/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:46:43 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/04 17:32:23 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>		//REMOVE

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
		return (2);
	}
	if ((input_valid(argc, argv)))
	{
		stack_a = stackpopulate(argc, argv);
		if (!read_input(&stack_a, &stack_b, &line))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
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
	//  printf("\n STACK A:\n");	//REMOVE
	//  print_stack(&stack_a);		//REMOVE
	//  printf("\n STACK B:\n");	//REMOVE
	//  print_stack(&stack_b);		//REMOVE
	return (0);
}
