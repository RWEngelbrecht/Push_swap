/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 10:35:11 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/12 10:57:12 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    read_input(t_stack *a, t_stack *b, char **line)
{
    while (get_next_line(0, line))
    {
        if (checkline(*line))
        {
            do_op(*line, &a, &b);
            free(*line);
        }
        else if (!(checkline(*line)))
        {
            free(*line);
            //free stack
            ft_putstr_fd("ERROR\n", 2);
        }
    }
}