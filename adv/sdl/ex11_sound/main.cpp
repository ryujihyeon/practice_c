#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"
#include <stdio.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

//The window we'll be rendering to
SDL_Window *g_pWindow = NULL;

int main(int argc, char* args[])
{
    int result = 0;
    int flags = MIX_INIT_OGG;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Failed to init SDL\n");
        return 1;
    }
    g_pWindow = SDL_CreateWindow("GAME", // creates a window
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (flags != (result = Mix_Init(flags))) {
        printf("Could not initialize mixer (result: %d).\n", result);
        printf("Mix_Init: %s\n", Mix_GetError());
        return 1;
    }

    //Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        return 1;
    }

    Mix_Music *music = Mix_LoadMUS("../res/nj4_2.ogg");

    if (!music)
    {
        printf("Failed to load music SDL_mixer Error: %s\n", Mix_GetError());
    }
    //Load sound effects
    Mix_Chunk *gScratch = Mix_LoadWAV("../res/scratch.wav");
    if (gScratch == NULL)
    {
        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
    }

    Mix_Chunk *gHigh = Mix_LoadWAV("../res/high.wav");
    if (gHigh == NULL)
    {
        printf("Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        // success = false;
    }

    Mix_Chunk *gMedium = Mix_LoadWAV("../res/medium.wav");
    if (gMedium == NULL)
    {
        printf("Failed to load medium sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        // success = false;
    }

    Mix_Chunk *gLow = Mix_LoadWAV("../res/low.wav");
    if (gLow == NULL)
    {
        printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        // success = false;
    }


    // controls annimation loop
    SDL_bool bLoop = SDL_TRUE;

    // annimation loop
    while (bLoop)
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
            {
                printf("key down %d \n", event.key.keysym.scancode);
                if (event.key.keysym.scancode == 41)
                {
                    bLoop = SDL_FALSE;
                }
                else if (event.key.keysym.sym == SDLK_a)
                {
                    //Play the music
                    Mix_PlayMusic(music, -1);

                }
                else if (event.key.keysym.sym == SDLK_1)
                {
                    Mix_PlayChannel(-1, gScratch, 0);
                }
                else if (event.key.keysym.sym == SDLK_2)
                {
                    Mix_PlayChannel(-1, gLow, 0);
                }
                else if (event.key.keysym.sym == SDLK_3)
                {
                    Mix_PlayChannel(-1, gHigh, 0);
                }
                else if (event.key.keysym.sym == SDLK_4)
                {
                    Mix_PlayChannel(-1, gMedium, 0);
                }
            }
            break;
            }
        }
    }

    // Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    // Mix_Music *music = Mix_LoadMUS(MY_COOL_MP3);
    // Mix_PlayMusic(music, 1);

    // while (!SDL_QuitRequested()) {
    //     SDL_Delay(250);
    // }



    Mix_FreeMusic(music);
    SDL_DestroyWindow(g_pWindow);
    SDL_Quit();
    return 0;
}