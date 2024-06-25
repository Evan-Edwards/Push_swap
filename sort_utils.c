#include "push_swap.h"

int ft_find_index(t_stack *a, int nbr)
{
    while (a)
    {
        if (nbr == a->nbr)
            return (a->index);
        a = a->next;
    }
    return (-1);
}
//need the return (-1)?

void    ft_min_to_top(t_stack **a)
{
    int index_min;

    index_min = ft_find_index(*a, ft_min(*a));
    if (index_min < ft_stacksize(*a) - index_min)
    {
        while ((*a)->nbr != ft_min(*a))
            ft_ra(a);
    }
    else
    {
        while ((*a)->nbr != ft_min(*a))
            ft_rra(a);
    }
}

void    ft_max_to_top(t_stack **b)
{
    int index_max;

    index_max = ft_find_index(*b, ft_min(*b));
    if (index_max < ft_stacksize(*b) - index_max)
    {
        while ((*b)->nbr != ft_max(*b))
            ft_ra(b);
    }
    else
    {
        while ((*b)->nbr != ft_max(*b))
            ft_rra(b);
    }
}

int ft_find_place_b(t_stack *b, int nbr)
{
    int     i;
    t_stack *temp;

    i = 1; //?
    if (nbr > b->nbr && nbr < ft_stacklast(b)->nbr)
        i = 0;
    else if (nbr > ft_max(b) || nbr < ft_min(b))
        i = ft_find_index(b, ft_max(b));
    else
    {
        temp = b->next;
        while (nbr < temp->nbr || nbr > b->nbr )
        {
            b = b->next;
            temp = b->next;
            i++;
        }
    }
    return (i);
}

int ft_find_place_a(t_stack *a, int nbr)
{
    int     i;
    t_stack *temp;

    i = 1; //?
    if (nbr < a->nbr && nbr > ft_stacklast(a)->nbr)
        i = 0;
    else if (nbr > ft_max(a) || nbr < ft_min(a))
        i = ft_find_index(a, ft_min(a));
    else
    {
        temp = a->next;
        while (nbr > temp->nbr || nbr < a->nbr )
        {
            a = a->next;
            temp = a->next;
            i++;
        }
    }
    return (i);
}