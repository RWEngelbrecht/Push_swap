/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 09:37:03 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/14 13:32:45 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char *argv[])
{
    t_stack	*stack_a;
	t_stack *stack_b;
    t_ops   *cmds;
    //char ops[3][3] = {"sa", "ra"};

    stack_b = NULL;
    cmds = malloc(sizeof(t_ops) * 4);
    if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
    stack_a = stackpopulate(argc, argv);
   // cmds = stackpopulate(2, ops);
    cmds->op = "sa";
    cmds->next = NULL;
    while (cmds != NULL)
    {
        if(check_op(cmds->op))
            ft_putstr_fd(cmds->op, 1);
        cmds = cmds->next;
    }
    return (0);
}