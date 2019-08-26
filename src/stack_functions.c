/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:35:18 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/26 07:43:03 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack		*new_node(int val)
{
	t_stack *new;

	if (!(new = (t_stack*)malloc(sizeof(new))))
	{
		free(new);
		return (NULL);
	}
	(new)->value = val;
	(new)->next = NULL;
	return (new);
}

void		push(t_stack **stack, int val)
{
	t_stack	*node;

	node = NULL;
	node = new_node(val);
	node->next = *stack;
	*stack = node;
}

int			pop(t_stack **stack)
{
	t_stack	*next_node;
	int		ret;

	next_node = NULL;
	if (*stack == NULL)
		return (-1);
	ret = -1;
	next_node = (*stack)->next;
	ret = (*stack)->value;
	free(*stack);
	*stack = next_node;
	return (ret);
}

static void		str_stack_populate(t_stack **stack, char **argv)
{
	int			i;
	static char	**args;

	i = ft_wordcount(argv[1], ' ') - 1;
	args = ft_strsplit(argv[1], ' ');
	while (i >= 0)
	{
		push(stack, ft_atoi(args[i]));
		i--;
	}
}

t_stack		*stack_populate(int argc, char **argv)
{
	t_stack	*stack;
	t_stack *norm;
	int		i;

	stack = NULL;
	norm = NULL;
	if (argc == 2)
	{
		str_stack_populate(&stack, argv);
		norm = normalize(&stack);
		while (stack)		///////fixes leaks
		{
			free(stack);
			stack = stack->next;
		}
		return (norm);
	}
	i = argc - 1;
	stack = new_node(ft_atoi(argv[i--]));
	while (i >= 1)
		push(&stack, ft_atoi(argv[i--]));
	norm = normalize(&stack);
	while (stack)				////fixes leaks
	{
		free(stack);
		stack = stack->next;
	}
	return (norm);
}
