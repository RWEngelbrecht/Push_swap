/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:40:13 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/12 09:37:57 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_min_max(t_stack *stack, int type)
{
	int min_max;

	min_max = stack->value;
	if (type == 0) //min
	{
		while (stack)
		{
			if (min_max > stack->value)
				min_max = stack->value;
			stack = stack->next;
		}
	}
	else if (type == 1) //max
	{
		while (stack)
		{
			if (min_max < stack->value)
				min_max = stack->value;
			stack = stack->next;
		}
	}
	return(min_max);
}

int		find_last(t_stack *stack)
{
	int ret;

	ret = 0;
	while (stack)
	{
		if (stack->next == NULL)
			ret = stack->value;
		stack = stack->next;
	}
	return (ret);
}

void	push_min_max(t_stack **a, t_stack **b, int min, int max)
{
	while (stack_len(a) > 3)
	{
		if ((*a)->value == min || (*a)->value == max)
			print_do_op("pb", a, b);
		else if ((*a)->next->value == min || (*a)->next->value == max)
			print_do_op("ra", a, b);
		else
			print_do_op("rra", a, b);
	}
}

int		find_avg(t_stack **stack)
{
	t_stack	*tmp;
	int		len;
	int		i;
	int		res;

	tmp = *stack;
	len = stack_len(&tmp);
	i = 0;
	res = 0;
	while (i < len)
	{
		res += tmp->value;
		tmp = tmp->next;
		i++;
	}
	res /= len;
	return (res);
}