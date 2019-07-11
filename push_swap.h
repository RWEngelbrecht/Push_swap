/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 10:48:45 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/11 11:02:04 by rengelbr         ###   ########.fr       */
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
int					ft_stacklen(t_stack **stack);
void				ft_print_stack(t_stack **stack);
void				ft_sa(t_stack **a);
void				ft_sb(t_stack **b);
void				ft_ss(t_stack **a, t_stack **b);
void				ft_pa(t_stack **dsta, t_stack **srcb);
void				ft_ra(t_stack **a);
void				ft_rra(t_stack **a);
void				ft_pb(t_stack **dst_b, t_stack **src_a);

#endif
