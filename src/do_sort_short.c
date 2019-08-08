/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:13:34 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/08 14:28:00 by rengelbr         ###   ########.fr       */
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
*/
int find_min_max(t_stack *stack, int type)
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
		return (min_max);
	}
	else if (type == 1) //max
	{
		while (stack)
		{
			if (min_max < stack->value)
				min_max = stack->value;
			stack = stack->next;
		}
		return (min_max);
	}
	return(0);
}

void	do_sort_three(t_stack **stack_a, t_stack **stack_b)
{
	int a;
	int b;
	int c;

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

void	do_sort_5_sub1(t_stack **a, t_stack **b)
{
	print_do_op("rra", a, b);
	print_do_op("sa", a, b);
	print_do_op("ra", a, b);
	print_do_op("ra", a, b);
}

void    do_sort_5_sub2(t_stack **a, t_stack **b)
{
	print_do_op("sa", a, b);
	print_do_op("ra", a, b);
	print_do_op("sa", a, b);
	print_do_op("rra", a, b);
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
void	do_sort_five(t_stack **a, t_stack **b)
{
	int min;
	int max;

	min = find_min_max(*a, 0);
	max = find_min_max(*a, 1);
	while (stack_len(a) > 3)
	{
		if ((*a)->value == min || (*a)->value == max)
			print_do_op("pb", a, b);
		else if ((*a)->next->value == min || (*a)->next->value == max)
			print_do_op("ra", a, b);
		else if (find_last(*a) == min || find_last(*a) == max)
			print_do_op("rra", a, b);
		else
			print_do_op("rra", a, b);
	}
	if (!is_sorted(*a))
		do_sort_three(a, b);
	while (!is_sorted(*a) || *b)
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
