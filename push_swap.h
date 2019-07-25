/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:48:45 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/25 13:01:50 by rengelbr         ###   ########.fr       */
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

void				push(t_stack **head, int val);
int					pop(t_stack **head);
t_stack				*stackpopulate(int argc, char **argv);
t_stack				*str_stackpopulate(t_stack *stack, char **argv, char **args);
void				print_stack(t_stack **stack);
int					stacklen(t_stack **stack);
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
int					input_valid(int ac, char **av);
int					only_digits(char *str);
int					dup_check(int ac, char **av);
int					input_valid_string(int ac, char **av);
int					input_valid_ints(int ac, char **av);

#endif
