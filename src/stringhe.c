/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringhe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <jfabi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:58:40 by mmurello          #+#    #+#             */
/*   Updated: 2021/06/14 12:27:42 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*ptr;

	if (count == 0 || size == 0)
	{
		size = 1;
		count = size;
	}
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2)
		return (0);
	res = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&res[ft_strlen(res)], s2, ft_strlen(s2) + 1);
	return (res);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(src));
}
