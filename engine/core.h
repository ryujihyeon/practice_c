#ifndef __CORE_H__
#define __CORE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

typedef struct _tde_s_base_ {
  
  Uint16 m_nType;
  SDL_bool m_bVisible;
  Uint32 m_nId;

  void (*m_fpDestory)(void *pObj);  
  void (*m_fpRender)(void *pObj, SDL_Renderer *pRender);
  void (*m_fpDoEvent)(void *pObj, SDL_Event *pEvt);
  void (*m_fpApply)(void *pObj,Uint32 tick);

} tDE_S_ObjectBase;


#endif