#include "../engine/core.h"
#include "../engine/tile.h"

tDE_S_Core *g_pEngineCore;
SDL_Texture *g_pTileSet;
Sint16 g_worldMap_Layer_1[64];
Uint16 g_nSelectTileIndex = 0;

int main(int argc, char *argv[])
{
  for (int i = 0; i < 64; i++)
  {
    g_worldMap_Layer_1[i] = -1;
  }  
  g_pEngineCore = tDE_setup_1("maptool",640,480,0);
  g_pTileSet = tDE_util_loadTexture(g_pEngineCore,"../res/dungeon.png");

  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    SDL_Renderer *pRender = g_pEngineCore->m_pRender; 
    SDL_SetRenderDrawColor(pRender, 0, 0, 0, 1);
    SDL_RenderClear(pRender);

    //select tile
    putTile(pRender, g_pTileSet, 15, 0, g_nSelectTileIndex,16,5,2);

    //440,100
    {
      //팔래트 랜디링
      SDL_Rect _dstRt = {440, 100, 80 * 4, 80 * 4};
      SDL_RenderCopy(pRender, g_pTileSet, NULL, &_dstRt);
    }

    //render world map
    {
      for (int i = 0; i < 64; i++)
      {
        Sint16 _index = g_worldMap_Layer_1[i];
        if (_index != -1)
        {
          putTile(pRender, g_pTileSet, i % 8, i / 8, _index,16,5,2);
        }
      }
    }

    SDL_RenderPresent(pRender);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      switch (_event.type)
      {
      case SDL_MOUSEMOTION:
      {
        printf("%4d%4d\r", _event.motion.x, _event.motion.y);
      }
      break;
      case SDL_MOUSEBUTTONDOWN:
      {
        printf("%8d\r", _event.button.button);
        if (_event.button.button == 1) //마우스 좌클릭
        {
          //팔래트처리
          {
            int _x = (_event.motion.x - 440) / 32;
            int _y = (_event.motion.y - 100) / 32;

            if ((_x >= 0 && _y >= 0) && (_x < 5 && _y < 5))
            {
              g_nSelectTileIndex = _y * 5 + _x;
            }

            // printf("%4d%4d\r", _x, _y);
          }
          //월드멥처리
          {
            int _x = (_event.motion.x) / 32;
            int _y = (_event.motion.y) / 32;

            if (_x < 8 && _y < 8)
            {
              int _tileIndex = _y * 8 + _x;
              // printf("%8d \r",_tileIndex);
              g_worldMap_Layer_1[_tileIndex] = g_nSelectTileIndex;
              printf("%4d%4d%4d\r", _x, _y, _tileIndex);
            }
          }
        }
        else if (_event.button.button == 3) //마우스 우클릭 
        {
          {
            int _x = (_event.motion.x) / 32;
            int _y = (_event.motion.y) / 32;

            if (_x < 8 && _y < 8)
            {
              int _tileIndex = _y * 8 + _x;
              g_worldMap_Layer_1[_tileIndex] = -1;              
            }
          }
        }
      }
      break;
      case SDL_KEYDOWN:
        printf("%d \n", _event.key.keysym.scancode);
        break;
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      default:
        break;
      }
    }
  }

  SDL_DestroyTexture(g_pTileSet);

  tDE_closeCore(g_pEngineCore);
  
  SDL_Quit();
  return 0;
}
