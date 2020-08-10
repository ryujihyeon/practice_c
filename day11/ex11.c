#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

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

  if (!g_pWindow)
  {
    printf("error initializing SDL window: %s\n", SDL_GetError());
    return 1;
  }

  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);

  SDL_bool bLoop = SDL_TRUE;

  SDL_Rect _rects[32];
  SDL_Color _rect_colors[32];

  Uint16 _rect_count = 0;
  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 1);
    SDL_RenderClear(g_pRenderer);

    for (int i = 0; i < _rect_count; i++)
    {
      SDL_SetRenderDrawColor(g_pRenderer, _rect_colors[i].r, _rect_colors[i].g, _rect_colors[i].b,
                             _rect_colors[i].a);
      // SDL_Rect _rt = {100, 100, 64, 64};
      SDL_RenderFillRect(g_pRenderer, &_rects[i]);
    }

    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      switch (_event.type)
      {
      case SDL_KEYDOWN:
        printf("%d \n", _event.key.keysym.scancode);
        if (_event.key.keysym.sym == SDLK_r)
        {
          SDL_Rect *pRect = &_rects[_rect_count];

          pRect->x = rand() % WINDOW_WIDTH;
          pRect->y = rand() % WINDOW_HEIGHT;
          pRect->w = rand() % 200;
          pRect->h = rand() % 200;

          SDL_Color *pColor = &_rect_colors[_rect_count];
          pColor->r = rand() % 255;
          pColor->g = rand() % 255;
          pColor->b = rand() % 255;
          pColor->a = rand() % 255;

          _rect_count++;
          if (_rect_count >= 32)
          {
            _rect_count = 0;
          }

          printf("add \n");
        }
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
