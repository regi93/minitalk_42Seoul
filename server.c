/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:49:38 by juyou             #+#    #+#             */
/*   Updated: 2021/09/13 20:49:05 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data data = {7,0,0};

void	process0(int signum)
{
	data.bitcnt--;
	if (data.bitcnt < 0)
	{
		data.backup[data.b_idx] = data.decimal;
		data.bitcnt = 7;

		data.b_idx++;
		data.decimal = 0;
	}
}
void	process1(int signum)
{
	int shift;

	shift = 1;
	shift = shift << data.bitcnt;
	data.decimal = data.decimal | shift;
	data.bitcnt--;
	if (data.bitcnt < 0)
	{
		data.backup[data.b_idx] = data.decimal;
		data.bitcnt = 7;
		
		data.b_idx++;
		if (data.decimal == 127)
		{
			write(1, data.backup, data.b_idx);
			data.b_idx = 0;
		}
		data.decimal = 0;
	}
}

int main(void)
{
	int pid;
	data.bitcnt = 7;
	pid = getpid();
	data.decimal = 0;

	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, process1);
	signal(SIGUSR2, process0);
	while (1)
		;
}
