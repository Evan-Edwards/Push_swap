/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:38:59 by eedwards          #+#    #+#             */
/*   Updated: 2024/07/02 16:52:14 by eedwards         ###   ########.fr       */
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


//clears stack, outputs error, and exits program
void    ft_error(t_stack **a)
{
    ft_stackclear(a);
    write (1, "Error\n", 6);
    exit(1);
}

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