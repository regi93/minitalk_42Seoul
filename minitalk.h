/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:40:55 by juyou             #+#    #+#             */
/*   Updated: 2021/09/13 20:48:44 by juyou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <sys/signal.h>
# include <unistd.h>

typedef struct s_data{
    int bitcnt;
    int decimal;
	int b_idx;
	char backup[1000];
} t_data;

int	ft_atoi(const char *str);
void ft_putnbr(int n);
int	ft_isspace(char c);
int	ft_atoi(const char *str);

#endif