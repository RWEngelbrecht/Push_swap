/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:27:12 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/25 11:31:01 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_op(char *line)
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

int			checkline(char *line)
{
	if (!line)
		return (0);
	if (!(check_op(line)))
		return (0);
	return (1);
}

void		do_op(char *line, t_stack **a, t_stack **b)
{
	if (ft_strequ(line, "sa"))
		swap(a);
	else if (ft_strequ(line, "sb"))
		swap(b);
	else if (ft_strequ(line, "ss"))
		swap_both(a, b);
	else if (ft_strequ(line, "pa"))
		push_to(a, b);			//////
	else if (ft_strequ(line, "pb"))
		push_to(b, a);			//////
	else if (ft_strequ(line, "ra"))
		rotate(a);
	else if (ft_strequ(line, "rb"))
		rotate(b);
	else if (ft_strequ(line, "rr"))
		rot_both(a, b);
	else if (ft_strequ(line, "rra"))
		rev_rot(a);
	else if (ft_strequ(line, "rrb"))
		rev_rot(b);
	else if (ft_strequ(line, "rrr"))
		rev_rot_both(a, b);
}

void		print_do_op(char *op, t_stack **a, t_stack **b)
{
	ft_putendl_fd(op, 1);
	do_op(op, a, b);
}

