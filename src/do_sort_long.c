/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sort_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 09:52:01 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/12 12:49:32 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_sort_hundred(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	int cur1;
	int cur2;
	int cur_min;
	int cur_max;
	int dis1;
	int dis2;
	int len;
	int i;

	tmp = *a;
	cur_min = 1;
	cur_max = 20;
	dis1 = 0;
	dis2 = 0;
	len = stack_len(a);
	i = 1;
	while (tmp)					//first half
	{
		if (tmp->value >= cur_min && tmp->value <= cur_max && i <= len / 2)
		{
			cur1 = tmp->value;	//set first value found in current range
			dis1 = i;			//the amnt of nodes from the begining
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	while (tmp)					//second half
	{
		if (tmp->value >= cur_min && tmp->value <= cur_max && i <= len)
		{
			cur2 = tmp->value;
			dis2 = i;
		}
		tmp = tmp->next;
		i++;
	}
	tmp = *a;
	i = 1;						//IS THIS NEEDED NOW?
	if (((len / 2) - dis1) > (len - dis2))	//use dis1
	{
		while (tmp->value != cur1)
			print_do_op("ra", a, b);
		if ((*b) == NULL)
			print_do_op("pb", a, b);
		else
		{
			find_min_max(*b, 0);
			find_min_max_pos(*b, 0);
		}
	}
}
