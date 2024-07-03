/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:07:39 by eedwards          #+#    #+#             */
/*   Updated: 2024/07/02 15:46:52 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//main function, takes the arguements given and checks if valid
//It then puts the arguments in t_stack a and calls the ft_sort
//to sort.
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		ft_error(&a);
	if (argc == 2)
		argv = ft_split((const char *)argv[1], ' ');
	ft_list_args(argc, argv, &a);
	printf("args listed\n");
	ft_sort(&a, &b);
	printf("args sorted\n");
	temp = a;
	while (temp)
	{
		printf("%li\n", temp->nbr);
		temp = temp->next;
	}
	ft_stackclear(&a);
	return (0);
}
