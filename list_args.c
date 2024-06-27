#include "push_swap.h"

int		ft_list_args(char **argv, t_stack **a)
{
    t_stack *new;
    int     i;

    new = NULL;
    while (argv[i])
    {
        while (*argv[i])
        {
            new = ft_stacknew(ft_atoi2(&*argv[i]));//need to make another t_stack var?
            if (new = NULL)
            {
                ft_stackclear(a);
                return (0);
            }
            ft_stackadd_back(a, new);
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

//checks if there if doubles in the stack, returns 1 if no
//doubles found
int ft_check_doubles (t_stack **a)
{
    int     check;
    t_stack *temp;
    t_stack *temp2;

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

//goes through every character of every arguement to check
//that each chacter is number, space, or -/+, and that if there
//is a i/+ there is a number after it
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
