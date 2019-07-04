/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:15:15 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/04 17:35:55 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct		s_array
{
	int				value;
	struct s_array	*next;
}					t_array;

void	ft_swap_a(t_array *a, t_array *b)
