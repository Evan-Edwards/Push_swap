#include "push_swap.h"

void    ft_set_indexes(t_stack **a)
{
    long    i;
    t_stack *temp;

    i = 0;
    temp = *a;
    while (temp->next != NULL)
    {
        temp->index = i;
        temp = temp->next;
        i++;
    }
}