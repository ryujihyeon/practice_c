#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        SDL_Window *window = NULL;
        SDL_Renderer *renderer = NULL;

        if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) == 0)
        {
            SDL_bool done = SDL_FALSE;

            int _mouseX, _mouseY;

            while (!done)
            {
                SDL_Event event;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);

                //render code here
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderDrawLine(renderer, _mouseX, 0, _mouseX, 480);
                SDL_RenderDrawLine(renderer, 0, _mouseY, 640, _mouseY);

                SDL_RenderPresent(renderer);

                while (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        done = SDL_TRUE;
                    }
                    else if (event.type == SDL_MOUSEMOTION)
                    {
                        
                        SDL_GetMouseState(&_mouseX, &_mouseY);

                        // printf("[%5d],[%5d] \r",x,y);
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