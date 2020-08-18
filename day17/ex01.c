#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct __s_sheet_data
{
  char szName[32];
  int x;
  int y;
  int w;
  int h;
} _S_SheetData;

void parseSheet(const char *szStr,_S_SheetData *pData)
{

}

int main()
{
  static char szBuf[256];

  FILE *fp = fopen("../res/tanks/sheet_tanks.xml", "rt");

  // fgets(szBuf,sizeof(szBuf),fp);
  // char *szToken = strtok(szBuf," ");
  // printf("%s \n",szToken);
  // szToken = strtok(NULL," ");
  // printf("%s \n",szToken);

  while (fgets(szBuf, sizeof(szBuf), fp))
  {
    char *szToken = strtok(szBuf, " ");
    if (!strcmp(szToken, "\t<SubTexture"))
    {

      static char _szBuf[5][256];
      //name
      szToken = strtok(NULL, " ");
      strcpy(_szBuf[0], szToken);
      //x
      szToken = strtok(NULL, " ");
      strcpy(_szBuf[1], szToken);
      //y
      szToken = strtok(NULL, " ");
      strcpy(_szBuf[2], szToken);
      //w
      szToken = strtok(NULL, " ");
      strcpy(_szBuf[3], szToken);
      //h
      szToken = strtok(NULL, " ");
      strcpy(_szBuf[4], szToken);

      //name 파싱
      szToken = strtok(_szBuf[0], "=");
      szToken = strtok(NULL, ".");
      strcpy(_szBuf[0],szToken+1);
      printf("%s\n", _szBuf[0]);

      //x 파싱
      szToken = strtok(_szBuf[1], "\"");
      szToken = strtok(NULL, "\"");
      // strcpy(_szBuf[1],szToken+1);      
      printf("x:%d\n",atoi(szToken));

      //y 파싱
      szToken = strtok(_szBuf[2], "\"");
      szToken = strtok(NULL, "\"");
      // strcpy(_szBuf[1],szToken+1);      
      printf("y:%d\n",atoi(szToken));

      //w
      szToken = strtok(_szBuf[3], "\"");
      szToken = strtok(NULL, "\"");
      // strcpy(_szBuf[1],szToken+1);      
      printf("w:%d\n",atoi(szToken));

      //h
      szToken = strtok(_szBuf[4], "\"");
      szToken = strtok(NULL, "\"");
      // strcpy(_szBuf[1],szToken+1);      
      printf("h:%d\n",atoi(szToken));


      
      


    }
    //printf("%s\n",szToken);
  }

  fclose(fp);
}