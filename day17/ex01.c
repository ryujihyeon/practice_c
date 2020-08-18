#include <stdio.h>
#include <string.h>

int main()
{
  static char szBuf[256];

  FILE *fp = fopen("../res/tanks/sheet_tanks.xml","rt");

  // fgets(szBuf,sizeof(szBuf),fp);
  // char *szToken = strtok(szBuf," ");
  // printf("%s \n",szToken);
  // szToken = strtok(NULL," ");
  // printf("%s \n",szToken);

  while(fgets(szBuf,sizeof(szBuf),fp))
  {
    char *szToken = strtok(szBuf," ");
    if(!strcmp(szToken,"\t<SubTexture")) {

      static char _szBuf[5][256];
      //name
      szToken = strtok(NULL," ");      
      strcpy(_szBuf[0],szToken);      
//x
      szToken = strtok(NULL," ");
      strcpy(_szBuf[1],szToken);
//y
      szToken = strtok(NULL," ");
      strcpy(_szBuf[2],szToken);
//w
      szToken = strtok(NULL," ");
      strcpy(_szBuf[3],szToken);
//h
      szToken = strtok(NULL," ");
      strcpy(_szBuf[4],szToken);

//name 파싱 
      szToken = strtok(_szBuf[0],"=");
      szToken = strtok(NULL,"=");
      printf("%s\n",szToken);

    }
    //printf("%s\n",szToken);
    
  }

  fclose(fp);

}