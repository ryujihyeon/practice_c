#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  char strBuf[32];

  FILE *fp = fopen("test4.txt", "rt");
  while (NULL != fgets(strBuf, sizeof(strBuf), fp))
  {
    char *pszTemp;

    char szName[32];
    int kor;
    int eng;
    int math;

    const char *pszDelimiter = ",";
    pszTemp = strtok(strBuf,pszDelimiter);
    // printf("%s \n",pszTemp);
    //name
    strcpy(szName,pszTemp);
//korea
    pszTemp = strtok(NULL,pszDelimiter);
    kor = atoi(pszTemp);
//english
    pszTemp = strtok(NULL,pszDelimiter);
    eng = atoi(pszTemp);
//math
    pszTemp = strtok(NULL,pszDelimiter);
    math = atoi(pszTemp);

    printf("%s %d %d %d \n",szName,kor,eng,math);

    //puts(strBuf);
  }

  fclose(fp);
}