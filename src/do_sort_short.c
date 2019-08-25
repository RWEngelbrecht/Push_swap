/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:13:34 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/25 08:30:31 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_sort_two(t_stack **a, t_stack **b)
{
	if ((*a)->value > (*a)->next->value)
		print_do_op("sa", a, b);
}

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

void	do_sort_twenty(t_stack **a, t_stack **b)
{
	int r_max;
	int i;

	r_max = 0;
	i = 1;
	while (*a)
	{
		r_max += 5;
		while (i <= r_max)
		{
			if (!(*a))
				break ;
			if ((*a)->value <= r_max)
			{
				print_do_op("pb", a, b);
				i++;
			}
			else
				print_do_op("ra", a, b);
		}
	}
	i--;
	push_max_a(b, a, i);
}
