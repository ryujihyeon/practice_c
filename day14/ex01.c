#include <stdio.h>
#include <SDL2/SDL.h>
#include "../engine/button.h"

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;

SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;

S_BUTTON *g_pExitButton;

static SDL_bool bLoop = SDL_TRUE;

void callbackExitButtonPush(S_BUTTON *pBtn)
{
  bLoop = SDL_FALSE;
}


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
  g_pRenderer = SDL_CreateRenderer(g_pWindow,-1,SDL_RENDERER_ACCELERATED);
  g_pExitButton = createButton(WINDOW_WIDTH/2-60,WINDOW_HEIGHT/2-16,120,32,1,callbackExitButtonPush);

//game loop
  
  while (bLoop)
  {
    //rendering
    SDL_SetRenderDrawColor(g_pRenderer,0,0,0,0xff);
    SDL_RenderClear(g_pRenderer);

    Button_Render(g_pExitButton,g_pRenderer);

    SDL_RenderPresent(g_pRenderer);

    //event handling
    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      Button_DoEvent(g_pExitButton,&_event);
      switch (_event.type)
      {
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
  SDL_DestroyRenderer(g_pRenderer);
  SDL_DestroyWindow(g_pWindow);
  SDL_Quit();
  return 0;
}
