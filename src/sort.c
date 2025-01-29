/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:08:12 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/05 11:15:47 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sorts t_stack a if needed by calling ft_sa if there is only 2 numbers, 
//ft_sort3 if there's 3 numbers, ft_sort45 for 4/5 numbers,
//and uses ft_sort_push_b ft_sort_push_a and ft_min_to_top to sort if it is 
//longer than 3 numbers.
void	ft_sort(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stacksize(*a);
	if (ft_check_sorted(*a) == 1 || size <= 1)
		return ;
	else if (size == 2)
		ft_sa(a, 0);
	else if (size == 3)
		ft_sort3(a);
	else if (size == 4 || size == 5)
		ft_sort45(a, b);
	else
	{
		ft_sort_push_b(a, b);
		ft_sort_push_a(a, b);
		ft_min_to_top(a);
	}
}

//first pushes 2 first numbers to b as long as a is not sorted. Then it calls 
//the ft_sort_b_til_3 to send all but 3 numbers to a. It then sorts the last 3
// numbers with ft_sort3.
void	ft_sort_push_b(t_stack **a, t_stack **b)
{
	ft_pb(a, b, 0);
	if (ft_check_sorted(*a) == 0)
		ft_pb(a, b, 0);
	if (ft_check_sorted(*a) == 0)
		ft_sort_push_b_til_3(a, b);
	if (ft_check_sorted(*a) == 0)
		ft_sort3(a);
}

void	ft_sort_push_b_til_3(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	while (ft_stacksize(*a) > 3 && ft_check_sorted(*a) == 0)
	{
		tmp = *a;
		i = ft_find_cheapest_ab(*a, *b);
		while (i >= 0)
		{
			if (i == ft_moves_rarb(*a, *b, tmp->nbr))
				i = ft_apply_rarb(a, b, tmp->nbr, 'a');
			else if (i == ft_moves_rarrb(*a, *b, tmp->nbr))
				i = ft_apply_rarrb(a, b, tmp->nbr, 'a');
			else if (i == ft_moves_rrarb(*a, *b, tmp->nbr))
				i = ft_apply_rrarb(a, b, tmp->nbr, 'a');
			else if (i == ft_moves_rrarrb(*a, *b, tmp->nbr))
				i = ft_apply_rrarrb(a, b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

//1)Finds the cheapest number and method to place it correctly in stack a.
//2) Identify the correct number and method.
//3)Apply that method to move the number to stack a.
void	ft_sort_push_a(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	while (*b)
	{
		tmp = *b;
		i = ft_find_cheapest_ba(*a, *b);
		while (i >= 0)
		{
			if (i == ft_moves_rarb_a(*a, *b, tmp->nbr))
				i = ft_apply_rarb(a, b, tmp->nbr, 'b');
			else if (i == ft_moves_rarrb_a(*a, *b, tmp->nbr))
				i = ft_apply_rarrb(a, b, tmp->nbr, 'b');
			else if (i == ft_moves_rrarb_a(*a, *b, tmp->nbr))
				i = ft_apply_rrarb(a, b, tmp->nbr, 'b');
			else if (i == ft_moves_rrarrb_a(*a, *b, tmp->nbr))
				i = ft_apply_rrarrb(a, b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
}
