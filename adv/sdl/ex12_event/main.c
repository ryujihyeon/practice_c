#include <SDL2/SDL.h>
#include <stdio.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;
SDL_bool g_bLoop = SDL_TRUE;

int main(int argc, char *argv[])
{
  // retutns zero on success else non-zero
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
  }
  SDL_Window *g_pWindow = SDL_CreateWindow("GAME", // creates a window
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  // creates a renderer to render our images
  SDL_Renderer *g_pRenderer = SDL_CreateRenderer(g_pWindow, -1,
                                                 SDL_RENDERER_ACCELERATED // your graphics hardware and sets flags
  );

  while (g_bLoop)
  {
    SDL_Event event;

    // Events mangement
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        // handling of close button
        printf("now quit app \n");
        g_bLoop = SDL_FALSE;
        break;
      case SDL_KEYDOWN:
        printf("key down %d \n", event.key.keysym.scancode);
        if (event.key.keysym.sym == SDLK_1)
        {
          SDL_Event _evt;
          _evt.type = SDL_USEREVENT + 1;
          _evt.user.code = 77;
          SDL_PushEvent(&_evt); //이밴트 발생 시키기 
        }
        else if(event.key.keysym.sym == SDLK_q)
        {
          SDL_Event _evt;
          _evt.type = SDL_QUIT;
          SDL_PushEvent(&_evt);
        }
        break;
      case SDL_USEREVENT + 1:
      {
        printf("raise user event %d \n",event.user.code);
      }
      break;
      }
    }
    // clears the screen
    SDL_SetRenderDrawColor(g_pRenderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(g_pRenderer);

    // triggers the double buffers
    // for multiple rendering
    SDL_RenderPresent(g_pRenderer);
  }
  // destroy renderer
  SDL_DestroyRenderer(g_pRenderer);

  // destroy window
  SDL_DestroyWindow(g_pWindow);
  return 0;
}