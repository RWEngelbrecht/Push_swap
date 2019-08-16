/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:37:03 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/16 12:14:12 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int			main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stacklen;

	stack_b = NULL;
	stacklen = 0;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (input_valid(argc, argv))
	{
		if (is_sorted(stack_a = stackpopulate(argc, argv)))
			return (0);
		stacklen = stack_len(&stack_a);
// printf("\n STACK A:\n");	//REMOVE
// print_stack(&stack_a);		//REMOVE
// printf("\n STACK B:\n");	//REMOVE
// print_stack(&stack_b);		//REMOVE
		if (stacklen == 3)
			do_sort_three(&stack_a, &stack_b);
		else if (stacklen > 3 && stacklen <= 5)
			do_sort_five(&stack_a, &stack_b);
		else if (stacklen > 5 && stacklen <= 20)
			do_sort_twenty(&stack_a, &stack_b);
		else if (stacklen > 20 && stacklen <= 50)
			do_sort_fifty(&stack_a, &stack_b);
		else if (stacklen > 50 && stacklen <= 100)
			do_sort_hundred(&stack_a, &stack_b);
		else if (stacklen > 100 && stacklen <= 250)
			do_sort_250(&stack_a, &stack_b);
		else if (stacklen > 250 && stacklen <= 500)
			do_sort_500(&stack_a, &stack_b);
	}
// printf("\n STACK A:\n");	//REMOVE
// print_stack(&stack_a);		//REMOVE
// printf("\n STACK B:\n");	//REMOVE
// print_stack(&stack_b);		//REMOVE
	return (0);
}
