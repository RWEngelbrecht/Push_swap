/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:13:34 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/02 13:21:25 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* 
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
*/ /* 
#include <stdio.h>
void	quicksort(int len, t_stack **a,t_stack **b)
{
	int half_len;
	int avg;
	int i;
//	int j;

	half_len = len / 2;
	avg = find_avg(a);
	printf("%i\n", avg);
	i = 0;
	if (len == 1)
		return ;
	while (i < len)
	{
		if ((*a)->value <= avg)
		{
			print_do_op("pb", a, b);
		}
		print_do_op("ra", a, b);
		i++;
	}
	while (*b)
	{
		
	}
}*/

t_stack		*normalize(t_stack **stack)
{
	t_stack *s_tmp;
	t_stack *tmp;
	t_stack *ret;
	int *order;
	int count;
	int i;

	s_tmp = *stack;
	order = (int*)malloc(sizeof(int) * stack_len(stack));
	i = -1;
	while (s_tmp)
	{
		tmp = *stack;
		count = 1;
		while (tmp)
		{
			if (s_tmp->value > tmp->value)
				count++;
			tmp = tmp->next;
		}
		order[++i] = count;
		s_tmp = s_tmp->next;
	}
	ret = malloc(sizeof(t_stack));
	stack_new(&ret, order[i--]);
	while (i >= 0)
		push(&ret, order[i--]);
	return (ret);
}

void	do_sort_three(t_stack **a, t_stack **b)
{
	int i;

	i = 0;
	if (order[i] > order[i + 1] && order[i] < order[i + 2])
		print_do_op("sa", a, b);
	else if (order[i] > order[i + 1] &&
				order[i + 1] > order[i + 2])
	{
		print_do_op("sa", a, b);
		print_do_op("rra", a, b);
	}
	else if (order[i] > order[i + 1] &&
				order[i + 1] < order[i + 2])
		print_do_op("ra", a, b);
	else if (order[i] < order[i + 1] &&
				order[i] < order[i + 2])
	{
		print_do_op("sa", a, b);
		print_do_op("ra", a, b);
	}
	else if (order[i] < order[i + 1] &&
				order[i] > order[i + 2])
		print_do_op("rra", a, b);
}
/*
void	do_sort_five(t_stack **a, t_stack **b, int *order)
{
	int i;
	int j;
	int max;
	int min;

	i = 0;
	j = stack_len(a);
	max = order[i];
	while (order[i])
	{
		if (order[i] > max)
		{
			max = order[i];
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	min = order[i];
	while (order[i])
	{
		if (order[i] < min)
		{
			min = order[i];
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (stack_len(b) < 2)
	{
		if (order[i] < max && order[i] <= (min + 1))
		{
			print_do_op("pb", a, b);
			i++;
		}
		else
		{
			print_do_op("ra", a, b);
			i++;
		}
	}
	do_sort_three(a, b, &(order[2]));
}
*/
//DOESN'T ACCOUNT FOR STACK LEN CHANGES 
void	do_sort_five(t_stack **a, t_stack **b) 
{
	print_do_op("pb", a, b);
	print_do_op("pb", a, b);
	if (!is_sorted(*a))
		do_sort_three(a, b);
	while (*b != NULL)
	{
		if ((*b)->value < (*a)->value)
		{
			print_do_op("pa", a, b);
		}
		else if ((*b)->value < (*a)->next->value)
		{
			print_do_op("pa", a, b);
			print_do_op("sa", a, b);
		}
		else if ((*b)->value >
					(*a)->next->next->next->value ||
						(*b)->value > (*a)->next->next->value)
		{
			print_do_op("pa", a, b);
			print_do_op("ra", a, b);
		}
		else if ((*b)->value > (*a)->next->value &&
					((*b)->value < (*a)->next->next->next->value ||
						(*b)->value < (*a)->next->next->value))
		{
			print_do_op("pa", a, b);
			print_do_op("rra", a, b);
			print_do_op("sa", a, b);
			print_do_op("ra", a, b);
			print_do_op("ra", a, b);
		}
	}
}