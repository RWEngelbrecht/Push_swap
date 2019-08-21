/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:46:43 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/21 08:53:44 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char	*line;

//stack_a = ;//malloc(sizeof(t_stack));
//line = NULL;
//stack_b = NULL;//malloc(sizeof(t_stack));

	if (argc < 2)
		ERROR;
	if ((input_valid(argc, argv)))
	{
		stack_a = stackpopulate(argc, argv);
		if (!read_input(&stack_a, &stack_b, &line))
		{
			if (stack_a == malloc(sizeof(t_stack)))
				free(stack_a);
			ERROR;
		}
	}
	else
		ERROR;
	if (is_sorted(stack_a) && !stack_b)
	{
		free(stack_a);
		free(stack_b);
		ft_putstr_fd("OK\n", 1);
		return (0);
	}
	else
	{
		free(stack_a);    ////
		free(stack_b);    ////
		ft_putstr_fd("KO\n", 1);
	}
//	print_stack(&stack_a);
	return (0);
}
