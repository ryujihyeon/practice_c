#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>

int doTokenize(char *szBuf, char szBufToken[][32]);

const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;
SDL_Window *gWindow;
SDL_Renderer *g_pRenderer;
SDL_Texture *g_pTitleTexture;


int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  gWindow = SDL_CreateWindow("GAME", // creates a window
                             SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED,
                             WINDOW_WIDTH, WINDOW_HEIGHT, 0);
  if (!gWindow)
  {
    printf("error initializing SDL window: %s\n", SDL_GetError());
    return 1;
  }
  // creates a renderer to render our images
  g_pRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

  {
    // creates a surface to load an image into the main memory
    SDL_Surface *surface;

    // please provide a path for your image
    surface = IMG_Load("../res/dungeontiles.png");

    // loads image to our graphics hardware memory.
    SDL_Texture *tex = SDL_CreateTextureFromSurface(g_pRenderer, surface);

    // clears main-memory
    SDL_FreeSurface(surface);
    g_pTitleTexture = tex;
  }

  static char strBuf[32] = {
      0,
  };

  int nTileIndex = 0;

  SDL_bool bLoop = SDL_TRUE;
  int nInputFSM = 0; //0 -> ready , 1-> text input
  while (bLoop)
  {

    // clears the screen
    SDL_SetRenderDrawColor(g_pRenderer,0x00,0x00,0x00,0x00);
    SDL_RenderClear(g_pRenderer);
    
    {
      Uint16 _index = nTileIndex;
      SDL_Texture *tex = g_pTitleTexture;
      SDL_Rect _tmpDstRt;
      _tmpDstRt.x = 0;
      _tmpDstRt.y = 0;
      _tmpDstRt.w = 32;
      _tmpDstRt.h = 32;
      SDL_Rect _tmpSrcRt;
      _tmpSrcRt.x = (_index % 6) * 8;
      _tmpSrcRt.y = (_index / 6) * 8;
      _tmpSrcRt.w = 8;
      _tmpSrcRt.h = 8;

      SDL_RenderCopy(g_pRenderer, tex, &_tmpSrcRt, &_tmpDstRt);
    }
    // for multiple rendering
    SDL_RenderPresent(g_pRenderer);

    SDL_Event _event;
    while (SDL_PollEvent(&_event))
    {
      switch (_event.type)
      {
      case SDL_KEYDOWN:
        //printf("%4d %4d \n", _event.key.keysym.scancode,_event.key.keysym.sym);
        if (_event.key.keysym.sym == SDLK_RETURN)
        {
          if (nInputFSM == 0)
          {
            printf("input msg : ");
            SDL_StartTextInput();
            nInputFSM = 1;
          }
          else if (nInputFSM == 1)
          {
            static char szTokens[8][32];
            int _numToken = doTokenize(strBuf,szTokens);

            if (strcmp(szTokens[0], "quit") == 0)
            {
              bLoop = SDL_FALSE;
            }
            else if (strcmp(szTokens[0], "change") == 0)
            {

              printf("\n %d %s %s \n",_numToken,szTokens[0],szTokens[1]);

              //nTileIndex++;
            }
            printf("\n%s\n", strBuf);
            strBuf[0] = 0x00;
            SDL_StopTextInput();
            nInputFSM = 0;
          }
        }
        break;
      case SDL_TEXTINPUT:
      {
        strcat(strBuf, _event.text.text);
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

  SDL_DestroyTexture(g_pTitleTexture);
  SDL_DestroyRenderer(g_pRenderer);

  SDL_DestroyWindow(gWindow);
  SDL_Quit();
  return 0;
}
