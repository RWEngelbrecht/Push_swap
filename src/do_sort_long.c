/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:52:01 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/12 15:53:43 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
/*
void	do_sort_hundred(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int cur1;
	int cur2;
	int cur_min;
	int cur_max;
	int dis1;
	int dis2;
	int len;
	int i;

	tmp = *a;
	cur_min = 1;
	cur_max = 20;
	dis1 = 0;
	dis2 = 0;
	len = stack_len(&tmp);
	i = 1;
	while (tmp)					//check from top
	{
		if (tmp->value >= cur_min && tmp->value <= cur_max && i <= len / 2)
		{
			cur1 = tmp->value;	//set first value found in current range
			dis1 = i;			//the amnt of nodes from the begining
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	while (tmp)					//check from bottom
	{
		if (tmp->value >= cur_min && tmp->value <= cur_max && i <= len)
		{
			cur2 = tmp->value;
			dis2 = len - i;
		}
		tmp = tmp->next;
		i++;
	}
	tmp = *a;
	i = 1;						//IS THIS NEEDED NOW?
	//(val frm current range closer to top than bottom) ? dis1 : dis2
	if (((len / 2) - dis1) > (len - dis2))
	{
		while (tmp->value != cur1)
			print_do_op("ra", a, b);
		if (stack_len(b) == 0)
			print_do_op("pb", a, b);
		else
		{
			while ((*b)->value != find_min_max(*b, 0))
			{
				if (find_min_max_pos(*b, 0) > (stack_len(b) / 2))
					print_do_op("rrb", a, b);
				else
					print_do_op("rb", a, b);
			}
			print_do_op("pb", a, b);
		}
	}
	if (stack_len(a) > stack_len(b))
		do_sort_hundred(a, b);
}
*/
#include <stdio.h>
void	do_sort_hundred(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int cur1;
	int cur2;
	int cur_min;
	int cur_max;
	int dis1;
	int dis2;
	int len;
	int i;

	tmp = *a;
	dis1 = 0;
	dis2 = 0;
	len = stack_len(&tmp);
	cur_min = find_min_max(tmp, 0);
	cur_max = find_min_max(tmp, 1);
	i = 0;
	while (tmp && i <= len / 2)					//check from top
	{
		if ((tmp->value == cur_min || tmp->value == cur_max) && i <= len / 2)
		{
			cur1 = tmp->value;	//set first value found in current range
			dis1 = i;			//the amnt of nodes from the begining
//printf("\n%d\n", cur1);
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	while (tmp && i < len)					//check from bottom
	{
		if ((tmp->value == cur_min || tmp->value == cur_max) && i <= len)
		{
			cur2 = tmp->value;
			dis2 = len - i;
//printf("\n%d\n", cur2);
		}
		tmp = tmp->next;
		i++;
	}
//	tmp = *a;
//	i = 1;						//IS THIS NEEDED NOW?
	//(val frm current range closer to top than bottom) ? dis1 : dis2
	if (dis1 <= dis2)
	{
		while ((*a)->value != cur1)
			print_do_op("ra", a, b);
		if (stack_len(b) == 0)
			print_do_op("pb", a, b);
		else
		{
			while ((*b)->value != find_min_max(*b, 1))
			{
				if (find_min_max_pos(*b, 1) > (stack_len(b) / 2))
					print_do_op("rrb", a, b);
				else
					print_do_op("rb", a, b);
			}
			print_do_op("pb", a, b);
		}
	}
	else if (dis1 > dis2)
	{
		while ((*a)->value != cur2)
			print_do_op("rra", a, b);
		if (stack_len(b) == 0)
			print_do_op("pb", a, b);
		else
		{
			while ((*b)->value != find_min_max(*b, 1))
			{
				if (find_min_max_pos(*b, 1) > (stack_len(b) / 2))
					print_do_op("rrb", a, b);
				else
					print_do_op("rb", a, b);
			}
			print_do_op("pb", a, b);
		}
	}
	if (stack_len(a) > stack_len(b))
		do_sort_hundred(a, b);
}
