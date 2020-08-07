#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

//The window we'll be rendering to
SDL_Window *g_pWindow = NULL;

//The window renderer
SDL_Renderer *g_pRenderer = NULL;

int main(int argc, char *argv[])
{
  // retutns zero on success else non-zero
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
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
    return 1;
  }
  else
  {
  }

  //텍스춰 생성
  //Create uninitialized texture
  int _texH = 256, _texW = 256;
  SDL_Texture *mTexture = SDL_CreateTexture(g_pRenderer,
                                            SDL_GetWindowPixelFormat(g_pWindow),
                                            SDL_TEXTUREACCESS_STREAMING, _texW, _texH);
  if (mTexture == NULL)
  {
    printf("Unable to create blank texture! SDL Error: %s\n", SDL_GetError());
    return 1;
  }

  // controls annimation loop
  int close = 0;
  // annimation loop
  while (!close)
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
        close = 1;
        break;
      case SDL_KEYDOWN:
        printf("key down %d \n", event.key.keysym.scancode);

        //esc 키 누름
        if (event.key.keysym.scancode == 41)
        {
          close = 1;
        }
        break;
      }
    }

    //Clear screen
    SDL_SetRenderDrawColor(g_pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(g_pRenderer);

    {
      void *mPixels;
      int mPitch;
      if (SDL_LockTexture(mTexture, NULL, &mPixels, &mPitch) != 0)
      {
        printf("Unable to lock texture! %s\n", SDL_GetError());
        return 1;
        // success = false;
      }

      // printf("surface pitch sizt %d \n", mPitch);

      Uint32 format = SDL_GetWindowPixelFormat(g_pWindow);
      SDL_PixelFormat *mappingFormat = SDL_AllocFormat(format);

      Uint32 _redColor = SDL_MapRGBA(mappingFormat,
                                     rand() % 256, rand() % 256, rand() % 256, 0xFF);

      int _x = rand() % 256;
      int _y = rand() % 256;
      ((Uint32 *)mPixels)[_y * 256 + _x] = _redColor;

      SDL_UnlockTexture(mTexture);
      SDL_FreeFormat(mappingFormat);
      mPixels = NULL;
      mPitch = 0;
    }

    //Render texture to screen
    SDL_Rect renderQuad = {0, 0, _texW*4, _texH*4};
    SDL_RenderCopy(g_pRenderer, mTexture, NULL, &renderQuad);

    SDL_RenderPresent(g_pRenderer);

    // calculates to 60 fps
    // SDL_Delay(1000 / 60);
  }

  SDL_DestroyTexture(mTexture);
  // destroy renderer
  SDL_DestroyRenderer(g_pRenderer);

  // destroy window
  SDL_DestroyWindow(g_pWindow);
  return 0;
}