#include "sprite.h"

static void _destory(void *pObj)
{
}

static void _render(void *pObj, SDL_Renderer *pRender)
{
}

static void _doEvent(void *pObj, SDL_Event *pEvt)
{
}

tDE_S_ObjectBase *tDE_Entity_createSprite(int x, int y, Uint16 nID,
                                          SDL_Rect srcRect,
                                          SDL_Texture *pTexture,
                                          void (*m_callackMouseDown)(void *),
                                          void (*m_callackKeyDown)(void *),
                                          void (*m_callackJoystick)(void *))
{
}