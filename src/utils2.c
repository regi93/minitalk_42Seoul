/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <jfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:20:53 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/14 13:28:08 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if (c == 32)
		return (1);
	if (c == 9)
		return (1);
	if (c == 10)
		return (1);
	if (c == 11)
		return (1);
	if (c == 12)
		return (1);
	if (c == 13)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		num;
	int		negative;

	i = 0;
	num = 0;
	negative = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (int)str[i] - 48;
		i++;
	}
	return (num * negative);
}

int	ft_check_argv(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num *= 10;
		num += str[i] - 48;
		i++;
		if (str[i] != 0)
		{
			if ((num == 214748364 && str[i] - 48 > 7) || num > 214748364)
				return (-1);
		}
	}
	return (1);
}
