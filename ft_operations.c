/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:15:15 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/08 16:13:27 by rengelbr         ###   ########.fr       */
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
		ft_addnode(&stack_a, ft_atoi(argv[i]));
		i--;
	}
	return (stack_a);
}
/************************************************/
void	ft_print_stack(t_stack **stack)
{
	t_stack	*print;

	print = *stack;
	while (print->next)
	{
		ft_putnbr(print->value);
		ft_putchar('\n');
		if (print->next != NULL)
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

void	ft_pa(t_stack **dsta, t_stack **srcb)
{

	if (*srcb && *dsta)
	{
		(*srcb)->next = *dsta;
		*dsta = *srcb;
	}
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

	first = *a;
	last = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	(*a)->next = first->next;
	last->next = first;
	first->next = NULL;
	// first->next = NULL;
	// (*a)->next = 
	// last->next = first;

}
/************************************************/