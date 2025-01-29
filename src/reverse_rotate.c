/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:07:53 by eedwards          #+#    #+#             */
/*   Updated: 2024/06/30 12:34:10 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//reverse rotates a stack so that the last becomes the first
void	ft_rra(t_stack **a, int j)
{
	t_stack	*temp;

	temp = ft_stacklast(*a);
	temp->prev->next = NULL;
	temp->next = *a;
	*a = temp;
	ft_set_index(a);
	ft_set_prev(a);
	if (j == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b, int j)
{
	ft_rra(b, 1);
	if (j == 0)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	ft_rra(a, 1);
	ft_rra(b, 1);
	if (j == 0)
		write(1, "rrr\n", 4);
}
