/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <jfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:19:09 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/14 14:31:11 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_ctobit(char carattere)
{
	int		i;
	char	*ret;

	ret = malloc(sizeof(8));
	if (ret == 0)
		exit(0);
	ret[7] = 0;
	i = 6;
	while (carattere > 1)
	{
		ret[i] = (carattere % 2) + 48;
		carattere /= 2;
		i--;
	}
	ret[i] = (carattere % 2) + 48;
	i--;
	while (i >= 0)
	{
		ret[i] = 48;
		i--;
	}
	return (ret);
}

void	ft_send_term(int pid)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(50);
	}
}

void	ft_send_signal(int pid, char *string)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (string[i])
	{
		temp = ft_ctobit(string[i]);
		j = 0;
		while (temp[j])
		{
			if (temp[j] == '0')
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(50);
		}
		free(temp);
		i++;
	}
	ft_send_term(pid);
}

int	main(int argc, char *argv[])
{
	int					pid;
	int					i;
	char				*string;

	if (argc != 3)
		exit(0);
	i = 0;
	if (ft_check_argv(argv[1]) < 0)
		exit (0);
	pid = ft_atoi(argv[1]);
	string = argv[2];
	ft_send_signal(pid, string);
}
