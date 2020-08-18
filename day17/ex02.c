#include "../engine/core.h"

tDE_S_SheetData g_sheetDataAssets[1024];
int g_select_SheetIndex = 0;

int main(int argc, char *argv[])
{
  tDE_S_Core *pEngineCore = tDE_setup_1("example2", 640, 480, 0);

  SDL_bool bLoop = SDL_TRUE;

  {
    int nCount = 0;
    static char szBuf[256];
    FILE *fp = fopen("../res/tanks/sheet_tanks.xml", "rt");
    while (fgets(szBuf, sizeof(szBuf), fp))
    {
      tDE_S_SheetData _tmp;
      if (tDE_util_parseSheet(szBuf, &_tmp))
      {
        g_sheetDataAssets[nCount++] = _tmp;
        // printf("%32s%4d%4d%4d%4d\n", data.szName, data.x, data.y, data.w, data.h);
      }
    }

    fclose(fp);
  }

  SDL_Texture *pTanksTex = tDE_util_loadTexture(pEngineCore, "../res/tanks/sheet_tanks.png");

  while (bLoop)
  {

    SDL_SetRenderDrawColor(pEngineCore->m_pRender, 0, 0, 0, 0xff);
    SDL_RenderClear(pEngineCore->m_pRender);

    {
      Uint16 sheet_index = g_select_SheetIndex;
      SDL_Rect _destRt = {320, 240,
                          g_sheetDataAssets[sheet_index].m_area.w,
                          g_sheetDataAssets[sheet_index].m_area.h};
      SDL_RenderCopy(pEngineCore->m_pRender, pTanksTex,
                     &g_sheetDataAssets[sheet_index].m_area, &_destRt);
    }

    {
      SDL_Color _whiteColor = {0xff, 0xff, 0xff, 0xff};

      //g_sheetDataAssets[g_select_SheetIndex].szName
      tDE_S_SheetData *pSheet = &g_sheetDataAssets[g_select_SheetIndex];
      char szInfo[256];
      sprintf(szInfo, "%s,%4d%4d%4d%4d",
              pSheet->szName,
              pSheet->m_area.x,
              pSheet->m_area.y,
              pSheet->m_area.w,
              pSheet->m_area.h);

      SDL_Surface *textSurface = TTF_RenderText_Solid(pEngineCore->m_pDefaultFont,
                                                      szInfo,
                                                      _whiteColor);
      SDL_Texture *pTex = SDL_CreateTextureFromSurface(pEngineCore->m_pRender, textSurface);

      SDL_Rect _dstRect = {0, 0, textSurface->w, textSurface->h};

      SDL_RenderCopy(pEngineCore->m_pRender, pTex, NULL, &_dstRect);

      SDL_FreeSurface(textSurface);
      SDL_DestroyTexture(pTex);
    }

    SDL_RenderPresent(pEngineCore->m_pRender);

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_KEYDOWN:
        printf("%4d\r", event.key.keysym.scancode);
        if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
        {
          if (g_select_SheetIndex > 0)
          {
            g_select_SheetIndex--;
          }
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
        {
          g_select_SheetIndex++;
        }
        break;
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      }
    }
  }

  SDL_DestroyTexture(pTanksTex);

  tDE_closeCore(pEngineCore);
  return 0;
}