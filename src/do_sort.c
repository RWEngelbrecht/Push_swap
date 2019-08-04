/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:13:34 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/02 18:08:43 by rengelbr         ###   ########.fr       */
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

#include <stdio.h>
void	do_sort_three(t_stack **stack_a, t_stack **stack_b)
{
	int a;
	int b;
	int c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	printf("a%i b%i c%i\n", a, b, c);
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

int find_min_max(t_stack **stack, int type)
{
	int min_max;

	min_max = (*stack)->value;
	if (type == 1) //max
	{
		while (*stack)
		{
			if (min_max > (*stack)->value)
				min_max = (*stack)->value;
			*stack = (*stack)->next;
		}
		return (min_max);
	}
	else if (type == 0) //min
	{
		while (*stack)
		{
			if (min_max < (*stack)->value)
				min_max = (*stack)->value;
			*stack = (*stack)->next;
		}
		return (min_max);
	}
	return(0);
}

void	do_sort_five(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int first;
	int second;
	int last;

	print_do_op("pb", a, b);
	if (!is_sorted((*a)->next))
		do_sort_three(&(*a)->next, b);
	int i = 2;
	while (i > 0)
	{
		tmp = *a;
		first = tmp->value;
		second = tmp->next->value;
		while (tmp)
		{
			if (tmp->next == NULL)
				last = tmp->value;
			tmp = tmp->next;
		}
		printf("1st:%i 2nd:%i last:%i\n", first, second, last);
		tmp = *a;
		if (first > second && first < last && first < (*a)->next->next->value)
			print_do_op("sa", a, b);
		else if (first > last)
			print_do_op("ra", a, b);
		else if (stack_len(a) == 4 &&
					first > (*a)->next->next->value && first < last)
		{
			print_do_op("rra", a, b);
			print_do_op("sa", a, b);
			print_do_op("ra", a, b);
			print_do_op("ra", a, b);
		}
		else if (stack_len(a) == 5 &&
					first < (*a)->next->next->next->value && first < last)
		{
			print_do_op("sa", a, b);
			print_do_op("ra", a, b);
			print_do_op("sa", a, b);
			print_do_op("rra", a, b);
		}
		else if (stack_len(a) == 5 &&
					first > (*a)->next->next->next->value && first < last)
		{
			print_do_op("rra", a, b);
			print_do_op("sa", a, b);
			print_do_op("ra", a, b);
			print_do_op("ra", a, b);
		}
		if (*b)
			print_do_op("pa", a, b);
		i--;
	}
}
/*
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
}*/