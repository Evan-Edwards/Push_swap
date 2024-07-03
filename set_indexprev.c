/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_indexprev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:08:02 by eedwards          #+#    #+#             */
/*   Updated: 2024/06/30 11:08:03 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
