/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <jfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:05:38 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/14 13:30:10 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putchar_fd_mod(char *c, int fd, int byte)
{
	write(fd, c, byte);
}

static int	nlen(int n)
{
	if (n < 0)
	{
		if (n > -10 && n < 0)
			return (2);
		else
			return (nlen(n / 10 * (-1)) + 2);
	}
	if (n < 10)
		return (1);
	return (nlen(n / 10) + 1);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		i;

	i = nlen(n);
	dst = (char *)malloc((i + 1) * sizeof(char));
	if (dst == 0)
		return (0);
	dst[i--] = 0;
	if (n < 0)
	{
		dst[0] = 45;
		dst[i] = (n % 10) * (-1) + 48;
		n = (n / 10) * (-1);
		if (n == 0)
			return (dst);
		i--;
	}
	while ((n / 10) > 0)
	{
		dst[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	dst[i] = n + 48;
	return (dst);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd != 0 && s != 0)
	{
		while (s[i])
		{
			ft_putchar_fd_mod(&s[i], fd, 1);
			i++;
		}
	}
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
