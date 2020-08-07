#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Uint16 map_layer1[64] = {
  0,0,11,11,11,11,11,11,
  11,11,11,11,11,11,11,11,
  11,11,11,12,12,11,11,11,
  11,11,11,11,12,11,11,11,
  11,11,11,11,11,11,11,11,
  11,11,11,15,15,11,11,11,
  11,11,11,11,11,11,11,11,
  11,11,11,11,11,11,11,11
    };

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

SDL_Window *g_pWindow;
SDL_Renderer *g_pRenderer;
SDL_Texture *g_pTexture;

void _drawDot(int x, int y, Uint8 _r, Uint8 _g, Uint8 _b)
{
  SDL_Rect _dotInfo;
  _dotInfo.x = x * 16;
  _dotInfo.y = y * 16;
  _dotInfo.w = 16;
  _dotInfo.h = 16;
  SDL_SetRenderDrawColor(g_pRenderer, _r, _g, _b, SDL_ALPHA_OPAQUE);
  SDL_RenderFillRect(g_pRenderer, &_dotInfo);
}

void _drawTile(int x, int y, Uint16 _tileIndex)
{
  SDL_Rect _tmpDstRt;
  _tmpDstRt.x = x * 32;
  _tmpDstRt.y = y * 32;
  _tmpDstRt.w = 32;
  _tmpDstRt.h = 32;

  SDL_Rect _tmpSrcRt;
  _tmpSrcRt.x = (_tileIndex % 8) * 16;
  _tmpSrcRt.y = (_tileIndex / 8) * 16;
  _tmpSrcRt.w = 16;
  _tmpSrcRt.h = 16;

  SDL_RenderCopy(g_pRenderer, g_pTexture, &_tmpSrcRt, &_tmpDstRt);
}

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }
  //Initialize PNG loading
  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags))
  {
    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
    return 0;
  }

  g_pWindow = SDL_CreateWindow("GAME", // creates a window
                             SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED,
                             WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if(!g_pWindow)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  Uint32 render_flags = SDL_RENDERER_ACCELERATED;
  // creates a renderer to render our images
  g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, render_flags);
  if(!g_pRenderer)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  //이미지 로딩
  {
    // creates a surface to load an image into the main memory
    SDL_Surface *surface;

    // please provide a path for your image
    surface = IMG_Load("../res/tiny16/basictiles.png");
    if(!surface) {
      printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
      return 1;
    }

    // loads image to our graphics hardware memory.
    SDL_Texture *tex = SDL_CreateTextureFromSurface(g_pRenderer, surface);
    g_pTexture = tex;

    // clears main-memory
    SDL_FreeSurface(surface);
  }

  //게임루프
  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    //입력처리
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;

      default:
        break;
      }
    }
    //출력(rendering)
    SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(g_pRenderer);

    for (int iy = 0; iy < 8; iy++)
    {
      for (int ix = 0; ix < 8; ix++)
      {
        //Uint16 _dot = map_layer1[iy][ix];
        Uint16 _dot = map_layer1[iy * 8 + ix];
        int _x, _y;
        _x = ix + 0;
        _y = iy + 0;
        _drawTile(_x, _y, _dot);
      }
    }

    SDL_RenderPresent(g_pRenderer);
  }
  SDL_DestroyRenderer(g_pRenderer);
  SDL_DestroyWindow(g_pWindow);
  SDL_Quit();
  return 0;
}
