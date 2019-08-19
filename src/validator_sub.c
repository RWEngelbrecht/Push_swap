/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:44:01 by rengelbr          #+#    #+#             */
/*   Updated: 2019/07/25 11:31:50 by rengelbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		only_digits(char *str)
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

int		dup_check(int ac, char **av)
{
	char	**str;
	int		i;
	int		j;

	i = 1;
	str = NULL;
	if (ac == 2)
	{
		str = ft_strsplit(av[1], ' ');
		i = 0;
	}
	else
		str = av;
	while (str[i])
	{
		j = 1;
		while (str[i + j] != '\0')
		{
			if (ft_strequ(str[i], str[i + j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		input_valid_string(int ac, char **av)
{
	char	**arr;
	int		i;

	arr = ft_strsplit(av[1], ' ');
	i = 0;
	if (!only_digits(av[1]))
		return (0);
	if (!dup_check(ac, av))
		return (0);
	while (arr[i])
	{
		if (ft_int_over(arr[i]))
			return (0);
		i++;
	}
	return (1);
}

int		input_valid_ints(int ac, char **av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (!only_digits(av[i]))
			return (0);
		if (ft_int_over(av[i]))
			return (0);
		i++;
	}
	if (!dup_check(ac, av))
		return (0);
	return (1);
}

