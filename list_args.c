/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:07:31 by eedwards          #+#    #+#             */
/*   Updated: 2024/07/02 17:03:00 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_list_args(int argc, char **argv, t_stack **a)
{
	t_stack	*new;
	int		i;

	new = NULL;
	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (ft_check_valid(argv[i]) == 0)
			ft_error(a);
		new = ft_stacknew(ft_atoi2(argv[i]));
		if (new == NULL)
			ft_error(a);
		ft_stackadd_back(a, new);
		i++;
	}
	if (ft_check_doubles(a) == 0)
		ft_error(a);
}

//checks if the string given is a valid input, can have 1 plus or
//minus and the other characters must be numbers
int	ft_check_valid(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

//checks if there if doubles in the stack, returns 1 if no
//doubles found
int	ft_check_doubles(t_stack **a)
{
	int		check;
	t_stack	*temp;
	t_stack	*temp2;

	temp = *a;
	ft_set_index(a);
	ft_set_prev(a);
	while (temp)
	{
		check = temp->nbr;
		temp2 = *a;
		while (temp2)
		{
			if (temp2->nbr == check && temp->index != temp2->index)
				return (0);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (1);
}

//need to also check that works with single string of numbers
//also can have space, -, or + in front
//make characters into numbers (atoi)
int	ft_atoi2(char *str)
{
	long	result;
	long	check;
	int		sign;

	sign = 1;
	result = 0;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
		check = result;
		result = result * 10 + *str - '0';
		if (result / 10 != check && sign < 0)
			return (0);
		if (result / 10 != check && sign > 0)
			return (-1);
		str++;
	}
	return ((int)(result * sign));
}
