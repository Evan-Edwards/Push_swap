/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:38:59 by eedwards          #+#    #+#             */
/*   Updated: 2024/07/30 18:09:51 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks if sorted, returns 1 if sorted
int	ft_check_sorted(t_stack *a)
{
	while (a->next != NULL)
	{
		if (a->next->nbr < a->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

//returns minimum number in stack
int	ft_min(t_stack *a)
{
	int	min;

	min = a->nbr;
	a = a->next;
	while (a)
	{
		if (min > a->nbr)
			min = a->nbr;
		a = a->next;
	}
	return (min);
}

//returns maximum number in stack
int	ft_max(t_stack *a)
{
	int	max;

	max = a->nbr;
	a = a->next;
	while (a)
	{
		if (max < a->nbr)
			max = a->nbr;
		a = a->next;
	}
	return (max);
}

void	ft_set_index(t_stack **a)
{
	int		index;
	t_stack	*i;

	if (!a)
		return ;
	index = 0;
	i = *a;
	while (i)
	{
		i->index = index;
		index++;
		i = i->next;
	}
}

void	ft_set_prev(t_stack **a)
{
	t_stack	*i;

	if (!*a)
		return ;
	i = *a;
	i->prev = NULL;
	while (i->next)
	{
		i->next->prev = i;
		i = i->next;
	}
}
