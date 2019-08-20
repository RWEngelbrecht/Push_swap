/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:37:03 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/20 12:50:35 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_sort(t_stack *a, t_stack *b, int stacklen)
{
	if (stacklen == 2)
		do_sort_two(&a, &b);
	else if (stacklen == 3)
		do_sort_three(&a, &b);
	else if (stacklen > 3 && stacklen <= 5)
		do_sort_five(&a, &b);
	else if (stacklen > 5 && stacklen <= 20)
		do_sort_twenty(&a, &b);
	else if (stacklen > 20 && stacklen <= 50)
		do_sort_fifty(&a, &b);
	else if (stacklen > 50 && stacklen <= 105)
		do_sort_hundred(&a, &b);
	else if (stacklen > 100 && stacklen <= 250)
		do_sort_250(&a, &b);
	else if (stacklen > 250 && stacklen <= 505)
		do_sort_500(&a, &b);
	else if (stacklen > 505)
		do_sort_large(&a, &b);
}

int			main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		ERROR;
	if (input_valid(argc, argv))
	{
		if (is_sorted(stack_a = stackpopulate(argc, argv)))
			return (0);
		choose_sort(stack_a, stack_b, stack_len(&stack_a));
//		free(stack_a);
	}
	return (0);
}
