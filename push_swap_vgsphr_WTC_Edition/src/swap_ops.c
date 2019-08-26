/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:38:39 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/26 13:24:27 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **b)
{
	t_stack *tmp;

	if (*b && (*b)->next != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
	}
	else
		return ;
}

void	swap_both(t_stack **a, t_stack **b)
{
	if (*a && *b)
	{
		swap(a);
		swap(b);
	}
	else
		return ;
}
