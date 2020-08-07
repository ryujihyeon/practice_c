#include <stdio.h>
#include <SDL2/SDL.h>

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;
SDL_Window *g_pWindow;

SDL_Renderer *g_pRenderer = NULL;

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

  Uint32 render_flags = SDL_RENDERER_ACCELERATED;
  // creates a renderer to render our images
  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, render_flags);

  SDL_bool bLoop = SDL_TRUE;
  Sint32 _mouseX = 0;
  Sint32 _mouseY = 0;
  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(g_pRenderer);

    //render code here
    SDL_SetRenderDrawColor(g_pRenderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(g_pRenderer, _mouseX, 0, _mouseX, 480);
    SDL_RenderDrawLine(g_pRenderer, 0, _mouseY, 640, _mouseY);

    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      switch (_event.type)
      {
      case SDL_MOUSEMOTION:
        SDL_GetMouseState(&_mouseX, &_mouseY);
        //printf("mouse relative [%4d,%4d]\n", event.motion.xrel, event.motion.yrel);
        break;
      case SDL_MOUSEBUTTONDOWN:
        printf("mouse down at [%4d,%4d] %4d %4d\n",
               _event.motion.x, _event.motion.y,_event.button.button,
               _event.button.timestamp
               );
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

  SDL_DestroyWindow(g_pWindow);
  SDL_Quit();
  return 0;
}
