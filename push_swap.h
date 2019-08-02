/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:48:45 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/02 13:21:07 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

void				stack_new(t_stack **stack, int val);
void				push(t_stack **stack, int val);
int					pop(t_stack **stack);
t_stack				*stackpopulate(int argc, char **argv);
t_stack				*str_stackpopulate(t_stack *stack, char **argv);
void				print_stack(t_stack **stack);
int					stack_len(t_stack **stack);
void				swap(t_stack **b);
void				swap_both(t_stack **a, t_stack **b);
void				push_to(t_stack **dst, t_stack **src);
void				rotate(t_stack **a);
void				rot_both(t_stack **a, t_stack **b);
void				rev_rot(t_stack **a);
void				rev_rot_both(t_stack **a, t_stack **b);
int					read_input(t_stack **a, t_stack **b, char **line);
int					check_op(char *line);
int					checkline(char *line);
int					is_sorted(t_stack *a);
void				do_op(char *line, t_stack **a, t_stack **b);
void				print_do_op(char *op, t_stack **a, t_stack **b);
int					input_valid(int ac, char **av);
int					only_digits(char *str);
int					dup_check(int ac, char **av);
int					input_valid_string(int ac, char **av);
int					input_valid_ints(int ac, char **av);
int					find_avg(t_stack **stack);
void				do_sort_three(t_stack **a, t_stack **b);
//void				do_sort_three(t_stack **a, t_stack **b, int *order);
void				do_sort_five(t_stack **a, t_stack **b);
//void				do_sort_five(t_stack **a, t_stack **b, int *order);
void				quicksort(int len, t_stack **a,t_stack **b_temp);
t_stack				*normalize(t_stack **stack);

#endif
