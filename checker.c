/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:46:43 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/18 12:18:51 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	if ((input_valid(argc, argv)))
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
