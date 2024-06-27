#include "push_swap.h"

int ft_min(t_stack *a)
{
    int     min;
    
    min = a->nbr;
    a = a->next;
    while (a)
    {
        if (min > a->nbr)
            min = a->nbr;
        a = a->next;
    }
    return (min);
}

int ft_max(t_stack *a)
{
    int     max;

    max = a->nbr;
    a = a->next;
    while (a)
    {
        if (max < a->nbr)
            max = a->nbr;
        a = a->next;
    }
    return (max);
}