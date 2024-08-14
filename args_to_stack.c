/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:07:31 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/14 10:31:59 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//takes the args given and puts them into the t_stack a
//it first checks that the arguments are valid, then makes
//a new stack element and adds it to the back of the stack
//it also checks if there are doubles
void	ft_args_to_stack(int argc, char **argv, t_stack **a)
{
	t_stack	*new;
	int		i;
	long	nbr;

	new = NULL;
	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (ft_check_valid(argv[i]) == 0)
			ft_invalid_arg(argc, argv, a);
		nbr = ft_atoi2(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			ft_invalid_arg(argc, argv, a);
		new = ft_stacknew(nbr);
		if (new == NULL)
			ft_invalid_arg(argc, argv, a);
		ft_stackadd_back(a, new);
		i++;
	}
	if (ft_check_doubles(a) == 0)
		ft_invalid_arg(argc, argv, a);
}

void	ft_invalid_arg(int argc, char **argv, t_stack **a)
{
	if (argc == 2)
		free_split_result(argv);
	ft_error(a);
}

//clears stack, outputs error, and exits program
void	ft_error(t_stack **a)
{
	ft_stackclear(a);
	write(2, "Error\n", 6);
	exit(1);
}

//checks if the string given is a valid input, can have 1 plus or
//minus and the other characters must be numbers
int	ft_check_valid(char *arg)
{
	int	i;

	i = 0;
	if ((arg[i] == '-' || arg[i] == '+') && ft_isdigit(arg[i + 1]) == 1)
		i++;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

//checks if there is doubles in the stack, returns 1 if no
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

//makes longs from the char strings given
long	ft_atoi2(char *str)
{
	long	result;
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
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
