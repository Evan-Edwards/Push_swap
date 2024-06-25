#include "push_swap.h"

void    ft_sort3(t_stack **a)
{
    t_stack *temp;
    
    if (ft_check_sorted(a) == 1)
        return ;
    temp = *a;
    if (ft_min(a) == temp->nbr)
    {
        ft_sa(a);
        ft_ra(a);
    }
    else if (temp->nbr != ft_min(a) && temp->nbr != ft_max(a))
    {
        if ((ft_stacklast(a))->nbr == ft_max(a))
            ft_sa(a);
        else
            ft_rra(a);
    }
    else
    {
        ft_ra(a);
        if ((ft_stacklast(a))->nbr == ft_min(a))
            ft_sa(a);
    }
         
}

void    ft_sort4(t_stack **a)
{
    if (ft_check_sorted(a) == 1)
        return ;
}

void    ft_sort5(t_stack **a)
{
    if (ft_check_sorted(a) == 1)
        return ;
}