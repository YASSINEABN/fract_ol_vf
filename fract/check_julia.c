/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 04:57:28 by yaboulan          #+#    #+#             */
/*   Updated: 2024/03/21 05:17:41 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>

int	is_signed(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	is_float(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (count > 0 || !is_digit(str[i + 1]))
				return (0);
			else
				count++;
		}
		else if (!is_digit(str[i]) && count == 0)
		{
			if (str[i] == '.')
				count++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_julia(char **argv)
{
	int	i;

	i = 2;
	while (argv[i])
	{
		if (!is_float(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
