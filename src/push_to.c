/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:37:18 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/23 13:47:32 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * 		Work with next ptrs instead of this
 */

// void	push_to(t_stack **dst, t_stack **src)
// {
// //	t_stack *p_node;

// 	if (!(*src))
// 		return ;
// //	p_node = malloc(sizeof(t_stack));
// //	p_node->value = pop(src);
// 	if (!(*dst))
// 		stack_new(dst, pop(src));
// //		p_node->next = NULL;
// 	else
// 		push(dst, pop(src));
// //		p_node->next = *dst;
// //	*dst = p_node;
// //	free(p_node);
// }

void	push_to(t_stack **dst, t_stack **src)		////
{
	t_stack *d_curr;
	t_stack *s_curr;
	t_stack *s_next;
//	t_stack *d_next;

	if (!*src)
		return ;
	d_curr = NULL;
	// d_next = NULL;
	s_curr = *src;
	s_next = s_curr->next;
	if (*dst)						/////
	{
		d_curr = *dst;
		s_curr->next = d_curr;			////
		*dst = s_curr;
		s_curr = s_next;
		*src = s_curr;
	}
	else
		*dst = stack_new(pop(src));		////
}
