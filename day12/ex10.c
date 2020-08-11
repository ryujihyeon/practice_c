#include <stdio.h>

int main()
{
  unsigned char data;

  FILE *fp;
  fp = fopen("test.bin","rb");  
  fseek(fp,2,SEEK_SET);
  fread(&data,sizeof(unsigned char),1,fp);
  printf("%d \n",data);

  fseek(fp,0,SEEK_SET);
  fread(&data,sizeof(unsigned char),1,fp);
  printf("%d \n",data);

  fclose(fp);

  printf("done! \n");
  
}