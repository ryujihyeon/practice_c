#include <stdio.h>
#include <SDL2/SDL.h>
#include "../engine/util.h"

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;
SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  g_pWindow = SDL_CreateWindow("GAME", // creates a window
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);

  if (!g_pWindow)
  {
    printf("error initializing SDL window: %s\n", SDL_GetError());
    return 1;
  }

  SDL_bool bLoop = SDL_TRUE;
  SDL_bool bCheckHitRect = SDL_FALSE;

  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
    SDL_RenderClear(g_pRenderer);

//사각형 그리기 
    SDL_Rect testRect = {100, 100, 120, 120};
    if (!bCheckHitRect)
    {
      
      SDL_SetRenderDrawColor(g_pRenderer, 255, 255, 255, 255);
      SDL_RenderDrawRect(g_pRenderer, &testRect);
    }
    else 
    {      
      SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
      SDL_RenderFillRect(g_pRenderer, &testRect);
    }

    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      switch (_event.type)
      {
      case SDL_MOUSEBUTTONDOWN:
      {
        int _mx = _event.motion.x;
        int _my = _event.motion.y;

      }
        break;
      case SDL_MOUSEMOTION:
      {
        bCheckHitRect = checkPointInRect(&testRect,_event.motion.x,_event.motion.y);        

        // int _mx = _event.motion.x;
        // int _my = _event.motion.y;       

        // if ((testRect.x < _mx && testRect.y < _my) &&
        //     ((testRect.x + testRect.w) > _mx && (testRect.y + testRect.h) > _my))
        // {
        //   printf("%4d%4d%2d\r", _event.motion.x, _event.motion.y, 1);
        //   bCheckHitRect = SDL_TRUE;
        // }
        // else
        // {
        //   printf("%4d%4d%2d\r", _event.motion.x, _event.motion.y, 0);
        //   bCheckHitRect = SDL_FALSE;
        // }
      }
      break;
      case SDL_KEYDOWN:
        // printf("%d \n", _event.key.keysym.scancode);
        break;
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;
      default:
        break;
      }
    }
  }

  SDL_DestroyRenderer(g_pRenderer);
  SDL_DestroyWindow(g_pWindow);
  SDL_Quit();
  return 0;
}
