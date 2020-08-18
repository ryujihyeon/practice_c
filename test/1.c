#include <stdio.h>
#include <memory.h>
#include <string.h>

int main()
{
    char *szStr = "<hello";
    char szBuf[32];

    strcpy(szBuf,(szStr+1));

    printf("%s\n",szBuf);


    return 1;
}