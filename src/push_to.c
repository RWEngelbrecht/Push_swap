/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:37:18 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/26 14:47:04 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to(t_stack **dst, t_stack **src)
{
	t_stack *p_node;

	if (!(*src))
		return ;
	p_node = malloc(sizeof(t_stack));
	p_node->value = pop(src);
	if (!(*dst))
		p_node->next = NULL;
	else
		p_node->next = *dst;
	*dst = p_node;
}

