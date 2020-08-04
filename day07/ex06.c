#include <stdio.h>
#include <SDL2/SDL.h>
//함수가 몇번 호출 되는지 카운팅...
int counter()
{
  static int counter=10; //초기값 
  return ++counter;
}

int main(int argc,char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    printf("error initializing SDL: %s\n", SDL_GetError());
    return 1;
  }

  printf("%d \n",counter());
  printf("%d \n",counter());
  printf("%d \n",counter());

  SDL_Quit();
  return 0;
}
