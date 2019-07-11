/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:46:43 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/11 14:58:31 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;
//	int len;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack_a = ft_stackpopulate(argc, argv);
	ft_push(&stack_b, 57);
	
	ft_ra(&stack_a);
//	ft_ra(&stack_a);
//	ft_ra(&stack_a);
//	ft_sa(&stack_a);
	ft_rra(&stack_a);
	ft_pb(&stack_b, &stack_a);

	ft_print_stack(&stack_a);
	printf("\n");
	ft_print_stack(&stack_b);

	
return (0);
}