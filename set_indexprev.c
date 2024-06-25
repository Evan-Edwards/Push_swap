#include "push_swap.h"

void    set_index(t_stack **a)
{
    int index;
    t_stack *i;

    index = 0;
    i = *a;
    while (i->next)
    {
        i->index = index;
        index++;
        i = i->next;
    }
}

void    set_prev(t_stack **a)
{
    t_stack *i;


    i = *a;
    i->prev = NULL;
    while (i->next)
    {
        i->next->prev = i;
        i = i->next;
    }
}