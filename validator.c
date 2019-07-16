/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:27:56 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/16 15:40:11 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int     only_digits(char **str)
// {

// }

int     input_valid(int ac, char **av)
{
    int     i;
    int     j;

    i = 1;
    j = 0;
    if (ac == 2)
    {
        while (av[i][j] != '\0')
        {
            while (ft_isdigit(av[i][j]) || ft_iswhitespace(av[i][j]))
            {
                while (ft_iswhitespace(av[i][j]) || av[i][j] == '-')
                    j++;
                if (!(ft_isdigit(av[i][j])))
                    return (0);
                if (av[i][j] == '\0')
                    break ;
                j++;
            }
        }
    }
    else if (ac > 2)
    {
        while (av[i] != '\0')
        {
            j = 0;
            while (ft_isdigit(av[i][j]) && av[i][j] != '\0')
            {
                if (av[i][j] == '\0')
                    break ;
                if (!(ft_isdigit(av[i][j])))
                    return (0);
                j++;
            }
            i++;
        }
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
