/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:39:10 by eedwards          #+#    #+#             */
/*   Updated: 2024/06/30 11:39:11 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//checks if sorted, returns 1 if sorted
int	ft_check_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->next->nbr < a->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}
