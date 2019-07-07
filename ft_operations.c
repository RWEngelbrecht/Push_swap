/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:15:15 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/07 13:50:40 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

t_stack	*ft_stacknew(int argc, char *argv)
{
	t_stack *stack;
	t_stack *node;

	int i;

	if (argc <= 1)
		return (NULL);
	i = argc;
	stack = malloc(sizeof(t_stack));
	stack->value = ft_atoi(&argv[i]);
	stack->next = NULL;
	i--;
	while (i > 1)
	{
		node->value = ft_atoi(&argv[i]);
		node = node->next;
		i--;
	}
	node->next = stack;
	stack = node;
	return (stack);
}

void	ft_swap_a(t_stack **a)
{
	t_stack *tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

int main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *node_a;
	int i;
	t_stack *print;

	i = (argc - 1);
	stack_a = malloc(sizeof(t_stack));
	stack_a->value = ft_atoi(argv[i]);
	stack_a->next = NULL;
	i--;
	while (i > 1)
	{
		printf("%s\n", "entered while loop");
		node_a = malloc(sizeof(t_stack));
		node_a->value = ft_atoi(argv[i]);
		i--;
		printf("i = | %d |\n", i);
		if (i <= 1)
			break ;
		else
			node_a = node_a->next;
	}
	node_a->next = stack_a;
	stack_a = node_a;
	printf("stack_a node 1 = | %d |\n", stack_a->value);
	//a_node = ft_stacknew(i, args);
	print = stack_a;
	while (print->next != NULL)
	{
		printf("print val 1 = | %d |\n", print->value);
		print = print->next;
	}
	return (0);
}
