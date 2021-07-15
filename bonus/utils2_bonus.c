/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <jfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:20:53 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/14 13:31:02 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*ft_create_string(char carattere, char *string)
{
	char	*temp;
	char	*temp2;

	temp = malloc(2);
	if (temp == 0)
		exit(0);
	temp[0] = carattere;
	temp[1] = 0;
	if (string == 0)
	{
		string = malloc(2);
		if (string == 0)
			exit(0);
		ft_strlcpy(string, temp, 2);
	}
	else
	{
		temp2 = string;
		string = ft_strjoin(string, temp);
		if (string == 0)
			exit (0);
		free(temp2);
	}
	free(temp);
	return (string);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(int c)
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

void	ft_string_complement(char *string)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (string[i] != 0)
	{
		if (string[i] == '0')
			string[i] = '1';
		else if (string[i] == '1')
			string[i] = '0';
		i++;
	}
	i = 7;
	while (i > 0 && flag != 1)
	{
		if (string[i] == '0')
		{
			string[i] = '1';
			flag = 1;
		}
		else
			string[i] = '0';
		i--;
	}
}
