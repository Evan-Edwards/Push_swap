/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_345.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:40:07 by eedwards          #+#    #+#             */
/*   Updated: 2024/07/03 16:40:08 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_sort3(t_stack **a)
{
	t_stack	*temp;

	if (ft_check_sorted(*a) == 1)
		return ;
	temp = *a;
	if (ft_min(*a) == temp->nbr)
	{
		ft_sa(a, 0);
		ft_ra(a, 0);
	}
	else if (temp->nbr != ft_min(*a) && temp->nbr != ft_max(*a))
	{
		if ((ft_stacklast(*a))->nbr == ft_max(*a))
			ft_sa(a, 0);
		else
			ft_rra(a, 0);
	}
	else
	{
		ft_ra(a, 0);
		if ((*a)->next->nbr == ft_min(*a))
			ft_sa(a, 0);
	}
}
//sorts stacks of 4 or 5 by bringing the min to the top and pushing to b,
//and then sorting the last 3 with ft_sort3
void	ft_sort45(t_stack **a, t_stack **b)
{
	while (ft_stacksize(*a) > 3)
	{
		ft_min_to_top(a);
		if (ft_check_sorted(*a) == 0)
			ft_pb(a, b, 0);
		else
			break ;
	}
	if (ft_check_sorted(*a) == 0)
		ft_sort3(a);
	while (*b)
		ft_pa(a, b, 0);
}
