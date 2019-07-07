/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:15:15 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/07 18:30:37 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

/******      Stack creation + pushing      ******/

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
/************************************************/
void	ft_print_stack(t_stack **stack)
{
	t_stack	*print;

	print = *stack;
	while (print->next != NULL)
	{
		ft_putnbr(print->value);
		ft_putchar('\n');
		print = print->next;
	}
}
/************************************************/
/*******************OPERATIONS*******************/
void	ft_swap(t_stack **ab)
{
	t_stack *tmp;

	tmp = *ab;
	*ab = (*ab)->next;
	tmp->next = (*ab)->next;
	(*ab)->next = tmp;
}

void	ft_

int main(int argc, char *argv[])
{
	t_stack	*stack_a;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stack_a = ft_stacknew(argc, argv);
	ft_swap(&stack_a);
	ft_print_stack(&stack_a);

	return (0);
}
