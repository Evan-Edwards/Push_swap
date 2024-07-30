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