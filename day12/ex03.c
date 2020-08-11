#include <stdio.h>
#include <malloc.h>

typedef struct _node
{
  int number;
  struct _node *p_next;
} NODE;


int main()
{
  NODE *phead =NULL;

  phead = (NODE *)malloc(sizeof(NODE));
  phead->number = 12;
  phead->p_next = NULL;

//추가
  {
    NODE *p = phead;
    while (p->p_next != NULL)
    {
      p = p->p_next;
    }
    p->p_next = (NODE *)malloc(sizeof(NODE));    
    p = p->p_next;

    p->number = 13;    
    p->p_next = NULL;
  }

  {
    NODE *p = phead;
    while (p->p_next != NULL)
    {
      p = p->p_next;
    }
    p->p_next = (NODE *)malloc(sizeof(NODE));    
    p = p->p_next;

    p->number = 14;    
    p->p_next = NULL;
  }

  {
    NODE *p = phead;
    while (p->p_next != NULL)
    {
      p = p->p_next;
    }
    p->p_next = (NODE *)malloc(sizeof(NODE));    
    p = p->p_next;
    
    p->number = 15;    
    p->p_next = NULL;
  }

//순회 
  {
    NODE *p = phead;

    while (p != NULL)
    {
      printf("%d \n",p->number);
      p = p->p_next;
    }
  }

  return 0;
}