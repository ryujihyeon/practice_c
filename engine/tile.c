
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void putTile(SDL_Renderer *pRenderer, SDL_Texture *pTex,
Uint16 _x,Uint16 _y, Uint16 _index,
Uint16 tile_size,
Uint16 tile_set_width,
Uint16 zoom
)
{
  SDL_Rect _tmpDstRt;
  _tmpDstRt.x = _x * (tile_size*zoom);
  _tmpDstRt.y = _y * (tile_size*zoom);
  _tmpDstRt.w = (tile_size*zoom);
  _tmpDstRt.h = (tile_size*zoom);

  SDL_Rect _tmpSrcRt;
  _tmpSrcRt.x = (_index % tile_set_width) * tile_size;
  _tmpSrcRt.y = (_index / tile_set_width) * tile_size;
  _tmpSrcRt.w = tile_size;
  _tmpSrcRt.h = tile_size;

  SDL_RenderCopy(pRenderer, pTex, &_tmpSrcRt, &_tmpDstRt);
}