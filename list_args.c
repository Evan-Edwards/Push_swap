#include "push_swap.h"

int		ft_list_args(char **argv, t_stack **a)
{
    t_stack *new;
    int     i;

    new = NULL;
    if (!(check_valid(argv)))
            return (0);
    while (argv[i])
    {
        while (*argv[i])
        {
            new = ft_stacknew(ft_atoi(&*argv[i]));
            if (new = NULL)
            {
                ft_stackclear(a);
                return (0);
            }
            if (new->nbr < (*a)->nbr) //necessary? Should be same outcome
                ft_stackadd_front(a, new);
            else
                ft_stackadd_back(a, new);
        }
        i++;
    }
    set_index(a);
    if (ft_check_doubles(a) == 0)
    {
        ft_stackclear(a);
        return (0);
    }
    return (1);
}

int ft_check_doubles (t_stack **a)
{
    int     check;
    t_stack *temp;
    t_stack *temp2;

    temp = *a;
    while (temp)
    {
        check = temp->nbr;
        temp2 = *a;
        while (temp2)//also check it's not the same index
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

int	ft_atoi2(char **str)
{
    long	result;
    long	check;
    int		sign;

    sign = 1;
    result = 0;
    while (ft_isspace(**str) == 1)
        (*str)++;
    if (**str == '-' || **str == '+')
    {
        if (**str == '-')
            sign *= -1;
        (*str)++;
    }
    while (**str >= '0' && **str <= '9' && **str)
    {
        check = result;
        result = result * 10 + **str - '0';
        if (result / 10 != check && sign < 0)
            return (0);
        if (result / 10 != check && sign > 0)
            return (-1);
        (*str)++;
    }
    return ((int)(result * sign));
}

//check that number, space, or -/+
int    check_valid(char **arg)
{
    int i;
    int j;

    i = 0;
    while (arg[i])
    {
        j = 0;
        while ((arg[i])[j])
        {
            if ((ft_isdigit((arg[i])[j]) == 1) || ft_isspace((arg[i])[j] == 1)
            || ((arg[i])[j] == '-' || (arg[i])[j]== '+'))
            {
                if (((arg[i])[j] == '-' || (arg[i])[j] == '+') && 
                (ft_isdigit((arg[i])[j]) != 1))
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
