/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:27:56 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/18 16:15:57 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     only_digits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_iswhitespace(*str))
			return (0);
		str++;
	}
	return (1);
}

int     dup_check(int ac, char **av)
{
    char **str;
    int i;
    int j;

    i = 1;
    str = NULL;
    if (ac == 2)
    {
        str = ft_strsplit(av[1], ' ');
        i = 0;
    }
    else
        str = av;
    while (str[i])
    {
        j = 1;
        while (str[i + j] != '\0')
        {
            if (ft_strequ(str[i], str[i + j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

// int     over_minmax(char **av)
// {
//     char *min;
//     char *max;

//     min = "-2147483649";
//     max = "2147483648";
//     while 
// }

int     input_valid(int ac, char **av)
{
    if (ac == 2)
    {
        if (!only_digits(av[1]))
			return (0);
        if (!dup_check(ac, av))
            return (0);
    }
    else if (ac > 2)
    {
        int     i;

        i = 1;
        while (av[i])
        {
            if(!only_digits(av[i]))
                return (0);
            i++;
        }
        if (!dup_check(ac, av))
            return (0);
    }
    return (1);
}

int     is_sorted(t_stack *a)
{
    int temp;

    if (!a)
        return (0);
    while (a->next)
    {
        temp = a->value;
        a = a->next;
        if (temp > a->value && a)
            return (0);
    }
    return (1);
}
