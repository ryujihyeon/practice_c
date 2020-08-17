#include "../engine/core.h"
#include "../engine/graph.h"
#include "../engine/entity/sprite.h"

SDL_Rect g_sheet_rects[] = {
    {730, 340, 75, 70},
    {671, 0, 75, 70},
    {671, 70, 75, 70}};

int main(int argc, char *argv[])
{
  tDE_S_Core *pEngineCore = tDE_setup_1("example2", 640, 480, 0);
  SDL_Texture *pSprTex = tDE_util_loadTexture(pEngineCore, "../res/tanks/sheet_tanks.png");

  tDE_S_ObjectBase *pSpr = tDE_Entity_createSprite(0, 0, 0, g_sheet_rects[0], pSprTex,
                                                   NULL, NULL, NULL);

  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    SDL_SetRenderDrawColor(pEngineCore->m_pRender,0,0,0,0xff);
    SDL_RenderClear(pEngineCore->m_pRender);

    pSpr->m_fpRender(pSpr,pEngineCore->m_pRender);

    SDL_RenderPresent(pEngineCore->m_pRender);

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      }
    }
  }

  SDL_DestroyTexture(pSprTex);

  tDE_closeCore(pEngineCore);

  return 0;
}