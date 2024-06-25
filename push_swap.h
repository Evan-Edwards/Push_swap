#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>

typedef struct s_stack
{
    long    nbr;//pointer?
    long    index;//pointer?
    struct s_stack  *next;
    struct s_stack  *prev;
}	t_stack;

int     check_valid(char **arg);
int	    ft_atoi2(char **str);
int     ft_check_doubles (t_stack **a);
int	    ft_isdigit(int c);
int	    ft_isspace(int c);
int     ft_max(t_stack **a);
int     ft_min(t_stack **a);
void    ft_push(t_stack **a, t_stack **b);
void    ft_ra(t_stack **a);
void    ft_rb(t_stack **b);
void    ft_rr(t_stack **a, t_stack **b);
void    ft_sa(t_stack **a);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackclear(t_stack **lst);
t_stack	*ft_stacklast(t_stack *lst);
t_stack *ft_stacknew(int nbr);
void    ft_swap_elements(t_stack **a);
void    ft_set_indexes(t_stack **a); //duplicate
int		list_args(char **argv, t_stack **a);
void    set_index(t_stack **a);
void    set_prev(t_stack **a);


#endif