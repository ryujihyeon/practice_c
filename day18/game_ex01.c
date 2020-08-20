#include"../engine/core.h"
#include "../engine/tile.h"
#include"cmd_parser.h"

tDE_S_Core *g_pEngineCore;

Sint16 g_WorldMap[64];
Sint16 g_WorldMap_attr_layer[64] ={
    1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
};
Sint16 g_WorldMap_obj_layer[64]={0,};

SDL_Texture *g_pTileSet;
SDL_Texture *g_pTileSet2;
SDL_Point g_playerPos;



int main(int argc ,char **argv)
{
    g_playerPos.x =1;
    g_playerPos.y =1;
    
    g_pEngineCore = tDE_setup_1("game", 640, 480,0);
    g_pTileSet =tDE_util_loadTexture(g_pEngineCore, "../res/dungeon.png");
    g_pTileSet =tDE_util_loadTexture(g_pEngineCore, "../res/gb_ft_rpg_tile_set.png");

    //char *szCmd;
    //parseCmd("load l1.map");

    loadMap("./l1.map", &g_WorldMap);


    SDL_bool bLoop = SDL_TRUE; 
    
    while(bLoop)
    {
        SDL_SetRenderDrawColor(g_pEngineCore->m_pRender ,0x00,0x00,0xff,0xff);
        SDL_RenderClear(g_pEngineCore-> m_pRender);

        //월드맵 그리기
        drawWorld(g_pEngineCore->m_pRender,g_pTileSet,16,5,2,//타일셋 정보
                                                        0,0,//그려질 위치 
                                                        8, g_WorldMap);//월드맵 정보
         
         //오브젝트 레이어 재설정  
         {
             memset(g_WorldMap_obj_layer,0,64*sizeof(Uint16));
             g_WorldMap_obj_layer[g_playerPos.y*8 +g_playerPos.x] =1;
         } 

         {
            
            Sint16 *map = g_WorldMap_obj_layer;
            for(int i=0; i<64; i++)
            {
                Sint16 _index =map[i];
                if(_index !=-1)
                {
                    if(_index == 1)
                    {
                        //캐릭터 그리기
                        int x = i%8;
                        int y = i/8;
                        putTile(g_pEngineCore->m_pRender, g_pTileSet2, x, y, 190,16, 10, 2);
                    }
                }
            }
        }

        SDL_RenderPresent(g_pEngineCore-> m_pRender);
        
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
      // Button_DoEvent(pButton,&_event);
        switch (event.type)
        {
            case SDL_KEYUP:
            {
                if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
                {
                    g_playerPos.x--;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
                {
                    g_playerPos.x++;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_UP)
                {
                    g_playerPos.y--;
                }
                else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
                {
                    g_playerPos.y++;
                }
                Sint16 _attr = g_WorldMap_attr_layer[g_playerPos.x +(g_playerPos.y*8)];
                if(_attr !=0) //갈수없는곳
                {
                    g_playerPos = _oldPos;
                }
            }
                break;
            case SDL_QUIT:
                bLoop = SDL_FALSE;
                break;
            
            default:
                break;
            }
        }
    }
    SDL_DestroyTexture(g_pTileSet);
    tDE_closeCore(g_pEngineCore);

    return 0;

}
