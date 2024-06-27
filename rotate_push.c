#include "push_swap.h"

void    ft_apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
    if (s == 'a')
    {
        while ((*a)->nbr != c && ft_find_place_b(b, c) != 0)
            ft_rr(a, b);
        while ((*a)->nbr != c)
            ft_ra(a);
        while (ft_find_place_b(b, c) != 0)
            ft_rb(b);
        ft_pa(a, b);
    }
    else
    {
        while ((*b)->nbr != c && ft_find_place_a(a, c) != 0)
            ft_rr(a, b);
        while ((*b)->nbr != c)
            ft_rb(b);
        while (ft_find_place_a(a, c) != 0)
            ft_ra(a);
        ft_pb(a, b);
    }
}

void    ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
    if (s == 'a')
    {
        while ((*a)->nbr != c)
            ft_ra(a);
        while (ft_find_place_b(b, c) != 0)
            ft_rrb(b);
        ft_pa(a, b);
    }
    else
    {
        while ((*b)->nbr != c)
            ft_rrb(b);
        while (ft_find_place_a(a, c) != 0)
            ft_ra(a);
        ft_pb(a, b);
    }
}

void    ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
    if (s == 'a')
    {
        while ((*a)->nbr != c)
            ft_rra(a);
        while (ft_find_place_b(b, c) != 0)
            ft_rb(b);
        ft_pa(a, b);
    }
    else
    {
        while ((*b)->nbr != c)
            ft_rb(b);
        while (ft_find_place_a(a, c) != 0)
            ft_rra(a);
        ft_pb(a, b);
    }
}

void    ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
    if (s == 'a')
    {
        while ((*a)->nbr != c && ft_find_place_b(b, c) != 0)
            ft_rrr(a, b);
        while ((*a)->nbr != c)
            ft_rra(a);
        while (ft_find_place_b(b, c) != 0)
            ft_rrb(b);
        ft_pa(a, b);
    }
    else
    {
        while ((*b)->nbr != c && ft_find_place_a(a, c) != 0)
            ft_rrr(a, b);
        while ((*b)->nbr != c)
            ft_rrb(b);
        while (ft_find_place_a(a, c) != 0)
            ft_rra(a);
        ft_pb(a, b);
    }
}