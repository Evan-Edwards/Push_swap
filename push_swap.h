#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>

typedef struct s_stack
{
    long    nbr;
    long    index;
    struct s_stack  *next;
    struct s_stack  *prev;
}	t_stack;

void    ft_swap_elements(t_stack **a);
void    ft_push(t_stack **a, t_stack **b);
void    ft_set_indexes(t_stack **a);
void    ft_rotate(t_stack **a);


#endif