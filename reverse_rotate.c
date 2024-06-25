#include "push_swap.h"

void    ft_rra(t_stack **a)
{
    t_stack *temp;

    temp = ft_stacklast(*a);
    temp->prev->next = NULL;
    ft_stackadd_front(a, temp);
    ft_set_index(a);
    ft_set_prev(a);
}

void    ft_rrb(t_stack **b)
{
    ft_rra(b);
}

void    ft_rrr(t_stack **a, t_stack **b)
{
    ft_rra(a);
    ft_rrb(b);
}