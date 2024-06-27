#include "push_swap.h"

//sorts t_stack a if needed by calling ft_sa if there
//is only 2 numbers, ft_sort3 if there's 3 numbers,
//and uses ft_sort_push_bm ft_sort_push_a and ft_min_to_top
// to sort if it is longer than 3 numbers.
void    ft_sort(t_stack **a, t_stack **b)
{
    if (ft_check_sorted(*a) == 1)
        return ;
    else if ((ft_stacklast(a))->index == 1)
        ft_sa(a, 0);
    else if ((ft_stacklast(a))->index == 2)
        ft_sort3(a);
    else if ((ft_stacklast(a))->index > 2)
    {
        ft_sort_push_b(a, b);
        ft_sort_push_a(a, b);
        ft_min_to_top(a);
    }
}

//first pushes 2 first numbers to a as long as a is not 
//sorted and has more than 3 numbers. Then it calls the 
//ft_sort_b_til_3 to send all but 3 numbers to a. It
//then sorts the last 3 numbers with ft_sort3. 
void    ft_sort_push_b(t_stack **a, t_stack **b)
{
    ft_pb(a, b, 0);
    if (ft_stacksize(a) > 3 && ft_check_sorted == 0)
        ft_pb(a, b, 0);
    if (ft_stacksize(a) > 3 && ft_check_sorted == 0)
        ft_sort_b_til_3(a, b);
    if (ft_check_sorted(a) == 0)
        ft_sort3(a);
}

void    ft_sort_b_til_3(t_stack **a, t_stack **b)
{
    int i;
    t_stack *tmp;

    while (ft_stacksize(a) > 3 && ft_check_sorted == 0)
    {
        tmp = *a;
        i = ft_find_cheapest_ab(*a, *b);
        while (tmp)
        {
            if (i == ft_moves_rarb(a, b, tmp->nbr))
                ft_apply_rarb(a, b, tmp->nbr, 'a');
            else if (i == ft_moves_rarrb(a, b, tmp->nbr))
                ft_apply_rarrb(a, b, tmp->nbr, 'a');
            else if (i == ft_moves_rrarb(a, b, tmp->nbr))
                ft_apply_rrarb(a, b, tmp->nbr, 'a');
            else if (i == ft_moves_rrarrb(a, b, tmp->nbr))
                ft_apply_rrarrb(a, b, tmp->nbr, 'a');
            else
                tmp = tmp->next;
        }
    }
}

void    ft_sort3(t_stack **a)
{
    t_stack *temp;
    
    if (ft_check_sorted(*a) == 1)
        return ;
    temp = *a;
    if (ft_min(*a) == temp->nbr)
    {
        ft_sa(a, 0);
        ft_ra(a, 0);
    }
    else if (temp->nbr != ft_min(*a) && temp->nbr != ft_max(*a))
    {
        if ((ft_stacklast(a))->nbr == ft_max(*a))
            ft_sa(a, 0);
        else
            ft_rra(a, 0);
    }
    else
    {
        ft_ra(a, 0);
        if ((ft_stacklast(a))->nbr == ft_min(*a))
            ft_sa(a, 0);
    }
         
}


void    ft_sort_push_a(t_stack **a, t_stack **b)
{
    int i;
    t_stack *tmp;

    while (*b)
    {
        tmp = *a;
        i = ft_find_cheapest_ab(*a, *b);
        while (tmp)
        {
            if (i == ft_moves_rarb_a(a, b, tmp->nbr))
                ft_apply_rarb(a, b, tmp->nbr, 'b');
            else if (i == ft_moves_rarrb_a(a, b, tmp->nbr))
                ft_apply_rarrb(a, b, tmp->nbr, 'b');
            else if (i == ft_moves_rrarb_a(a, b, tmp->nbr))
                ft_apply_rrarb(a, b, tmp->nbr, 'b');
            else if (i == ft_moves_rrarrb_a(a, b, tmp->nbr))
                ft_apply_rrarrb(a, b, tmp->nbr, 'b');
            else
                tmp = tmp->next;
        }
    }
}
