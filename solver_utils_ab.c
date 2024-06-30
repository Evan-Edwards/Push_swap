/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:08:05 by eedwards          #+#    #+#             */
/*   Updated: 2024/06/30 11:08:06 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_cheapest_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = ft_moves_rarb(a, b, a->nbr);
	while (a && i != 0)
	{
		if (i > ft_moves_rarb(a, b, tmp->nbr))
			i = ft_moves_rarb(a, b, tmp->nbr);
		if (i > ft_moves_rarrb(a, b, tmp->nbr))
			i = ft_moves_rarrb(a, b, tmp->nbr);
		if (i > ft_moves_rrarb(a, b, tmp->nbr))
			i = ft_moves_rrarb(a, b, tmp->nbr);
		if (i > ft_moves_rrarrb(a, b, tmp->nbr))
			i = ft_moves_rrarrb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

//finds how many moves to move a nbr from a to it's
//corect place in b using ra and rb
int	ft_moves_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_index(a, c);
	if (ft_find_place_b(b, c) > i)
		i = ft_find_place_b(b, c);
	return (i);
}

//finds how many moves to move a nbr from a to it's
//corect place in b using rra and rrb
int	ft_moves_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	if (ft_find_index(a, c) != 0)
		i = ft_stacksize(a) - ft_find_index(a, c);
	if (ft_find_place_b(b, c) != 0)
	{
		if (i < ft_stacksize(b) - ft_find_place_b(b, c))
			i = ft_stacksize(b) - ft_find_place_b(b, c);
	}
	return (i);
}

//finds how many moves to move a nbr from a to it's
//corect place in b using ra and rrb
int	ft_moves_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	if (ft_find_index(a, c) != 0)
		i = ft_stacksize(a) - ft_find_index(a, c);
	i += ft_find_place_b(b, c);
	return (i);
}

//finds how many moves to move a nbr from a to it's
//corect place in b using rra and rb
int	ft_moves_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_index(a, c);
	if (ft_find_place_b(b, c) != 0)
		i += ft_stacksize(b) - ft_find_place_b(b, c);
	return (i);
}
