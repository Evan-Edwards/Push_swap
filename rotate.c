#include "push_swap.h"

void    ft_ra(t_stack **a)
{
    t_stack *new_last;
    t_stack *i;

    if (*a == NULL || (*a)->next == NULL)
        return ;
    new_last = *a;
    *a = (*a)->next;
    i = *a;
    while (i->next != NULL)
        i = i->next;
    i->next = new_last;
    new_last->next = NULL;
    ft_set_index(a);
    ft_set_prev(a);
}

void ft_rb(t_stack **b)
{
    ft_ra(b);
}

void ft_rr(t_stack **a, t_stack **b)
{
    ft_ra(a);
    ft_ra(b);
}