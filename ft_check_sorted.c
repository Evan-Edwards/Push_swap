#include "push_swap.h"

//checks if sorted
int ft_check_sorted(t_stack *a)
{
    while (a->next)
    {
        if (a->next->nbr < a->nbr)
            return (0);
        a = a->next;
    }
    return (1);
}