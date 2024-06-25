#include "push_swap.h"

void ft_sa(t_stack **a)
{
    t_stack *temp;

    if (*a == NULL || (*a)->next == NULL)
        return ;
    
    temp = *a;
    *a = (*a)->next;
    (*a)->next = temp;
    (*a)->prev = NULL;
    (*a)->index = 0;
    temp->prev = *a;
    temp->index = 1;

    if ((*a)->next->next != NULL)
        (*a)->next->next->prev = (*a)->next;
}

void    ft_sb(t_stack **b)
{
    ft_sa(b);
}

