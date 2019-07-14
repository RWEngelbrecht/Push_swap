/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:46:43 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/12 12:41:34 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char	**line;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack_a = ft_stackpopulate(argc, line);
	printf("Stack A Initialized\n");
	read_input(stack_a, stack_b, line);
//	insertionSort(&stack_a);
	
//	ft_ra(&stack_a);
//	ft_ra(&stack_a);
//	ft_ra(&stack_a);
//	ft_sa(&stack_a);
//	ft_rra(&stack_a);
//	ft_push_to(&stack_b, &stack_a);

	ft_print_stack(&stack_a);
	printf("\n");
//	ft_print_stack(&stack_b);


	
return (0);
}