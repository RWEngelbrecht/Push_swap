/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:46:43 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/16 11:18:39 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

/* ************ Insertion sort experiment
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

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char	*line;

	stack_a = NULL;
	line = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	/* Validate arguments */
	if (input_valid(argc, argv))
	{
		stack_a = stackpopulate(argc, argv);
		read_input(&stack_a, &stack_b, &line);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (is_sorted(stack_a) && !stack_b)
	{
		free(stack_a);
		ft_putstr_fd("OK\n", 1);
		return (0);
	}
	else
		ft_putstr_fd("KO\n", 1);
	 
//	insertionSort(&stack_a);
	printf("\n STACK A:\n");
	print_stack(&stack_a);
	printf("\n STACK B:\n");
	print_stack(&stack_b);
	
	return (0);
}