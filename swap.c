#include "push_swap.h"

//swaps the top 2 numbers of stack a
void    ft_sa(t_stack **a, int j)
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
    if (j == 0)
        write (1, "sa\n", 3);

}

void    ft_sb(t_stack **b, int j)
{
    ft_sa(b, 1);
    if (j == 0)
        write (1, "sb\n", 3);
}

void    ft_ss(t_stack **a, t_stack **b, int j)
{
    ft_sa(a, 1);
    ft_sa(b, 1);
    if (j == 0)
        write (1, "ss\n", 3);
}

