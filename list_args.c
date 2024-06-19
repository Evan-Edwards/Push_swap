#include "push_swap.h"

int		list_args(char **argv, t_stack **a)
{
    t_stack *temp;

    temp = *a;
    while (*argv)
    {
        if (!(check_valid(*argv))) //change to atoi?
            return (0);
        if (ft_check_doubles() == 0)
            return (0);
        (*a)->nbr = 
        
    }
    
}

int ft_check_doubles (t_stack **a)
{
    int     check;
    t_stack *temp;
    t_stack *temp2;

    temp = *a;
    temp2 = *a;
    while (temp->next)
    {
        check = temp->nbr;
        while (temp2->next && )
        {
            if (temp->index == temp2->index)
                temp2 = temp2->next;
            if (temp2->nbr == check)
                return (0);
            if (temp->next)
                temp2 = temp2->next;
        }
    }
    return (1);
}

//need to also check that works with single string of numbers
//also can have space, -, or + in front
//make characters into numbers (atoi)

int	ft_atoi(const char *str)
{
	long	result;
	long	check;
	int		sign;

	sign = 1;
	result = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
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

int    check_valid(char *arg)
{
    int i;

    while (arg[i])
    {
        if (arg[i] < '0' || arg[i] > '9')
            return (0);
        i++;
    }
    return (1);
    //check that number
}