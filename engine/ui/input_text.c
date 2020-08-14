#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "ui_base.h"
#include "input_text.h"

static void _destory(void *_pObj)
{
  S_INPUT_TEXT *pObj = _pObj;

  if(pObj->m_pTextTxture )
  {
    SDL_DestroyTexture(pObj->m_pTextTxture);
  }

  SDL_free(pObj);
}
static void _render(void *_pObj,SDL_Renderer *pRender)
{
  //...

}

static void _doEvent(void *_pObj,SDL_Event *evt)
{

}

 S_INPUT_TEXT *myui_createInputText(SDL_Renderer *pRenderer,
                         int x, int y,int w,int h,
                         Uint16 nID,
                         TTF_Font *pFont,
                         SDL_Color fgColor,
                         SDL_Color bgColor
                         )
{
  S_INPUT_TEXT *pObj = SDL_malloc(sizeof(S_INPUT_TEXT));

  pObj->m_base.m_nType = MYUI_TEXT_INPUT;
  pObj->m_base.m_nID = nID;

  pObj->m_Rect.x = x;
  pObj->m_Rect.y = y;  
  pObj->m_Rect.w = w;
  pObj->m_Rect.h = h;

  pObj->m_pFont = pFont;
  pObj->m_pTextTxture = NULL;

  pObj->m_fgColor = fgColor;
  pObj->m_bgColor = bgColor;

  pObj->m_base.m_fpRender = _render;
  pObj->m_base.m_fpDestory = _destory;
  pObj->m_base.m_fpDoEvent = _doEvent;

  return pObj;
}
