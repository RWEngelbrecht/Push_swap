/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:52:01 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/13 14:34:22 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

/*
void	do_sort_hundred(t_stack **a, t_stack **b, int div)
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
	len = stack_len(a);
printf("len = %d\n", len);
	cur_min = find_min_max(*a, 0);
printf("cur_min = %d\n", cur_min);
	cur_max = (len >= 60) ? len / div : len * div;
printf("cur_max = %d\n", cur_max);
	i = 1;
	while (*a)
	{
		while (tmp && i <= len / 2)					//check from top
		{
			if (tmp->value >= cur_min && tmp->value <= cur_max)
			{
				cur1 = tmp->value;	//set first value found in current range
				dis1 = i;			//the amnt of nodes from the begining
				break ;
			}
			tmp = tmp->next;
			i++;
		}
		while (tmp && i <= len)					//check from bottom
		{
			if (tmp->value >= cur_min && tmp->value <= cur_max)
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
					if (find_min_max_pos(*b, 1) > (stack_len(b) / 2))//if min is
						print_do_op("rrb", a, b);					//in lower
					else
						print_do_op("rb", a, b);
				}
				print_do_op("pb", a, b);
				if ((*b)->value < (*b)->next->value)
					print_do_op("sb", a, b);
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
					if (find_min_max_pos(*b, 1) > (stack_len(b) / 2))	//if min is
						print_do_op("rrb", a, b);						//in lower
					else
						print_do_op("rb", a, b);
				}
				print_do_op("pb", a, b);
				if ((*b)->value < (*b)->next->value)
					print_do_op("sb", a, b);
			}
		}
		if (stack_len(b) == cur_max)
		{
			if (len == 80)
				do_sort_hundred(a, b, 2);
			else if (len == 60)
				do_sort_hundred(a, b, 1);
			else if (len == 40)
				do_sort_hundred(a, b, 2);
			else if (len == 20)
				do_sort_hundred(a, b, 5);
		}
	}
}
*/

//Finds first occurance of any int between min and max, inclusive, in stack,
//starting at node number s_pos.
int find_in_range_pos(t_stack *stack, int min, int max, int s_pos)
{
	while (s_pos <= stack_len(&stack) &&
			!(stack->value >= min && stack->value <= max))
	{
		s_pos++;
		stack = stack->next;
	}
	return (s_pos);
}
//Finds, in range min to max, the current lowest or highest int value
int find_min_max_range(t_stack *stack, int min, int max, int type)
{
	int min_max;

	min_max = 0;
	if (type == 0)
	{
		while (!(stack->value >= min && stack->value <= max))
			stack = stack->next;
		min_max = stack->value;
		while (stack)
		{
			if (stack->value >= min && stack->value <= max
					&& stack->value < min_max)
				min_max = stack->value;
			stack = stack->next;
		}
	}
	else if (type == 1)
	{
		while (!(stack->value >= min && stack->value <= max))
			stack = stack->next;
		min_max = stack->value;
		while (stack)
		{
			if (stack->value >= min && stack->value <= max
					&& stack->value > min_max)
				min_max = stack->value;
			stack = stack->next;
		}
	}
	return (min_max);
}

void	do_sort_hundred(t_stack **a, t_stack **b, int div)
{
	int cur_min;
	int cur_max;
	int pos_first;
	int pos_last;
	int len;
	int i;

	len = stack_len(a);
	cur_min = find_min_max(*a, 0);
	cur_max = (len >= 60) ? len / div : len * div; //max value of this iteration
// printf("len = %d\ncur_min = %d\ncur_max = %d\n", len, cur_min, cur_max);
	i = 1;
	while (*a)
	{
		pos_first = find_in_range_pos(*a, cur_min, cur_max, 1);
		pos_last = find_in_range_pos(*a, cur_min, cur_max, (len / 2 + 1));
// printf("pos_first = %d\npos_last = %d\n", pos_first, pos_last);
//		tmp = *a;
//		i = 1;						//IS THIS NEEDED NOW?
		//(val frm current range closer to top than bottom) ? pos_first : pos_last
		if (pos_first <= len - pos_last)
		{
	//		i = 1;
			while (i < pos_first)
			{
				print_do_op("ra", a, b);
				i++;
			}
			if (stack_len(b) == 0)
				print_do_op("pb", a, b);
			else
			{
				while ((*b)->value != find_min_max_range(*b, cur_min, cur_max, 1)) //NO! check if value about to push over is bigger or smaller than all others
				{
					if (find_in_range_pos(*b, cur_min, cur_max, 1) >
							(stack_len(b) / 2))
					{
						while ((*b)->value != find_min_max_range(*b, cur_min, cur_max, 1))
							print_do_op("rrb", a, b);
					}
					else
					{
						while ((*b)->value != find_min_max_range(*b, cur_min, cur_max, 1))
							print_do_op("rb", a, b);
					}
				}
				print_do_op("pb", a, b);
				if ((*b)->value < (*b)->next->value)
					print_do_op("sb", a, b);
			}
		}
		else if (pos_first > len - pos_last)
		{
	//		i = (len / 2 + 1);
			while (i < len - pos_last)
			{
				print_do_op("rra", a, b);
				i++;
			}
			if (stack_len(b) == 0)
				print_do_op("pb", a, b);
			else
			{
				while ((*b)->value != find_min_max_range(*b, cur_min, cur_max, 1))//NO! check if value about to push over is bigger or smaller than all others
				{
					if (find_in_range_pos(*b, cur_min, cur_max, 1) >
							(stack_len(b) / 2))
					{
						while ((*b)->value != find_min_max_range(*b, cur_min, cur_max, 1))
							print_do_op("rrb", a, b);
					}
					else
					{
						while ((*b)->value != find_min_max_range(*b, cur_min, cur_max, 1))
							print_do_op("rb", a, b);
					}
				}
				print_do_op("pb", a, b);
//				if ((*b)->value < (*b)->next->value)
//					print_do_op("sb", a, b);
			}
		}
		if (stack_len(b) == cur_max)
		{
			if (len == 80)
				do_sort_hundred(a, b, 2);
			else if (len == 60)
				do_sort_hundred(a, b, 1);
			else if (len == 40)
				do_sort_hundred(a, b, 2);
			else if (len == 20)
				do_sort_hundred(a, b, 5);
		}
	}
}
