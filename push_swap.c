/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:37:03 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/26 15:18:45 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int stacklen;

	stack_b = NULL;
	stacklen = 0;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (input_valid(argc, argv))
	{
		stack_a = stackpopulate(argc, argv);
		stacklen = stack_len(&stack_a);
		if (stacklen == 3)
			do_sort_three(&stack_a);
		else
		{
			quicksort(stacklen, &stack_a);
		}
	}
	// else
	// {
	// 	ft_putstr_fd("Error\n", 2);
	// 	return (0);
	// }
	return (0);
}
