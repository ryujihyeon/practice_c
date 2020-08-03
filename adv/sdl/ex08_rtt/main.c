#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

//The window we'll be rendering to
SDL_Window *gWindow = NULL;

//The window renderer
SDL_Renderer *gRenderer = NULL;

int main(int argc, char *argv[])
{
    // retutns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window *gWindow = SDL_CreateWindow("GAME", // creates a window
                                           SDL_WINDOWPOS_CENTERED,
                                           SDL_WINDOWPOS_CENTERED,
                                           WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    // triggers the program that controls
    // your graphics hardware and sets flags
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    // creates a renderer to render our images
    gRenderer = SDL_CreateRenderer(gWindow, -1, render_flags);

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
    int _texH = 128, _texW = 128;
    SDL_Texture *mTexture = SDL_CreateTexture(gRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, _texW, _texH);
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
        // clears the screen
        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        //Make self render target
        SDL_SetRenderTarget(gRenderer, mTexture);
        //Clear screen
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(gRenderer);

        //Reset render target
        SDL_SetRenderTarget(gRenderer, NULL);
        //Set rendering space and render to screen
        SDL_Rect renderQuad = {0, 0, _texW, _texH};

        //Render to screen
        SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
        // SDL_RenderCopyEx( gRenderer, mTexture, NULL,renderQuad , 0.0, NULL, flip );

        SDL_RenderPresent(gRenderer);

        // calculates to 60 fps
        // SDL_Delay(1000 / 60);
    }

    SDL_DestroyTexture(mTexture);
    // destroy renderer
    SDL_DestroyRenderer(gRenderer);

    // destroy window
    SDL_DestroyWindow(gWindow);
    return 0;
}