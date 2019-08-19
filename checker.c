/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:46:43 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/19 14:44:40 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char	*line;

	stack_a = NULL;
	line = NULL;
	stack_b = NULL;
	if (argc < 2)
		ERROR;
	if ((input_valid(argc, argv)))
	{
		stack_a = stackpopulate(argc, argv);
		if (!read_input(&stack_a, &stack_b, &line))
			ERROR;
	}
	else
		ERROR;
	if (is_sorted(stack_a) && !stack_b)
	{
		free(stack_a);
		ft_putstr_fd("OK\n", 1);
		return (0);
	}
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
