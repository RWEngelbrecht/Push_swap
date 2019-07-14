/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:48:45 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/14 11:48:56 by rengelbr         ###   ########.fr       */
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

void				ft_push(t_stack **head, int val);
int					ft_pop(t_stack **head);
t_stack				*ft_stackpopulate(int argc, char **argv);
void				ft_print_stack(t_stack **stack);
int					ft_stacklen(t_stack **stack);
void				ft_swap(t_stack **b);
void				ft_swap_both(t_stack **a, t_stack **b);
void				ft_push_to(t_stack **dst, t_stack **src);
void				ft_rotate(t_stack **a);
void				ft_rot_both(t_stack **a, t_stack **b);
void				ft_rev_rot(t_stack **a);
void 				ft_rev_rot_both(t_stack **a, t_stack **b);
void    			read_input(t_stack **a, t_stack **b, char **line);
int     			check_op(char *line);
int     			checkline(char *line);
void    			do_op(char *line, t_stack **a, t_stack **b);

#endif
