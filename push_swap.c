#include "push_swap.h"


void    push_swap(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    
    if (argc <= 1)
    {
        write (1, "Error", 5);
        return ;
    }
    a = NULL;
    b = NULL;
    if (list_args(argv, &a) == 0)
    {
        write (1, "Error\n", 6);
        return ;
    }
    ft_sort(&a, &b);
}

void    ft_sort(t_stack **a, t_stack **b)
{
    if (ft_check_sorted(*a) == 1)
        return ;
    if ((ft_stacklast(a))->index == 1)
        ft_sa(a);
    if ((ft_stacklast(a))->index == 2)
        ft_sort3(a);
    if ((ft_stacklast(a))->index == 3)
        ft_sort4(a);
    if ((ft_stacklast(a))->index == 4)
        ft_sort5(a);
    if ((ft_stacklast)->index > 4)
}






