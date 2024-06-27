#include "push_swap.h"

void ft_pa(t_stack **a, t_stack **b, int j )
{
    t_stack *temp;
    
    if (*a == NULL)
        return ;
    temp = *a;
    *a = (*a)->next;
    temp->next = *b;
    *b = temp;
    ft_set_index(a);
    ft_set_index(b);
    ft_set_prev(a);
    ft_set_prev(b);
    if (j == 0)
        write (1, "pa\n", 3);
}

void    ft_pb(t_stack **a, t_stack **b, int j)
{
    ft_pa(b, a, 1);
    if (j == 0)
        write (1, "pb\n", 3);
}