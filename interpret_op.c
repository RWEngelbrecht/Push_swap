/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:27:12 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/14 10:43:36 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     check_op(char *line)
{
    if (ft_strequ(line, "sa") || ft_strequ(line, "sb"))
        return (1);
    else if (ft_strequ(line, "pa") || ft_strequ(line, "pb"))
        return (1);
    else if (ft_strequ(line, "ss"))
        return (1);
    else if (ft_strequ(line, "ra") || ft_strequ(line, "rb"))
        return (1);
    else if (ft_strequ(line, "rr") || ft_strequ(line, "rrr"))
        return (1);
    else if (ft_strequ(line, "rra") || ft_strequ(line, "rrb"))
        return (1);
    return (0);
}

int     checkline(char *line)
{
    if (!line)
        return (0);
    if (!(check_op(line)))
        return (0);
    return (1);
}

void    do_op(char *line, t_stack **a, t_stack **b)
{
    if (ft_strequ(line, "sa"))
        ft_swap(a);
    else if (ft_strequ(line, "sb"))
        ft_swap(b);
    else if (ft_strequ(line, "ss"))
        ft_swap_both(a, b);
    else if (ft_strequ(line, "pa"))
        ft_push_to(a, b);
    else if (ft_strequ(line, "pb"))
        ft_push_to(b, a);
    else if (ft_strequ(line, "ra"))
        ft_rotate(a);
    else if (ft_strequ(line, "rb"))
        ft_rotate(b);
    else if (ft_strequ(line, "rr"))
        ft_rot_both(a, b);
    else if (ft_strequ(line, "rra"))
        ft_rev_rot(a);
    else if (ft_strequ(line, "rrb"))
        ft_rev_rot(b);
    else if (ft_strequ(line, "rrr"))
        ft_rev_rot_both(a, b);
}