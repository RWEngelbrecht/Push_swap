/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:15:15 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/08 16:40:54 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******      Stack creation + pushing      ******/

void	ft_addnode(t_stack **head, int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->value = val;
	node->next = *head;
	*head = node;
}

t_stack	*ft_stackpopulate(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	if (!(stack = malloc(sizeof(t_stack))))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	// if (**argv == NULL)
	// {
	// 	stack->value = 0;
	// 	stack->next = NULL;
	// 	return (0);
	// }
	i = argc - 1;
	stack->value = ft_atoi(argv[i]);
	stack->next = NULL;
	i--;
	while (i >= 1)
	{
		ft_addnode(&stack, ft_atoi(argv[i]));
		i--;
	}
	return (stack);
}
/************************************************/
void	ft_print_stack(t_stack **stack)
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
/************************************************/
/*******************OPERATIONS*******************/
void	ft_sa(t_stack **a)
{
	t_stack *tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	ft_sb(t_stack **b)
{
	t_stack *tmp;

	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pb(t_stack **dst_b, t_stack **src_a)
{
	t_stack *p_node;
	t_stack *temp;

	if (!(*src_a))
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	p_node = malloc(sizeof(t_stack));
	p_node->value = (*src_a)->value;
	p_node->next = *dst_b;
	*dst_b = p_node;
	free((p_node));
	temp = *src_a;
	*src_a = (*src_a)->next;
	
}

// void	ft_pb(t_stack **dst_b, t_stack **src_a)
// {
// 	if (!(*dst_b))
// 	{
// 		*dst_b = malloc(sizeof(t_stack));
// 		(*dst_b)->value = (*src_a)->value;
// 		(*dst_b)->next = NULL;
// 		//free(&(*src_a));
// 	}
// 	else
// 	{
// 		(*src_a)->next = *dst_b;
// 		*dst_b = *src_a;
// 	}
// }

void	ft_ra(t_stack **a)
{
	t_stack *first;
	t_stack *last;

	first = (*a)->next;
	last = *a;
	if ((*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	(*a) = first->next;
	first->next = NULL;
	last->next = first;
}

void	ft_rra(t_stack **a)
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
/************************************************/