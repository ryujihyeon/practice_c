#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;

        if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) == 0)
        {
            SDL_bool done = SDL_FALSE;

            SDL_Texture *ptxSpr;

            {
                // SDL_RenderPresent(renderer);
                SDL_Surface *surface;
                // please provide a path for your image
                surface = IMG_Load("../../res/tiny16/characters.png");

                if(surface == 0) {
                    printf("error load file \n");
                }
                else {
                    printf("success load file \n");
                }
                

                // loads image to our graphics hardware memory.
                SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surface);

                // clears main-memory
                SDL_FreeSurface(surface);
                ptxSpr = tex;
            }

            while (!done)
            {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE); //green

                for (int i = 0; i < WINDOW_WIDTH / 20; i++)
                {
                    int _stepX = i * (WINDOW_WIDTH / 20);
                    SDL_RenderDrawLine(renderer, _stepX, 0, _stepX, WINDOW_HEIGHT);
                }

                for (int i = 0; i < WINDOW_HEIGHT / 20; i++)
                {
                    int _stepY = i * (WINDOW_HEIGHT / 20);
                    SDL_RenderDrawLine(renderer, 0, _stepY, WINDOW_WIDTH, _stepY);
                }

                {
                    SDL_Rect srcRt,dstRt;
                    dstRt.x = 128;
                    dstRt.y = 200;
                    dstRt.w = 64;
                    dstRt.h = 64;

                    srcRt.x = 16;
                    srcRt.y = 0;
                    srcRt.w = 16;
                    srcRt.h = 16;

                    SDL_RenderCopy(renderer,ptxSpr,&srcRt,&dstRt);

                }

                {
                    SDL_Rect srcRt,dstRt;
                    dstRt.x = 128 + 64;
                    dstRt.y = 200;
                    dstRt.w = 64;
                    dstRt.h = 64;

                    srcRt.x = 16*4;
                    srcRt.y = 0;
                    srcRt.w = 16;
                    srcRt.h = 16;

                    SDL_RenderCopy(renderer,ptxSpr,&srcRt,&dstRt);

                }

                {
                    SDL_Rect srcRt,dstRt;
                    dstRt.x = 128 + (64*2);
                    dstRt.y = 200;
                    dstRt.w = 64;
                    dstRt.h = 64;

                    srcRt.x = 16*7;
                    srcRt.y = 0;
                    srcRt.w = 16;
                    srcRt.h = 16;

                    SDL_RenderCopy(renderer,ptxSpr,&srcRt,&dstRt);

                }

                {
                    SDL_Rect srcRt,dstRt;
                    dstRt.x = 128 + (64*3);
                    dstRt.y = 200;
                    dstRt.w = 64;
                    dstRt.h = 64;

                    srcRt.x = 16*10;
                    srcRt.y = 0;
                    srcRt.w = 16;
                    srcRt.h = 16;

                    SDL_RenderCopy(renderer,ptxSpr,&srcRt,&dstRt);

                }
                



                SDL_RenderPresent(renderer);
                // SDL_Delay(500);

                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        done = SDL_TRUE;
                    }
                }
            }
        }

        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
        }
        if (window)
        {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}