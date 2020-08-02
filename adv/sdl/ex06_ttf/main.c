#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Globally used font
TTF_Font *gFont = NULL;

int main(int argc, char *argv[])
{
    // retutns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
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
        return 0;
    }
    else 
    {

    }

    //Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return 0;
    }
    else 
    {
        printf("load font success \n");
    }

    //LOAD font file
    gFont = TTF_OpenFont("../res/nmf.ttf", 28);

    if (!gFont)
    {
        printf("font file load error");
        printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
        return 0;
    }

    SDL_Texture *mTexture;

    int text_height, text_width;

    {
        SDL_Color textColor = {0, 0, 0};
        Uint16 text[]={'H','e','l','l','o',' ','W','o','r','l','d','!',L'한' ,L'글'};

        SDL_Surface *textSurface = TTF_RenderUNICODE_Solid(gFont, text, textColor);
        mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        text_height = textSurface->h;
        text_width = textSurface->w;

        SDL_FreeSurface(textSurface);
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

        //Set rendering space and render to screen
        SDL_Rect renderQuad = {100, 100, text_width, text_height};

        //Render to screen
        SDL_RenderCopy(gRenderer, mTexture, NULL, &renderQuad);
        // SDL_RenderCopyEx( gRenderer, mTexture, NULL,renderQuad , 0.0, NULL, flip );

        SDL_RenderPresent(gRenderer);

        // calculates to 60 fps
        SDL_Delay(1000 / 60);
    }

    //Free global font
    TTF_CloseFont(gFont);
    gFont = NULL;

    SDL_DestroyTexture(mTexture);
    // destroy renderer
    SDL_DestroyRenderer(gRenderer);

    // destroy window
    SDL_DestroyWindow(gWindow);
    return 0;
}