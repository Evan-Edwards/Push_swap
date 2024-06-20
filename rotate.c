#include "push_swap.h"

void    ft_rotate(t_stack **a)
{
    t_stack *temp1;
    t_stack *temp2;

    if (*a == NULL || (*a)->next == NULL)
        return ;
    temp1 = *a;
    *a = (*a)->next;
    (*a)->prev = NULL;
    temp2 = *a;
    while (temp2->next != NULL)
        temp2 = temp2->next;
    temp2->next = temp1;
    temp1->prev = temp2;
    temp1->next = NULL;
}