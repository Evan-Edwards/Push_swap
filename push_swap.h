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

void    ft_push_swap(int argc, char **argv);
void    ft_sort(t_stack **a, t_stack **b);
void    ft_sort3(t_stack **a);
void    ft_sort(t_stack **a, t_stack **b);
void    ft_sort_push_b(t_stack **a, t_stack **b);
void    ft_sort_b_til_3(t_stack **a, t_stack **b);
void    ft_sort_push_a(t_stack **a, t_stack **b);


int     check_valid(char **arg);
int	    ft_atoi2(char **str);
int     ft_check_doubles (t_stack **a);
int	    ft_isdigit(int c);
int	    ft_isspace(int c);
int		ft_list_args(char **argv, t_stack **a);


int     ft_check_sorted(t_stack *a);
int     ft_find_index(t_stack **a, int nbr);
int     ft_find_place_a(t_stack *a, int nbr);
int     ft_find_place_b(t_stack *b, int nbr);
int     ft_max(t_stack *a);
void    ft_max_to_top(t_stack **b);
int     ft_min(t_stack *a);
void    ft_min_to_top(t_stack **a);
void    ft_set_index(t_stack **a);
void    ft_set_prev(t_stack **a);

int     ft_find_cheapest_ab(t_stack *a, t_stack *b);
int     ft_find_cheapest_ba(t_stack *a, t_stack *b);
int     ft_moves_rarb(t_stack *a, t_stack *b, int c);
int     ft_moves_rarrb(t_stack *a, t_stack *b, int c);
int     ft_moves_rrarb(t_stack *a, t_stack *b, int c);
int     ft_moves_rrarrb(t_stack *a, t_stack *b, int c);
int     ft_moves_rarb_a(t_stack *a, t_stack *b, int c);
int     ft_moves_rarrb_a(t_stack *a, t_stack *b, int c);
int     ft_moves_rrarb_a(t_stack *a, t_stack *b, int c);
int     ft_moves_rrarrb_a(t_stack *a, t_stack *b, int c);

void    ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);
void    ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
void    ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
void    ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);

void    ft_pa(t_stack **a, t_stack **b, int j);
void    ft_pb(t_stack **a, t_stack **b, int j);
void    ft_ra(t_stack **a, int j);
void    ft_rb(t_stack **b, int j);
void    ft_rr(t_stack **a, t_stack **b, int j);
void    ft_rra(t_stack **a, int j);
void    ft_rrb(t_stack **b, int j);
void    ft_rrr(t_stack **a, t_stack **b, int j);
void    ft_sa(t_stack **a, int j);
void    ft_sb(t_stack **b, int j);
void    ft_ss(t_stack **a, t_stack **b, int j);


void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackclear(t_stack **lst);
t_stack	*ft_stacklast(t_stack *lst);
t_stack *ft_stacknew(int nbr);
int	    ft_stacksize(t_stack *lst);





#endif