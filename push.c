/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:07:50 by eedwards          #+#    #+#             */
/*   Updated: 2024/06/30 11:07:51 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pushes number from top of a stack to top of b stack
void	ft_pb(t_stack **a, t_stack **b, int j)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	ft_set_index(a);
	ft_set_prev(a);
	ft_set_prev(b);
	if (j == 0)
		write(1, "pb\n", 3);
}

void	ft_pa(t_stack **a, t_stack **b, int j)
{
	ft_pb(b, a, 1);
	if (j == 0)
		write(1, "pa\n", 3);
}
