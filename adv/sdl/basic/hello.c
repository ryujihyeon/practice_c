#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

//The window we'll be rendering to
SDL_Window *g_pWindow = NULL;

//The window renderer
SDL_Renderer *g_pRenderer = NULL;

//The Texture
SDL_Texture *g_pTexture = NULL;

int main(int argc, char *argv[])
{
  // retutns zero on success else non-zero
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
  }
  SDL_Window *g_pWindow = SDL_CreateWindow("GAME", // creates a window
                                         SDL_WINDOWPOS_CENTERED,
                                         SDL_WINDOWPOS_CENTERED,
                                         WINDOW_WIDTH, WINDOW_HEIGHT, 0);

  // triggers the program that controls
  // your graphics hardware and sets flags
  Uint32 render_flags = SDL_RENDERER_ACCELERATED;

  // creates a renderer to render our images
  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, render_flags);

  //Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
  {
    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    return 0;
  }

  //load image
  {
    // creates a surface to load an image into the main memory
    SDL_Surface *surface;

    // please provide a path for your image
    surface = IMG_Load("../res/grasstiles.png");

    if (!surface)
    {
      printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
      return 0;
    }

    // loads image to our graphics hardware memory.
    SDL_Texture *tex = SDL_CreateTextureFromSurface(g_pRenderer, surface);

    // clears main-memory
    SDL_FreeSurface(surface);

    SDL_Rect dest;
    // connects our texture with dest to control position
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h);

    printf("orignal size %d,%d \n", dest.w, dest.h);
    g_pTexture = tex;
  }

  // controls annimation loop
  SDL_bool bLoop = SDL_TRUE;

  // annimation loop
  while (bLoop)
  {
    // Events mangement
    {
      SDL_Event event;
      while (SDL_PollEvent(&event))
      {
        switch (event.type)
        {
        case SDL_QUIT:
          // handling of close button
          printf("now quit app \n");
          bLoop = SDL_FALSE;
          break;
        case SDL_KEYDOWN:
          printf("key down %d \n", event.key.keysym.scancode);

          //esc 키 누름
          if (event.key.keysym.scancode == 41)
          {
            bLoop = SDL_FALSE;
          }
          break;
        }
      }
    }

    //rendering process
    {
      //Clear screen
      SDL_SetRenderDrawColor(g_pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
      SDL_RenderClear(g_pRenderer);

      //이미지 출력
      SDL_Rect dest;
      // connects our texture with dest to control position
      SDL_QueryTexture(g_pTexture, NULL, NULL, &dest.w, &dest.h);
      dest.x = 320;
      dest.y = 200;
      SDL_RenderCopy(g_pRenderer, g_pTexture, NULL, &dest);

      SDL_RenderPresent(g_pRenderer);
    }
  }

  //clear objects
  SDL_DestroyTexture(g_pTexture);
  // destroy renderer
  SDL_DestroyRenderer(g_pRenderer);
  // destroy window
  SDL_DestroyWindow(g_pWindow);

  return 0;
}