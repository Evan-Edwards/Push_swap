#include "push_swap.h"

//finds how many moves to move a nbr from a to it's
//corect place in b using ra and rb
int ft_moves_rarb(t_stack *a, t_stack *b, int c)
{
    int i;

    i = ft_find_index(a, c);
    if (ft_find_place_b(b, c) > i)
        i = ft_find_place_b(b, c);
    return (i);
}

//finds how many moves to move a nbr from a to it's
//corect place in b using rra and rrb
int ft_moves_rrarrb(t_stack *a, t_stack *b, int c)
{
    int i;

    if (ft_find_index(a, c) != 0)
        i = ft_stacksize(a) - ft_find_index(a, c);
    if (ft_find_place_b(b, c) != 0)
    {
        if (i < ft_stacksize(b) - ft_find_place_b(b, c))
            i = ft_stacksize(b) - ft_find_place_b(b, c);
    }
    return (i);
}

//finds how many moves to move a nbr from a to it's
//corect place in b using ra and rrb
int ft_moves_rarrb(t_stack *a, t_stack *b, int c)
{
     int i;

    if (ft_find_index(a, c) != 0)
        i = ft_stacksize(a) - ft_find_index(a, c);
    i += ft_find_place_b(b, c);
    return (i);
}

//finds how many moves to move a nbr from a to it's
//corect place in b using rra and rb
int ft_moves_rrarb(t_stack *a, t_stack *b, int c)
{
    int i;

    i = ft_find_index(a, c);
    if (ft_find_place_b != 0)
        i += ft_stacksize(b) - ft_find_place_b(b, c);
    return (i);
}