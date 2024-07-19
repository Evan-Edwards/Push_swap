/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_utils_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:08:05 by eedwards          #+#    #+#             */
/*   Updated: 2024/07/19 13:49:25 by eedwards         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	least(int rarb, int rarrb, int rrarb, int rrarrb)
{
	int	least;

	least = rarb;
	if (least > rarrb)
		least = rarrb;
	if (least > rrarb)
		least = rrarb;
	if (least > rrarrb)
		least = rrarrb;
	return (least);
}

//finds the cheapest number to move as well as cheapest way to move it to from
//stack a to stack b
/* int ft_find_cheapest_ab(t_stack *a, t_stack *b)
{
    t_stack *tmp;
    int     cheapest_nbr = a->nbr;
    int     cheapest_moves = INT_MAX;

    tmp = a;
    while (tmp)
    {
        int moves_rarb = ft_moves_rarb(a, b, tmp->nbr);
        int moves_rarrb = ft_moves_rarrb(a, b, tmp->nbr);
        int moves_rrarb = ft_moves_rrarb(a, b, tmp->nbr);
        int moves_rrarrb = ft_moves_rrarrb(a, b, tmp->nbr);

        printf("Number: %ld, Moves: rarb=%d, rarrb=%d, rrarb=%d, rrarrb=%d\n", 
               tmp->nbr, moves_rarb, moves_rarrb, moves_rrarb, moves_rrarrb);

        int min_moves = least(moves_rarb, moves_rarrb, moves_rarb, moves_rrarrb);
        if (min_moves < cheapest_moves)
        {
            cheapest_moves = min_moves;
            cheapest_nbr = tmp->nbr;
        }
        tmp = tmp->next;
    }
    printf("Cheapest number to move: %d with %d moves\n", cheapest_nbr, cheapest_moves);
    return cheapest_moves;
} */


		

//finds how many moves to move a nbr from a to it's
//corect place in b using ra and rb
int	ft_moves_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_index(a, c);
	if (ft_find_place_b(b, c) > i)
		i = ft_find_place_b(b, c);
	return (i);
}

//finds how many moves to move a nbr from a to it's
//corect place in b using rra and rrb
int	ft_moves_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(a, c) != 0)
		i = ft_stacksize(a) - ft_find_index(a, c);
	if (ft_find_place_b(b, c) != 0)
	{
		if (i < ft_stacksize(b) - ft_find_place_b(b, c))
			i = ft_stacksize(b) - ft_find_place_b(b, c);
	}
	return (i);
}

//finds how many moves to move a nbr from a to it's
//corect place in b using ra and rrb
int	ft_moves_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_index(a, c) != 0)
		i = ft_stacksize(a) - ft_find_index(a, c);
	i += ft_find_place_b(b, c);
	return (i);
}

//finds how many moves to move a nbr from a to it's
//corect place in b using rra and rb
int	ft_moves_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = ft_find_index(a, c);
	if (ft_find_place_b(b, c) != 0)
		i += ft_stacksize(b) - ft_find_place_b(b, c);
	return (i);
}

int	ft_find_cheapest_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = ft_moves_rarb(a, b, a->nbr);
	while (tmp && i != 0)
	{
		if (i > ft_moves_rarb(a, b, tmp->nbr))
			i = ft_moves_rarb(a, b, tmp->nbr);
		if (i > ft_moves_rarrb(a, b, tmp->nbr))
			i = ft_moves_rarrb(a, b, tmp->nbr);
		if (i > ft_moves_rrarb(a, b, tmp->nbr))
			i = ft_moves_rrarb(a, b, tmp->nbr);
		if (i > ft_moves_rrarrb(a, b, tmp->nbr))
			i = ft_moves_rrarrb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}