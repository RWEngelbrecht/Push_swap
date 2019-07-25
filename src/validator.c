/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 12:27:56 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/25 11:32:19 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		input_valid(int ac, char **av)
{
	if (ac == 2)
	{
		if(!input_valid_string(ac, av))
			return (0);
	}
	else if (ac > 2)
	{
		if (!input_valid_ints(ac, av))
			return (0);
	}
	return (1);
}

int		is_sorted(t_stack *a)
{
	int		temp;

	if (!a)
		return (0);
	while (a->next)
	{
		temp = a->value;
		a = a->next;
		if (temp > a->value && a)
			return (0);
	}
	return (1);
}
