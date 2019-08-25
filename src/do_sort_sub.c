/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:40:13 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/25 08:46:04 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
** Finds either min or max value of a stack.
** Set type to 0 for min, 1 for max.
** Returns an int that exists in stack
*/

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

/**
** Finds either min or max value's position from start of stack.
** Set type to 0 for min, 1 for max.
** Returns int that will be 1 >= n <= stack_len of stack.
*/

int		find_min_max_pos(t_stack *stack, int type)
{
	int	pos;

	pos = 1;
	if (type == 0)
	{
		while (stack->value != find_min_max(stack, 0))
		{
			stack = stack->next;
			pos++;
		}
	}
	else if (type == 1)
	{
		while (stack->value != find_min_max(stack, 1))
		{
			stack = stack->next;
			pos++;
		}
	}
	return (pos);
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

/**
** Pushes min/max in 'a' to 'b' 'rpt' amount of times.
*/

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

/**
** Pushes max value in 'b' to 'a' 'rpt' amount of times.
*/

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
