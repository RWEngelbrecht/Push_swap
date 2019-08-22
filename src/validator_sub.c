/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rengelbr <rengelbr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 10:44:01 by rengelbr          #+#    #+#             */
/*   Updated: 2019/08/22 16:22:48 by rengelbr         ###   ########.fr       */
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

int		dup_check(/*int ac, */char **arr)	/////
{
//	char	**str;
	int		i;
	int		j;

	i = 0;
//	str = NULL;
//	if (ac == 2)
//	{
//		str = ft_strsplit(av[1], ' ');
//		i = 0;
//	}
//	else
//		str = av;
	while (arr[i])			////
	{
		j = 1;
		while (arr[i + j] != '\0')
		{
			if (ft_strequ(arr[i], arr[i + j]))
			{
			//	free(arr);     ///leak
				return (0);
			}
			j++;
		}
		i++;
	}
//	if (ac == 2)				leak
//	free(arr);
	return (1);
}

int		input_valid_string(/*int ac, */char **av)
{
	char	**arr;
	char	*str;
	int		i;

	str = av[1];					/////
	arr = ft_strsplit(str, ' ');	/////
	i = 0;
	if (!only_digits(str))			/////
		return (0);
	if (!dup_check(/*ac, */arr))			/////
		return (0);
	while (arr[i])
	{
		if (ft_int_over(arr[i]))
		{
//			free(arr);
			return (0);
		}
		i++;
	}
//	free(arr);
	return (1);
}

int		input_valid_ints(/*int ac, */char **av)
{
	int		i;
	char **arr;			//////

	i = 1;
	arr = av;		/////
	while (arr[i])
	{
		if (!only_digits(arr[i]))
			return (0);
		if (ft_int_over(arr[i]))
			return (0);
		i++;
	}
	if (!dup_check(/*ac, */arr))
		return (0);
	return (1);
}
