/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_only_digits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 11:43:52 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/25 11:46:19 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Takes string and checks whether the entirety of its content are
 * digits.
 */

int		ft_only_digits(char *str)
{
	while (*str)
	{
		if (*str == '-')
			str++;
		if (!ft_isdigit(*str) && !ft_iswhitespace(*str))
			return (0);
		str++;
	}
	return (1);
}
