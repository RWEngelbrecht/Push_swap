/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:13:34 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/26 15:18:38 by rengelbr         ###   ########.fr       */
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
}*/

void	do_sort_three(t_stack **a)
{
	if ((*a)->value > (*a)->next->value &&
		(*a)->value < (*a)->next->next->value)
		ft_putendl_fd("sa", 1);
	else if ((*a)->value > (*a)->next->value &&
				(*a)->next->value >
					(*a)->next->next->value)
	{
		ft_putendl_fd("sa", 1);
		ft_putendl_fd("rra", 1);
	}
	else if ((*a)->value > (*a)->next->value &&
				(*a)->next->value <
						(*a)->next->next->value)
		ft_putendl_fd("ra", 1);
	else if ((*a)->value < (*a)->next->value &&
				(*a)->value <
						(*a)->next->next->value)
	{
		ft_putendl_fd("sa", 1);
		ft_putendl_fd("ra", 1);
	}
	else if ((*a)->value < (*a)->next->value &&
				(*a)->value >
						(*a)->next->next->value)
	{
		ft_putendl_fd("rra", 1);
	}
}

void	quicksort(int len, t_stack **a)
{
	t_stack *b_temp;
	int top_half_len;
	int half_len;
	int avg;
	int i;
	int j;

	b_temp = NULL;
	top_half_len = 0;
	avg = find_avg(a);
	i = len;
	if (len == 1)
		return ;
	while (i > 0)
	{
		if ((*a)->value > avg)
		{
			ft_putendl_fd("pb", 1);
			push_to(&b_temp, a);
			top_half_len++;
			i--;
		}
		ft_putendl_fd("ra", 1);
		rotate(a);
	}
	j = len - top_half_len;
	while (j)
	{
		ft_putendl_fd("rra", 1);
		rev_rot(a);
		j--;
	}
	half_len = top_half_len;
	while (half_len)
	{
		ft_putendl_fd("pa", 1);
		push_to(a, &b_temp);
		half_len--;
	}
	//if (stack_len(a) > stack_len(&b_temp))
		quicksort(top_half_len, a);
	//else
	//	quicksort(top_half_len, &b_temp);
	half_len = top_half_len;
	while (half_len)
	{
		ft_putendl_fd("ra", 1);
		rotate(a);
		half_len--;
	}
	j = len - top_half_len;
	//if (stack_len(a) < stack_len(&b_temp))
		quicksort(j, a);
	//else
	//	quicksort(j, &b_temp);
	half_len = top_half_len;
	while (half_len)
	{
		ft_putendl_fd("rra", 1);
		rev_rot(a);
		half_len--;
	}
}