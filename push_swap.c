/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:37:03 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/14 10:40:11 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
    t_stack	*stack_a;
	t_stack *stack_b;
    char cmds[3][3] = {"sa", "ra"};

    stack_b = NULL;
    if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
    stack_a = ft_stackpopulate(argc, argv);
    ft_putendl_fd(cmds[0], 1);
    ft_putendl_fd(cmds[1], 1);
    
    return (0);
}