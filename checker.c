/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:46:43 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/25 09:08:34 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char	*line;
	char **args;

	stack_a = NULL;
	args = argv;
	stack_b = NULL;
	if (argc < 2)
		ERROR;
	if ((input_valid(argc, args)))
	{
		stack_a = stackpopulate(argc, args);
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
	return (0);
}
