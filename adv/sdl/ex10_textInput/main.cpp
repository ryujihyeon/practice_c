#include <stdio.h>
#include <SDL2/SDL.h>
#include <string.h>


const Uint16 WINDOW_WIDTH = 640;
const Uint16 WINDOW_HEIGHT = 480;
SDL_Window *g_pWindow;

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    g_pWindow = SDL_CreateWindow("GAME", // creates a window
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (!g_pWindow)
    {
        printf("error initializing SDL window: %s\n", SDL_GetError());
        return 1;
    }


    char strbuf[256]={ 0, };

    SDL_bool bLoop = SDL_TRUE;
    while (bLoop)
    {
        SDL_Event _event;
        while (SDL_PollEvent(&_event))
        {
            switch (_event.type)
            {
            case SDL_KEYDOWN:
                printf("[%4d,%4d]\n",
                    _event.key.keysym.scancode, //key scan code
                    _event.key.keysym.sym //ascii code
                );
                {
                    if (_event.key.keysym.sym == SDLK_RETURN)
                    {
                        if (!strlen(strbuf)) {
                            //Enable text input
                            SDL_StartTextInput();
                            puts("ready to input text ");
                        }
                        else {
                            puts(strbuf);

                            if (!strcmp(strbuf, "exit"))
                            {
                                bLoop = SDL_FALSE;
                            }

                            strbuf[0] = 0x00;
                            //Disable text input
                            SDL_StopTextInput();

                        }
                    }
                }
                break;
            case SDL_TEXTINPUT:
            {
                if (!(SDL_GetModState() & KMOD_CTRL && (_event.text.text[0] == 'c' || _event.text.text[0] == 'C' || _event.text.text[0] == 'v' || _event.text.text[0] == 'V')))
                {
                    //Append character
                    strcat(strbuf, _event.text.text);
                }

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

    SDL_DestroyWindow(g_pWindow);
    SDL_Quit();
    return 0;
}
