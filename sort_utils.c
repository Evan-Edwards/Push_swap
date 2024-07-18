/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:08:10 by eedwards          #+#    #+#             */
/*   Updated: 2024/07/03 16:42:15 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(t_stack *a, int nbr)
{
	while (a)
	{
		if (nbr == a->nbr)
			return (a->index);
		a = a->next;
	}
	return (-1);
}

void	ft_min_to_top(t_stack **a)
{
	int	index_min;

	index_min = ft_find_index(*a, ft_min(*a));
	if (index_min < ft_stacksize(*a) - index_min)
	{
		while ((*a)->nbr != ft_min(*a))
			ft_ra(a, 0);
	}
	else
	{
		while ((*a)->nbr != ft_min(*a))
			ft_rra(a, 0);
	}
}

void	ft_max_to_top(t_stack **b)
{
	int	index_max;

	index_max = ft_find_index(*b, ft_min(*b));
	if (index_max < ft_stacksize(*b) - index_max)
	{
		while ((*b)->nbr != ft_max(*b))
			ft_rb(b, 0);
	}
	else
	{
		while ((*b)->nbr != ft_max(*b))
			ft_rrb(b, 0);
	}
}

//finds the correct place for the given number in the stack b
int	ft_find_place_b(t_stack *b, int nbr)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (nbr > b->nbr && nbr < ft_stacklast(b)->nbr)
		i = 0;
	else if (nbr > ft_max(b) || nbr < ft_min(b))
		i = ft_find_index(b, ft_max(b));
	else
	{
		temp = b->next;
		while (nbr < temp->nbr || nbr > b->nbr)
		{
			b = b->next;
			temp = b->next;
			i++;
		}
	}
	return (i);
}

//finds the correct place for the given number in the stack a
int	ft_find_place_a(t_stack *a, int nbr)
{
	int		i;
	t_stack	*temp;

	i = 1;
	if (nbr < a->nbr && nbr > ft_stacklast(a)->nbr)
		i = 0;
	else if (nbr > ft_max(a) || nbr < ft_min(a))
		i = ft_find_index(a, ft_min(a));
	else
	{
		temp = a->next;
		while (nbr > temp->nbr || nbr < a->nbr)
		{
			a = a->next;
			temp = a->next;
			i++;
		}
	}
	return (i);
}
