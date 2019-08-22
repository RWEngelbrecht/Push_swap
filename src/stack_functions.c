/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:35:18 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/22 17:06:04 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack		*stack_new(int val)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
//	*stack = malloc(sizeof(t_stack));			///
	(new)->value = val;
	(new)->next = NULL;
	return (new);
//print_stack(stack);
}

void		push(t_stack **stack, int val)
{
//	t_stack *curr;
	t_stack	*node;

//	curr = *stack;
	node = stack_new(val);
	// node = (t_stack*)malloc(sizeof(t_stack));
	node->value = val;
	node->next = *stack;
//	node->next = curr;
	*stack = node;
//	free(node);
}

int			pop(t_stack **stack)
{
	t_stack	*next_node;
	int		ret;

	if (*stack == NULL)
		return (-1);
//	next_node = malloc(sizeof(t_stack));
	ret = -1;
	next_node = (*stack)->next;
	ret = (*stack)->value;
	free(*stack);
	*stack = next_node;
//	free(next_node);
	return (ret);
}

// t_stack		*str_stackpopulate(t_stack *stack, char **argv)
// {
// 	int		i;
// 	char	**args;

// //	stack = malloc(sizeof(t_stack));
// 	i = ft_wordcount(argv[1], ' ') - 1;
// 	args = ft_strsplit(argv[1], ' ');
// 	//stack_new(&stack, ft_atoi(args[i]));
// 	stack = stack_new(ft_atoi(args[i]));				///////
// 	i--;
// 	while (i >= 0)
// 	{
// 		push(&stack, ft_atoi(args[i]));
// 		i--;
// 	}
// 	free(args); //new
// 	return (stack);
// }

void		str_stackpopulate(t_stack **stack, char **argv)
{
	int		i;
	char	**args;

//	stack = malloc(sizeof(t_stack));
	i = ft_wordcount(argv[1], ' ') - 1;
	args = ft_strsplit(argv[1], ' ');
	//stack_new(&stack, ft_atoi(args[i]));
	*stack = stack_new(ft_atoi(args[i]));				///////
	i--;
	while (i >= 0)
	{
		push(stack, ft_atoi(args[i]));
		i--;
	}
	free(args); //new
//	return (stack);
}

t_stack		*stackpopulate(int argc, char **argv)
{
//	while(1);							////////////////////WHILE HERE
	t_stack	*stack;
//	t_stack *norm;
	int		i;

	stack = NULL;
//	norm = NULL;
//	if (!(stack = malloc(sizeof(t_stack))))
//	{
//		ft_putstr_fd("Error\n", 2);
//		return (0);
//	}
	if (argc == 2)
	{
		str_stackpopulate(&stack, argv);
//		norm = normalize(&stack);
//		free(stack);
		return (stack);
	}
	i = argc - 1;
	//stack_new(&stack, ft_atoi(argv[i--]));
	stack = stack_new(ft_atoi(argv[i--]));
	while (i >= 1)
		push(&stack, ft_atoi(argv[i--]));
//	norm = normalize(&stack);
//	free(stack);
	return (stack);
}
