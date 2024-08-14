/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:07:39 by eedwards          #+#    #+#             */
/*   Updated: 2024/08/14 10:33:29 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	free_split_result(char **argv);

//main function, checks that argc is more than 1, uses ft_split to make a 
//single string of values into an array of strings, lists args in t_stack a and
//then sorts them.
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split((const char *)argv[1], ' ');
		if (!argv || !*argv)
			ft_error(&a);
	}
	ft_args_to_stack(argc, argv, &a);
	ft_sort(&a, &b);
	ft_stackclear(&a);
	if (argc == 2)
		free_split_result(argv);
	return (0);
}

//frees the result of using ft_split if there is only 1 argument given
void	free_split_result(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free (argv[i]);
		i++;
	}
	free (argv);
}
