/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:37:03 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/22 11:02:53 by rengelbr         ###   ########.fr       */
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
}
*/
int main (int argc, char *argv[])
{
    t_stack	*stack_a;
	t_stack *stack_b;

    char ops[4][4] = {"rra", "sa", "pq"};

    stack_b = NULL;
//    cmds = malloc(sizeof(t_ops) * 4);
    if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
    if (input_valid(argc, argv))
    {
        stack_a = stackpopulate(argc, argv);
		ft_putendl_fd(ops[0], 1);
//		ft_putendl_fd(ops[2], 1);
    }
	// else
	// {
	// 	ft_putstr_fd("Error\n", 2);
	// 	return (0);
	// }
//    ft_putendl_fd(ops[1], 1);
//    ft_putendl_fd(ops[2], 1);
//    ft_putendl_fd(ops[2], 1);
    
   // cmds = stackpopulate(2, ops);
    // cmds->op = "sa";
    // cmds->next = NULL;
    // while (cmds != NULL)
    // {
    //     if(check_op(cmds->op))
    //         ft_putstr_fd(cmds->op, 1);
    //     cmds = cmds->next;
    // }
    return (0);
}
