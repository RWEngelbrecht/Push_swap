/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:37:03 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/25 16:08:40 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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

void	do_sort(t_stack **a, t_stack **b)
{
	t_stack	*tempa;
	t_stack	*tempb;
	int		stacklen;
	int		med;

	tempa = *a;
	tempb = *b;
	stacklen = stack_len(&tempa);
	med = find_median(&tempa);
	while (stacklen)
	{
		if (tempa->value <= med)
		{
			ft_putendl_fd("pb", 1);
			pop(&tempa);
		}
		else
		{
			ft_putendl_fd("ra", 1);
			rotate(&tempa);
		}
		stacklen--;
	}
}

int main (int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;

//	char ops[4][4] = {"rra", "ra", "ps"};

	stack_b = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (input_valid(argc, argv))
	{
		stack_a = stackpopulate(argc, argv);
		do_sort(&stack_a, &stack_b);
	}
	// else
	// {
	// 	ft_putstr_fd("Error\n", 2);
	// 	return (0);
	// }
	return (0);
}
