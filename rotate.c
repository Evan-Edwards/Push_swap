#include "push_swap.h"

//rotates the stack so that the first becomes the last
void    ft_ra(t_stack **a, int j)
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
    if (j == 0)
        write (1, "ra\n", 3);
}

void ft_rb(t_stack **b, int j)
{
    ft_ra(b, 1);
    if (j == 0)
        write (1, "rb\n", 3);
}

void ft_rr(t_stack **a, t_stack **b, int j)
{
    ft_ra(a, 1);
    ft_ra(b, 1);
    if (j == 0)
        write (1, "rr\n", 3);
}