/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:55:21 by juyou             #+#    #+#             */
/*   Updated: 2021/09/13 16:13:04 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	kill_char(int pid, char input)
{
	int temp;
	int shift;
	shift = 1 << 7;
	while (shift >= 1)
	{
		temp = input & shift;
		if (temp == shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		shift = shift >> 1;
		usleep(100);
	}
}
void kill_str(int pid, char input[])
{
	int idx;

	idx = 0;
	while(input[idx] != '\0')
	{
		kill_char(pid, input[idx]);
		idx += 1;
	}
	kill_char(pid, 127);
}

int	main(int argc, char *argv[])
{
	int	pid;
	char input;

	pid = ft_atoi(argv[1]);
	kill_str(pid, argv[2]);
}