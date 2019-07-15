/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:27:56 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/15 16:18:33 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     input_valid(int ac, char **av)
{
    char    **args;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (ac == 2)
    {
        args = (char**)malloc(sizeof(char*) * (ft_wordcount(*av, ' ')));
        args = ft_strsplit(*av, ' ');
        while (ft_isdigit(args[i][j]))
        {
            j = 0;
            while (ft_isdigit(args[i][j]) && args[i][j] != '\0')
            {
                j++;
                if (!(*args))
                    return (0);
            }
            i++;
        }
    }
    else if (ac > 2)
    {
        while (ft_isdigit(av[i][j]))
        {
            j = 0;
            while (ft_isdigit(av[i][j]) && av[i][j] != '\0')
            {
                j++;
                if (!(ft_isdigit(av[i][j])))
                    return (0);
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