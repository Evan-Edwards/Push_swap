#include "push_swap.h"

//finds how many moves to move a nbr from b to it's
//corect place in a using ra and rb
int ft_moves_rarb_a(t_stack *a, t_stack *b, int c)
{
    int i;

    i = ft_find_index(b, c);
    if (ft_find_place_b(a, c) > i)
        i = ft_find_place_a(a, c);
    return (i);
}

//finds how many moves to move a nbr from b to it's
//corect place in a using rra and rrb
int ft_moves_rrarrb_a(t_stack *a, t_stack *b, int c)
{
    int i;

    if (ft_find_index(b, c) != 0)
        i = ft_stacksize(b) - ft_find_index(b, c);
    if (ft_find_place_a(b, c) != 0)
    {
        if (i < ft_stacksize(a) - ft_find_place_a(a, c))
            i = ft_stacksize(a) - ft_find_place_a(a, c);
    }
    return (i);
}

//finds how many moves to move a nbr from b to it's
//corect place in a using ra and rrb
int ft_moves_rarrb_a(t_stack *a, t_stack *b, int c)
{
     int i;

    if (ft_find_index(b, c) != 0)
        i = ft_stacksize(b) - ft_find_index(b, c);
    i += ft_find_place_a(a, c);
    return (i);
}

//finds how many moves to move a nbr from b to it's
//corect place in a using rra and rb
int ft_moves_rrarb_a(t_stack *a, t_stack *b, int c)
{
    int i;

    i = ft_find_index(b, c);
    if (ft_find_place_a(a, c) != 0)
        i += ft_stacksize(a) - ft_find_place_a(a, c);
    return (i);
}