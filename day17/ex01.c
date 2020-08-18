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

int parseSheet(char *szStr, _S_SheetData *pData)
{
  char *szToken = strtok(szStr, " ");
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
    strcpy(_szBuf[0], szToken + 1);
    //printf("%s\n", _szBuf[0]);
    strcpy(pData->szName,_szBuf[0]);

    //x 파싱
    szToken = strtok(_szBuf[1], "\"");
    szToken = strtok(NULL, "\"");
    // strcpy(_szBuf[1],szToken+1);
    // printf("x:%d\n", atoi(szToken));
    pData->x = atoi(szToken);

    //y 파싱
    szToken = strtok(_szBuf[2], "\"");
    szToken = strtok(NULL, "\"");
    // strcpy(_szBuf[1],szToken+1);
    // printf("y:%d\n", atoi(szToken));
    pData->y = atoi(szToken);

    //w
    szToken = strtok(_szBuf[3], "\"");
    szToken = strtok(NULL, "\"");
    // strcpy(_szBuf[1],szToken+1);
    // printf("w:%d\n", atoi(szToken));
    pData->w = atoi(szToken);

    //h
    szToken = strtok(_szBuf[4], "\"");
    szToken = strtok(NULL, "\"");
    // strcpy(_szBuf[1],szToken+1);
    // printf("h:%d\n", atoi(szToken));
    pData->h = atoi(szToken);
    return 1;
  }
  return 0;
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

  _S_SheetData data;

  while (fgets(szBuf, sizeof(szBuf), fp))
  {
    if(parseSheet(szBuf,&data))
    {
      printf("%32s%4d%4d%4d%4d\n",data.szName,data.x,data.y,data.w,data.h);

    }    
  }

  fclose(fp);
}