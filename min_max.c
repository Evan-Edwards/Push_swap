#include "push_swap.h"

int ft_min(t_stack **a)
{
    int     min;
    t_stack *temp;

    temp = *a;
    min = temp->nbr;
    temp = temp->next;
    while (temp)
    {
        if (min > temp->nbr)
            min = temp->nbr;
        temp = temp->next;
    }
    return (min);
}

int ft_max(t_stack **a)
{
    int     max;
    t_stack *temp;

    temp = *a;
    max = temp->nbr;
    temp = temp->next;
    while (temp)
    {
        if (max < temp->nbr)
            max = temp->nbr;
        temp = temp->next;
    }
    return (max);
}