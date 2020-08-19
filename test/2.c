#include <stdio.h>
#include <string.h>

struct s_sheet {
    char szName[8];
    short x;
    short y;
    short w;
    short h;
};

struct s_sheet sheets[3];

int main()
{
    sheets[0].x = 10;
    sheets[0].y = 10;
    sheets[0].w = 200;
    sheets[0].h = 300;
    strcpy(sheets[0].szName,"t45");

    sheets[1].x = 10;
    sheets[1].y = 10;
    sheets[1].w = 250;
    sheets[1].h = 800;
    strcpy(sheets[1].szName,"p-99");
    sheets[2].x = 10;
    sheets[2].y = 10;
    sheets[2].w = 200;
    sheets[2].h = 300;
    strcpy(sheets[2].szName,"m-1");

    FILE *fp = fopen("./sheet.dat","wb");
    fwrite(sheets,sizeof(sheets),1,fp);

    fclose(fp);

}