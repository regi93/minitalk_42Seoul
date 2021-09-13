/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:43:38 by juyou             #+#    #+#             */
/*   Updated: 2021/09/13 15:54:13 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// #include "minitalk_bonus.h"

int	ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' ||
			c == '\r' || c == '\f' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	value;

	i = 0;
	value = 0;
	sign = 1;
	while ((str[i] != '\0') && (ft_isspace(str[i]) == 1))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	return (sign * value);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -1 * n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}