/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:37:03 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/15 13:52:12 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
    t_stack	*stack_a;
	t_stack *stack_b;

    char ops[4][4] = {"rra", "ra", "pb"};

    stack_b = NULL;
//    cmds = malloc(sizeof(t_ops) * 4);
    if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
    if (input_valid(argc, &argv))
    {
        stack_a = stackpopulate(argc, argv);
        ft_putendl_fd(ops[0], 1);
    }
//    ft_putendl_fd(ops[1], 1);
//    ft_putendl_fd(ops[2], 1);
//    ft_putendl_fd(ops[2], 1);
    
   // cmds = stackpopulate(2, ops);
    // cmds->op = "sa";
    // cmds->next = NULL;
    // while (cmds != NULL)
    // {
    //     if(check_op(cmds->op))
    //         ft_putstr_fd(cmds->op, 1);
    //     cmds = cmds->next;
    // }
    return (0);
}