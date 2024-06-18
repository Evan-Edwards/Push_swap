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
    list_args(argv, &a);

}


void		list_args(char **argv, t_stack **a)
{
    t_stack *temp;

    temp = *a;
    while (*argv)
    {
        if (!(check_valid(*argv)))
            write (1, "Error", 5);
        
    }
    
}

int    check_valid(char *arg)
{
    int i;

    while (arg[i])
    {
        if (arg[i] < '0' || arg[i] > '9')
            return (0);
        i++;
    }
    return (1);
    //check that number
}



