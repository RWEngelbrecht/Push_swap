/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:35:18 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/25 13:03:23 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **head, int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = val;
	node->next = *head;
	*head = node;
}

int		pop(t_stack **head)
{
	t_stack	*next_node;
	int		ret;

	if (*head == NULL)
		return (-1);
	next_node = NULL;
	ret = -1;
	next_node = (*head)->next;
	ret = (*head)->value;
	free(*head);
	*head = next_node;
	return (ret);
}

t_stack		*str_stackpopulate(t_stack *stack, char **argv, char **args)
{
	int		i;

	stack = malloc(sizeof(t_stack));
	args = ft_strsplit(argv[1], ' ');
	i = ft_wordcount(argv[1], ' ') - 1;
	stack->value = ft_atoi(args[i]);
	stack->next = NULL;
	i--;
	while (i >= 0)
	{
		push(&stack, ft_atoi(args[i]));
		i--;
	}
	return (stack);
}

t_stack		*stackpopulate(int argc, char **argv)
{
	t_stack	*stack;
	char	**args;
	int		i;

	args = NULL;
	if (!(stack = malloc(sizeof(t_stack))))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (argc == 2)
	{
		stack = str_stackpopulate(stack, argv, args);
		return (stack);
	}
	i = argc - 1;
	stack->value = ft_atoi(argv[i]);
	stack->next = NULL;
	i--;
	while (i >= 1)
	{
		push(&stack, ft_atoi(argv[i]));
		i--;
	}
	return (stack);
}