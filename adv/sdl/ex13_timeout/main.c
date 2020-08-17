#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

//The window we'll be rendering to
SDL_Window *g_pWindow = NULL;

//The window renderer
SDL_Renderer *g_pRenderer = NULL;

//Globally used font
TTF_Font *gFont = NULL;


Uint32 callback( Uint32 interval, void* param )
{

    printf("param :%s interval : %8d\n",(const char *)param,interval);

    return interval;
}



Uint32 callback_oneTime( Uint32 interval, void* param )
{

    printf("callback after %d\n",interval);

    return 0;
}


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
                // printf("key down %d \n", event.key.keysym.scancode);

                //esc 키 누름
                if (event.key.keysym.scancode == 41)
                {
                    close = 1;
                }
                else if(event.key.keysym.sym == SDLK_1)
                {
                    // Uint32 _tick=SDL_GetTicks();
                    // // _tick = SDL_GetTicks();
                    char *pMsg = "hello timer";
                    SDL_AddTimer(1000,callback,pMsg);
                    printf("start interval \n");
                }
                else if(event.key.keysym.sym == SDLK_2)
                {
                    Uint32 _tick=SDL_GetTicks();
                    SDL_AddTimer(1000,callback_oneTime,&_tick);
                    printf("call one time \n");
                    // SDL_Event _evt;
                    // _evt.type = SDL_QUIT;
                    // SDL_PushEvent(&_evt);
                }
                break;
            }
        }
        

        // calculates to 60 fps
        // SDL_Delay(1000 / 60);
    }

   
    // destroy renderer
    SDL_DestroyRenderer(g_pRenderer);

    // destroy window
    SDL_DestroyWindow(g_pWindow);
    return 0;
}