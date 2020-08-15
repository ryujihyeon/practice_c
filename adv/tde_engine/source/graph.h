#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "core.h"

typedef struct __tde_node__ {

    void *m_pNext;
    void *m_pPrev;
    void *m_pParent;
    void *m_pChild;
    void *m_pBody;

} tDE_S_Node;



#endif __GRAPH_H__