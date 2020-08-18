#include <stdio.h>
#include <malloc.h>
#include <memory.h>

typedef struct _S_Data {
  short a;
  short b;
  int c;
  char d[5];

} S_Data;

int main()
{
  S_Data *pdata = malloc(sizeof(S_Data));
  FILE *fp = fopen("q1.dat","rb");
  fread(pdata,sizeof(S_Data),1,fp);

  printf("%4x,%4x,%4x,%4x\n",pdata->a,pdata->b,pdata->c,pdata->a+pdata->b+pdata->c);

  for(int i=0;i<5;i++)
  {
    printf("%4d",pdata->d[i]);
  }
  
  fclose(fp);
  printf("\ndone!\n");

  return 0;
}