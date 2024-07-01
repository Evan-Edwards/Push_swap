/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:07:31 by eedwards          #+#    #+#             */
/*   Updated: 2024/06/30 14:58:04 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_args(char **argv, t_stack **a)
{
	t_stack	*new;
	int		i;
	int		j;

	new = NULL;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			new = ft_stacknew(ft_atoi2(argv[i][j]));
			//need to make another t_stack var?
			if (new == NULL)
			{
				ft_stackclear(a);
				return (0);
			}
			ft_stackadd_back(a, new);
			j++;
		}
		i++;
	}
	if (ft_check_doubles(a) == 0)
	{
		ft_stackclear(a);
		return (0);
	}
	return (1);
}

int	ft_multiple_check(char *str)
{
	int	i;
	int	nonum;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 && nonum

	}
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


