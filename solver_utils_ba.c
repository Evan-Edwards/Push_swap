/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ba.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:08:08 by eedwards          #+#    #+#             */
/*   Updated: 2024/06/30 11:08:09 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_cheapest_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = ft_moves_rarb_a(a, b, b->nbr);
	while (tmp && i != 0)
	{
		if (i > ft_moves_rarb_a(a, b, tmp->nbr))
			i = ft_moves_rarb_a(a, b, tmp->nbr);
		if (i > ft_moves_rarrb_a(a, b, tmp->nbr))
			i = ft_moves_rarrb_a(a, b, tmp->nbr);
		if (i > ft_moves_rrarb_a(a, b, tmp->nbr))
			i = ft_moves_rrarb_a(a, b, tmp->nbr);
		if (i > ft_moves_rrarrb_a(a, b, tmp->nbr))
			i = ft_moves_rrarrb_a(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

//finds how many moves to move a nbr from b to it's
//corect place in a using ra and rb_a
int	ft_moves_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_index(b, c);
	if (ft_find_place_a(a, c) > i)
		i = ft_find_place_a(a, c);
	return (i);
}

//finds how many moves to move a nbr from b to it's
//corect place in a using rra and rrb_a
int	ft_moves_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	if (ft_find_index(b, c) != 0)
		i = ft_stacksize(b) - ft_find_index(b, c);
	if (ft_find_place_a(a, c) != 0)
	{
		if (i < ft_stacksize(a) - ft_find_place_a(a, c))
			i = ft_stacksize(a) - ft_find_place_a(a, c);
	}
	return (i);
}

//finds how many moves to move a nbr from b to it's
//corect place in a using ra and rrb_a
int	ft_moves_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	if (ft_find_index(b, c) != 0)
		i = ft_stacksize(b) - ft_find_index(b, c);
	i += ft_find_place_a(a, c);
	return (i);
}

//finds how many moves to move a nbr from b to it's
//corect place in a using rra and rb_a
int	ft_moves_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_index(b, c);
	if (ft_find_place_a(a, c) != 0)
		i += ft_stacksize(a) - ft_find_place_a(a, c);
	return (i);
}
