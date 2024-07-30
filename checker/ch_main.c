/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:50:16 by eedwards          #+#    #+#             */
/*   Updated: 2024/07/30 18:33:01 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	apply_op(char *op, t_stack **a, t_stack **b)
{
	if (op == "sa\n")
		ft_sa(a, 1);
	if (op == "sb\n")
		ft_sb(b, 1);
	if (op == "ss\n")
		ft_ss(a, b, 1);
	if (op == "pa\n")
		ft_pa(a, b, 1);
	if (op == "pb\n")
		ft_pb(a, b, 1);
	if (op == "ra\n")
		ft_ra(a, 1);
	if (op == "rb\n")
		ft_rb(b, 1);
	if (op == "rr\n")
		ft_rr(a, b, 1);
	if (op == "rra\n")
		ft_rra(a, 1);
	if (op == "rrb\n")
		ft_rrb(b, 1);
	if (op == "rrr\n")
		ft_rrr(a, b, 1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	a = NULL;
	b = NULL;
	if (ac <= 1)
		return (0);
	if (ac == 2)
	{
		av = ft_split((const char *)av[1], ' ');
		if (!av || !*av)
			ft_error(&a);
	}
	ft_args_to_stack(ac, av, &a);
	op = get_next_line(0);
	while (op != NULL)
	{
		apply_op(op, &a, &b);
		op = get_next_line(0);
	}
	if (ft_check_sorted(a) == 0 || b != NULL)
		write (1, "KO\n", 3);
	write (1, "OK\n", 3);
}
