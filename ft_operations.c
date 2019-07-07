/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:15:15 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/07 14:48:27 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

void	ft_push(t_stack **head, int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = val;
	node->next = *head;
	*head = node;
}

t_stack	*ft_stacknew(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!(stack_a = malloc(sizeof(t_stack))))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	i = argc;
	stack_a->value = ft_atoi(argv[i - 1]);
	stack_a->next = NULL;
	i--;
	while (i >= 1)
	{
		ft_push(&stack_a, ft_atoi(argv[i]));
		i--;
	}
	return (stack_a);
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
	t_stack	*print;

	stack_a = ft_stacknew(argc, argv);
	print = stack_a;
	ft_swap_a(&print);
	while (print->next != NULL)
	{
		printf("print val 1 = | %d |\n", print->value);
		print = print->next;
	}
	return (0);
}
