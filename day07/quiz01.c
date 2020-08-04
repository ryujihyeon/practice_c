#include <stdio.h>
#include <SDL2/SDL.h>

void _copyStr(int nStartIndex,int nEndIndex,char src[],char dest[])
{

}

char data[] = "kor,mat,eng,bio,phy,earth";
char buf1[16];
char buf2[16];
char buf3[16];
char buf4[16];
char buf5[16];
char buf6[16];

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Quit();
  return 0;
}


