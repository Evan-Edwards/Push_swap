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
    //malloc?
    if (list_args(argv, &a) == 0)
    {
        write (1, "Error\n", 6);
        return ;
    }

}






