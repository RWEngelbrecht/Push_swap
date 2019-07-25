/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions02.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 12:42:41 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/25 14:13:57 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack **stack)
{
	t_stack	*print;

	print = *stack;
	while (print != NULL)
	{
		ft_putnbr(print->value);
		ft_putchar('\n');
		print = print->next;
	}
}

int		stacklen(t_stack **stack)
{
	t_stack	*tmp;
	int		len;

	len = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int		find_median(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		res;

	tmp = *stack;
	i = 0;
	res = 0;
	while (i < stacklen(tmp))
	{
		
	}
}