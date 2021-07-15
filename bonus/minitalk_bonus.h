/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurello <mmurello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:50:31 by jfabi             #+#    #+#             */
/*   Updated: 2021/06/17 18:14:19 by mmurello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

/* utils.c */

char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_string_complement(char *string);
char	*ft_create_string(char carattere, char *string);
void	ft_putchar_fd_mod(char *c, int fd, int byte);
int		ft_check_argv(char *str);
int		ft_isspace(int c);
int		ft_isdigit(int c);
void	ft_end(int sign);

/* stringhe */

void	*ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
