/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:34:41 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/20 13:45:07 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			*get_order(t_stack **stack)
{
	t_stack *s_tmp;
	t_stack	*tmp;
	int		*order;
	int		count;
	int		i;

	s_tmp = *stack;
	order = (int*)malloc(sizeof(int) * stack_len(stack));
	i = -1;
	while (s_tmp)
	{
		tmp = *stack;
		count = 1;
		while (tmp)
		{
			if (s_tmp->value > tmp->value)
				count++;
			tmp = tmp->next;
		}
		order[++i] = count;
		s_tmp = s_tmp->next;
	}
	free(tmp);
	free(s_tmp);
	return (order);
}

t_stack		*normalize(t_stack **stack)
{
	t_stack	*ret;
	int		*order;
	int		i;

	i = stack_len(stack) - 1;
	order = get_order(stack);
	ret = malloc(sizeof(t_stack));
	stack_new(&ret, order[i--]);
	while (i >= 0)
		push(&ret, order[i--]);
	free(order);
	return (ret);
}
