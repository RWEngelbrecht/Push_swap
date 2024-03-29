/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:15:15 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/26 11:00:40 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (!*a)
		return ;
	if ((*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next != NULL)
		last = last->next;
	(*a) = first->next;
	first->next = NULL;
	last->next = first;
}

void	rot_both(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		rotate(a);
		rotate(b);
	}
}

void	rev_rot(t_stack **a)
{
	t_stack	*scnd_last;
	t_stack	*last;

	if (!*a)
		return ;
	if ((*a)->next == NULL)
		return ;
	scnd_last = NULL;
	last = *a;
	while (last->next != NULL)
	{
		scnd_last = last;
		last = last->next;
	}
	scnd_last->next = NULL;
	last->next = *a;
	*a = last;
}

void	rev_rot_both(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		rev_rot(a);
		rev_rot(b);
	}
}
