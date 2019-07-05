/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:15:15 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/05 13:11:40 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#include "libft/libft.h"

t_stack	*ft_stacknew(int *argv, int argc)
{
	t_stack	*stack;
	int 	i;

	i = 1;
	stack = malloc(sizeof(t_stack));
	stack->value = ft_atoi(av[i]);
	stack->next = NULL;
	i++;
	// if (!(*av))
	// 	stack->value = NULL;
	while (i < ac)
	{
		stack->next = malloc(sizeof(t_stack));
		stack->next->value = ft_atoi(av[i]);
		i++;
	}
	stack->next->next = NULL;
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

int main(int ac, char *av[])
{
	t_stack	*a;
	int 	i = 0;
	int 	arg[ac - 1];

	while(i < ac && **av)
		arg[i] = ft_atoi(av[i + 1]);
	stack = ft_stacknew(arg, ac);

	while (stack->next)
		printf("%d\n", stack->value);
	return (0);
}
