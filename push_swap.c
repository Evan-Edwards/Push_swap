/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:07:39 by eedwards          #+#    #+#             */
/*   Updated: 2024/06/30 14:47:08 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//main function, takes the arguements given and checks if valid
//It then puts the arguments in t_stack a and calls the ft_sort
//to sort.
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	
	printf("started\n");
	if (argc <= 1)
	{
		write(1, "argc Error\n", 11);
		return (0);
	}
	a = NULL;
	b = NULL;
	printf("argc valid\n");
	if (ft_check_valid(argv) == 0)
	{
		write(1, "val Error\n", 10);
		return (0);
	}
	printf("check_valid_passed\n");
	if (ft_list_args(argv, &a) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	printf("args listed\n");
	while (a)
	{
		printf("%li\n", a->nbr);
		a = a->next;
	}
	ft_sort(&a, &b);
	printf("args sorted\n");
	ft_stackclear(&a);
	return (0);
}

//goes through every character of every arguement to check
//that each chacter is number, space, or -/+, and that if there
//is a i/+ there is a number after it
int	ft_check_valid(char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (arg[i])
	{
		j = 0;
		while ((arg[i])[j])
		{
			if (ft_isdigit((arg[i])[j]) == 1 || ft_isspace((arg[i])[j]) == 1
				|| (arg[i])[j] == '-' || (arg[i])[j] == '+')
			{
				if (((arg[i])[j] == '-' || (arg[i])[j] == '+') &&
					(ft_isdigit((arg[i])[j + 1]) != 1))
					return (0);
				j++;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}