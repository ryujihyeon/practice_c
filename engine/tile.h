#ifndef __TILE_H
#define __TILE_H
// void putTile(SDL_Renderer *pRenderer, SDL_Texture *pTex,Uint16 _x,Uint16 _y, Uint16 _index);
void putTile(SDL_Renderer *pRenderer, SDL_Texture *pTex,
Uint16 _x,Uint16 _y, Uint16 _index,
Uint16 tile_size,
Uint16 tile_set_width,
Uint16 zoom
);
#endif