#include "push_swap.h"

void    ft_sa(t_stack **a)
{
    t_stack *temp;

    if (*a == NULL || (*a)->next == NULL)
        return ;
    
    temp = *a;
    *a = (*a)->next;
    temp->next = (*a)->next;
    (*a)->next = temp;
    ft_set_index(a);
    ft_set_prev(a);
}

void    ft_sb(t_stack **b)
{
    ft_sa(b);
}

void    ft_ss(t_stack **a, t_stack **b)
{
    ft_sa(a);
    ft_sa(b);
}

