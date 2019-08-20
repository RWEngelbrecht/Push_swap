/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:46:43 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/20 14:15:37 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char	*line;

/*	prob	//	stack_a = ;//malloc(sizeof(t_stack));
	dont	//	line = NULL;
	need	//	stack_b = NULL;//malloc(sizeof(t_stack));
*/
	if (argc < 2)
		ERROR;
	if ((input_valid(argc, argv)))
	{
		stack_a = stackpopulate(argc, argv);
		if (!read_input(&stack_a, &stack_b, &line))
		{
			free(stack_a);
			free(stack_b);
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
		ft_putstr_fd("KO\n", 1);
//	print_stack(&stack_a);
	return (0);
}
