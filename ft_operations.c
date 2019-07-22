/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:15:15 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/22 09:09:51 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******      Stack creation + pushing + popping     ******/

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

t_stack	*stackpopulate(int argc, char **argv)
{
	t_stack	*stack;
	char	**args;
	int		i;
	char	c;

	if (!(stack = malloc(sizeof(t_stack))))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	c = ' ';
	if (argc == 2)
	{
		args = ft_strsplit(argv[1], c);
		i = ft_wordcount(argv[1], c) - 1;
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

/************************************************/

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

/************************************************/
/*******************OPERATIONS*******************/

void	swap(t_stack **b)
{
	t_stack *tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	push_to(t_stack **dst, t_stack **src)
{
	t_stack *p_node;

	if (!(*src))
		return ;
	p_node = malloc(sizeof(t_stack));
	p_node->value = pop(src);
	if (!(*dst))
		p_node->next = NULL;
	else
		p_node->next = *dst;
	*dst = p_node;
}

void	rotate(t_stack **a)
{
	t_stack *first;
	t_stack *last;

	first = *a;
	last = *a;
	if ((*a)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	(*a) = first->next;
	first->next = NULL;
	last->next = first;
}

void	rot_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void	rev_rot(t_stack **a)
{
	t_stack *scnd_last;
	t_stack *last;

	scnd_last = NULL;
	last = *a;
	while (last->next != NULL)
	{
		scnd_last = last;
		last = last->next;
	}
	scnd_last->next = NULL;
	last->next = *a;
	*a = last;
}

void rev_rot_both(t_stack **a, t_stack **b)
{
	rev_rot(a);
	rev_rot(b);
}

/************************************************/
