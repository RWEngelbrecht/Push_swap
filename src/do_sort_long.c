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

/**
 ***				THE DO_SORT GRAVEYARD			***
void	sortedInsert(t_stack **head, t_stack *new_head)
{
	t_stack *current;

	if (*head == NULL || (*head)->value >= new_head->value)
	{
		new_head->next = *head;
		*head = new_head;
	}
	else
	{
		// find the location before the point of insertion
		current = *head;
		while(current->next != NULL && current->next->value < new_head->value)
		{
			current = current->next; // point to next
		}
		new_head->next = current->next;
		current->next = new_head;
	}
}

void	insertionSort(t_stack **head)
{
	t_stack *sorted = NULL;
	t_stack *current = *head;
	t_stack *next;

	while (current != NULL)
	{
		next = current->next;
		sortedInsert(&sorted, current);
		current = next;
	}
	*head = sorted;
}

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
*/
/**
 ** PROBABLY DON'T NEED THIS **
 */
// //Finds first occurance of any int between r_min and r_max, inclusive, in stack,
// //starting at node number s_pos.
// int		find_in_range_pos(t_stack *stack, int r_min, int r_max, int s_pos)
// {
// 	while (s_pos <= stack_len(&stack) &&
// 			!(stack->value >= r_min && stack->value <= r_max))
// 	{
// 		s_pos++;
// 		stack = stack->next;
// 	}
// 	return (s_pos);
// }

// //Finds, in range min to max, the current lowest or highest int value
// int		find_min_max_range(t_stack *stack, int r_min, int r_max, int type)
// {
// 	int min_max;

// 	min_max = 0;
// 	if (type == 0)
// 	{
// 		while (!(stack->value >= r_min && stack->value <= r_max))
// 			stack = stack->next;
// 		min_max = stack->value;
// 		while (stack)
// 		{
// 			if (stack->value >= r_min && stack->value <= r_max
// 					&& stack->value < min_max)
// 				min_max = stack->value;
// 			stack = stack->next;
// 		}
// 	}
// 	else if (type == 1)
// 	{
// 		while (!(stack->value >= r_min && stack->value <= r_max))
// 			stack = stack->next;
// 		min_max = stack->value;
// 		while (stack)
// 		{
// 			if (stack->value >= r_min && stack->value <= r_max
// 					&& stack->value > min_max)
// 				min_max = stack->value;
// 			stack = stack->next;
// 		}
// 	}
// 	return (min_max);
// }

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
			// else if (find_in_range_pos(*a, find_min_max_range(*a, r_max - 20, r_max, 0), r_max, i) <= stack_len(a) / 2)
			// 	print_do_op("ra", a, b);
			// else if (find_in_range_pos(*a, find_min_max_range(*a, r_max-20, r_max, 0), r_max, i) > stack_len(a) / 2)
			// 	print_do_op("rra", a, b);
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
