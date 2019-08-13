/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 13:40:13 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/13 07:55:09 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Finds either min or max value of a stack.
// Set type to 0 for min, 1 for max.
// Returns an int that exists in stack
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

// Finds either min or max value's position from start of stack.
// Set type to 0 for min, 1 for max.
// Returns int that will be 1 >= n <= stack_len of stack.
int		find_min_max_pos(t_stack *stack, int type)
{
	int	pos;

	pos = 0;
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

// void	push_min_max(t_stack **a, t_stack **b, int min, int max)
// {
// 	while (stack_len(a) > 3)
// 	{
// 		if ((*a)->value == min || (*a)->value == max)
// 			print_do_op("pb", a, b);
// 		else if ((*a)->next->value == min || (*a)->next->value == max)
// 			print_do_op("ra", a, b);
// 		else
// 			print_do_op("rra", a, b);
// 	}
// }

void	push_min_max(t_stack **dst, t_stack **src, int min, int max, int stacklen)
{
	while (stack_len(dst) > stacklen - ((stacklen == 4) ? 1 : 2))
	{
		if ((*dst)->value == min || (*dst)->value == max)
			print_do_op("pb", dst, src);
		else if ((*dst)->next->value == min || (*dst)->next->value == max)
			print_do_op("ra", dst, src);
		else
			print_do_op("rra", dst, src);
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
