/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:40:13 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/26 11:00:14 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		find_min_max(t_stack *stack, int type)
{
	int min_max;

	min_max = stack->value;
	if (type == 0)
	{
		while (stack)
		{
			if (min_max > stack->value)
				min_max = stack->value;
			stack = stack->next;
		}
	}
	else if (type == 1)
	{
		while (stack)
		{
			if (min_max < stack->value)
				min_max = stack->value;
			stack = stack->next;
		}
	}
	return (min_max);
}

int		find_pos(t_stack *stack, int val)
{
	int pos;

	pos = 1;
	while (stack)
	{
		if (stack->value == val)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

void	push_min_max_b(t_stack **a, t_stack **b, int rpt, int a_len)
{
	int i;
	int min;
	int max;

	i = 0;
	min = find_min_max(*a, 0);
	max = find_min_max(*a, 1);
	while (i < rpt)
	{
		if (find_pos(*a, min) == 1 || find_pos(*a, max) == 1)
		{
			print_do_op("pb", a, b);
			i++;
		}
		else if (find_pos(*a, min) > a_len / 2
					|| find_pos(*a, max) > a_len / 2)
			print_do_op("rra", a, b);
		else if (find_pos(*a, min) < a_len / 2
					|| find_pos(*a, max) < a_len / 2)
			print_do_op("ra", a, b);
	}
}

void	push_max_a(t_stack **b, t_stack **a, int rpt)
{
	int i;
	int max;

	i = 0;
	max = find_min_max(*b, 1);
	while (i < rpt)
	{
		if (find_pos(*b, max) == 1)
		{
			print_do_op("pa", a, b);
			i++;
			if (*b)
				max = find_min_max(*b, 1);
		}
		else if (find_pos(*b, max) > stack_len(b) / 2)
			print_do_op("rrb", a, b);
		else if (find_pos(*b, max) <= stack_len(b) / 2)
			print_do_op("rb", a, b);
	}
}
