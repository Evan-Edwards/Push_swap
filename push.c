#include "push_swap.h"

void ft_push(t_stack **a, t_stack **b)
{
    t_stack *temp;
    
    if (*a == NULL)
        return ;
    temp = *a;
    *a = (*a)->next;
    (*a)->prev = NULL;
    ft_set_indexes(a);
    temp->next = *b;
    temp->prev = NULL;
    *b = temp;
    ft_set_indexes(b);
}