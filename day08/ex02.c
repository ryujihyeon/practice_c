#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  for(int i=0; i<4;i++)
  {
    for(int j=0;j<(i+1);j++)
    {
      printf("*");
    }
    printf("\n");
  }

  char _tt[5][5] = {
    {' ',' ','*',' ',' '},
    {' ','*','*','*',' '},
    {'*','*','*','*','*'},
    {' ','*','*','*',' '},
    {' ',' ','*',' ',' '}
  };

  for(int iy=0;iy<5;iy++)
  {
    for(int ix=0;ix<5;ix++)
    {
      printf("%c",_tt[iy][ix]);
    }
    printf("\n");
  }



  SDL_Quit();
  return 0;
}


