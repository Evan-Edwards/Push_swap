#include "push_swap.h"

//main function, takes the arguements given and checks if valid
//It then puts the arguments in t_stack a and calls the ft_sort
//to sort.
void    ft_push_swap(int argc, char **argv)
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
    if (check_valid(argv) == 0)
    {
        write (1, "Error\n", 6);
        return ;
    }
    if (list_args(argv, &a) == 0)
    {
        write (1, "Error\n", 6);
        return ;
    }
    ft_sort(&a, &b);
}







