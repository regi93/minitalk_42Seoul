/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:19:09 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/17 18:11:20 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

char	*ft_ctobit(char carattere)
{
	int		i;
	char	*ret;

	ret = malloc(sizeof(9));
	if (ret == 0)
		exit(0);
	ret[8] = 0;
	i = 7;
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
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		i++;
		usleep(50);
	}
}

char	*ft_ctobit_pluse(char cara)
{
	char	*string;

	cara *= -1;
	string = ft_ctobit(cara);
	ft_string_complement(string);
	return (string);
}

void	ft_send_signal(int pid, char *string)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (string[i])
	{
		if (string[i] < 0)
			temp = ft_ctobit_pluse(string[i]);
		else
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
		i++;
		free(temp);
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*string;
	char	*temp;

	if (argc != 3)
		exit (0);
	if (ft_check_argv(argv[1]) < 0)
		exit (0);
	pid = ft_atoi(argv[1]);
	string = argv[2];
	temp = ft_itoa(getpid());
	if (temp == 0)
		exit (0);
	ft_send_signal(pid, "\1");
	ft_send_signal(pid, temp);
	ft_send_term(pid);
	ft_send_signal(pid, string);
	ft_send_term(pid);
	free(temp);
	signal(SIGUSR1, ft_end);
	pause();
}
