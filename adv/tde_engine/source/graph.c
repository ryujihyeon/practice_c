#include "graph.h"

tDE_S_Node *g_pRootNode;

void tDE_graph_init()
{
    g_pRootNode = SDL_malloc(sizeof(tDE_S_Node));
}

void tDE_graph_close()
{
    SDL_free(g_pRootNode);
}

void tDE__graph_add_node(tDE_S_Node *pNode,tDE_S_Node *pParent)
{
    

}