/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:52:01 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/16 14:04:35 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_sort_fifty(t_stack **a, t_stack **b)
{
	int r_max;
	int i;

	r_max = 0;
	i = 1;
	while (*a)
	{
		r_max += 13;
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

void	do_sort_hundred(t_stack **a, t_stack **b)
{
	int r_max;
	int i;

	r_max = 0;
	i = 1;
	while (*a)
	{
		r_max += 15;
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

void	do_sort_250(t_stack **a, t_stack **b)
{
	int r_max;
	int i;

	r_max = 0;
	i = 1;
	while (*a)
	{
		r_max += 30;
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

void	do_sort_500(t_stack **a, t_stack **b)
{
	int r_max;
	int i;

	r_max = 0;
	i = 1;
	while (*a)
	{
		r_max += 44;
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

void	do_sort_large(t_stack **a, t_stack **b)
{
	int r_max;
	int i;

	r_max = 0;
	i = 1;
	while (*a)
	{
		r_max += 50;
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
