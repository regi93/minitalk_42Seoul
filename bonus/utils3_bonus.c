/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:01:30 by mmurello          #+#    #+#             */
/*   Updated: 2021/06/17 18:14:54 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_end(int sign)
{
	if (sign == SIGUSR1)
		write(1, "Message received\n", 17);
	exit (0);
}
