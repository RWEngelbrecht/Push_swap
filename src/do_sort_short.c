/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:13:34 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/09 14:47:31 by rengelbr         ###   ########.fr       */
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

void	do_sort_five(t_stack **a, t_stack **b)
{
	int min;
	int max;

	min = find_min_max(*a, 0);
	max = find_min_max(*a, 1);
	push_min_max(a, b, min, max);
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
