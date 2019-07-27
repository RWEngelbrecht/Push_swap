/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:13:34 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/27 14:54:29 by rengelbr         ###   ########.fr       */
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
*//* 
void	quicksort(int len, t_stack **a,t_stack **b_temp)
{
//	t_stack *b_temp;
	int top_half_len;
//	int half_len;
	int avg;
	int i;
	int j;

//	b_temp = NULL;
	top_half_len = 0;
	avg = find_avg(a);
	i = 0;
	if (len == 1)
		return ;
	while (i < len)
	{
		if ((*a)->value >= avg)
		{
			ft_putendl_fd("pb", 1);
			push_to(b_temp, a);
			top_half_len++;
		}
		ft_putendl_fd("ra", 1);
		rotate(a);
		i++;
	}
	j = len - top_half_len;
	while (j)
	{
		ft_putendl_fd("rra", 1);
		rev_rot(a);
		j--;
	}*//*
	half_len = top_half_len;
	while (half_len)
	{
		ft_putendl_fd("pa", 1);
		push_to(a, &b_temp);
		half_len--;
	}
	quicksort(top_half_len, &b_temp);
	half_len = top_half_len;
	while (half_len)
	{
		ft_putendl_fd("ra", 1);
		rotate(a);
		half_len--;
	}
	j = len - top_half_len;
	quicksort(j, a);
	half_len = top_half_len;
	while (half_len)
	{
		ft_putendl_fd("rra", 1);
		rev_rot(a);
		half_len--;
	}
}
*/

void	do_sort_three(t_stack **a, t_stack **b)
{
	if ((*a)->value > (*a)->next->value &&
		(*a)->value < (*a)->next->next->value)
		print_do_op("sa", a, b);
	else if ((*a)->value > (*a)->next->value &&
				(*a)->next->value >
					(*a)->next->next->value)
	{
		print_do_op("sa", a, b);
		print_do_op("rra", a, b);
	}
	else if ((*a)->value > (*a)->next->value &&
				(*a)->next->value <
						(*a)->next->next->value)
		print_do_op("ra", a, b);
	else if ((*a)->value < (*a)->next->value &&
				(*a)->value <
						(*a)->next->next->value)
	{
		print_do_op("sa", a, b);
		print_do_op("ra", a, b);
	}
	else if ((*a)->value < (*a)->next->value &&
				(*a)->value >
						(*a)->next->next->value)
		print_do_op("rra", a, b);
}
#include <stdio.h>
void	do_sort_five(t_stack **a, t_stack **b)
{
	print_do_op("pb", a, b);
	print_do_op("pb", a, b);
	if (!is_sorted(*a))
		do_sort_three(a, b);
	while (*b != NULL)
	{
		//printf("b = %i\n(*a) = %i\n", b->value, (*a)->value);
		if ((*b)->value < (*a)->value)
		{
			print_do_op("pa", a, b);
		}
		else if ((*b)->value > (*a)->value)
		{
			print_do_op("pa", a, b);
			if ((*a)->value < (*a)->next->next->value)
				print_do_op("sa", a, b);
			else if ((*a)->value >
						(*a)->next->next->next->next->value)
				print_do_op("ra", a, b);
		}
	}
}