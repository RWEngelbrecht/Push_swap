/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:46:43 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/14 14:45:51 by rengelbr         ###   ########.fr       */
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
//char cmds[3][3] = {"sa", "ra"};
	line = NULL;
//	stack_b = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}

	/* Check argument input type i.e. ARG="1 2 3" || ARG=1 2 3 */
	/* Validate arguments */
	/* read output of push_swap */ //FIGURED THIS OUT
	stack_a = stackpopulate(argc, argv);
//	stack_b = ft_stackpopulate(argc, argv);
	printf("Stack A Initialized\n");
	read_input(&stack_a, &stack_b, &line);
//	insertionSort(&stack_a);
	
//	ft_rotate(&stack_a);
//	ft_swap(&stack_a);
//	ft_rev_rot(&stack_a);
//	ft_push_to(&stack_b, &stack_a);
	printf("\n");
	print_stack(&stack_a);
	printf("\n");
	print_stack(&stack_b);
	
	return (0);
}