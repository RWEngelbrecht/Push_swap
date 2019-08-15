/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:13:34 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/15 14:03:42 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
void	do_sort_five(t_stack **a, t_stack **b)
{
	int		first;
	int		second;
	int		last;

	print_do_op("pb", a, b);
	print_do_op("pb", a, b);
	if (!is_sorted(*a))
		do_sort_three(&(*a), b);
	while (!is_sorted(*a) || *b)
	{
		first = (*a)->value;
		second = (*a)->next->value;
		last = find_last(*a);
		if (first > second && first < last && first < (*a)->next->next->value)
			print_do_op("sa", a, b);
		else if (first > last)
			print_do_op("ra", a, b);
		else if (stack_len(a) == 4 &&
					first > (*a)->next->next->value && first < last) //first < last
			do_sort_5_sub1(a, b);
		else if (stack_len(a) == 5 && first < (*a)->next->next->next->value && first < last) // first < last
			do_sort_5_sub2(a, b);
		else if (stack_len(a) == 5 && first > (*a)->next->next->next->value && first < last) //first < last
			do_sort_5_sub1(a, b);
		if (*b)
			print_do_op("pa", a, b);
	}
}
*/

void	do_sort_three(t_stack **stack_a, t_stack **stack_b)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && a < c)
		print_do_op("sa", stack_a, stack_b);
	else if (a > b && b > c)
	{
		print_do_op("sa", stack_a, stack_b);
		print_do_op("rra", stack_a, stack_b);
	}
	else if (a > b && b < c)
		print_do_op("ra", stack_a, stack_b);
	else if (a < b && a < c && b > c)
	{
		print_do_op("sa", stack_a, stack_b);
		print_do_op("ra", stack_a, stack_b);
	}
	else if (a < b && a > c && b > c)
		print_do_op("rra", stack_a, stack_b);
}

void	do_sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	max;

	min = find_min_max(*a, 0);
	max = find_min_max(*a, 1);
	push_min_max_b(a, b, 2, stack_len(a));
	if (!is_sorted(*a))
		do_sort_three(a, b);
	while (*b)
	{
		if ((*b)->value == max)
		{
			print_do_op("pa", a, b);
			print_do_op("ra", a, b);
		}
		else if ((*b)->value == min)
			print_do_op("pa", a, b);
	}
}
