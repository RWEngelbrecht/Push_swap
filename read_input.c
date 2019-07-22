/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:35:11 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/22 09:32:12 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    read_input(t_stack **a, t_stack **b, char **line)
{
    while (get_next_line(0, line))
    {
        if (checkline(*line))
        {
            do_op(*line, a, b);
            free(*line);
            return (1);
        }
        else if (!(checkline(*line)))
        {
            free(*line);
            //free stack
            ft_putstr_fd("Error\n", 2);
        }
    }
    return (0);
}
