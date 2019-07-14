/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:27:56 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/14 12:40:00 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     input_valid(int ac, char **av)
{
    char **args;

    if (ac == 2)
    {
        args = (char**)malloc(sizeof(char*) * (ac - 1));
        args = ft_strsplit(*av, ' ');
    }
}