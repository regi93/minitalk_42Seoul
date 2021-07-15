/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <jfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:47:49 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/14 14:33:17 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	ft_count(int sign)
{
	static int	cont;
	static int	carattere;
	static char	*string;

	cont++;
	if (sign == SIGUSR2)
	{
		carattere = carattere << 1;
		carattere += 1;
	}
	else
		carattere = carattere << 1;
	if (cont == 7)
	{
		string = ft_create_string(carattere, string);
		if (carattere == 0)
		{
			ft_putstr_fd(string, 1);
			write(1, "\n", 1);
			free(string);
			string = 0;
		}
		cont = 0;
		carattere = 0;
	}
}

int	main(void)
{
	int		pid;
	char	*piddino;
	int		count1;

	count1 = -1;
	pid = getpid();
	piddino = ft_itoa(pid);
	if (piddino == 0)
		exit(0);
	ft_putstr_fd(piddino, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_count);
	signal(SIGUSR2, ft_count);
	while (1)
		pause();
}
