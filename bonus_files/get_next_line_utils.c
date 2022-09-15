/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:05:14 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/15 20:55:18 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	res;

	if (s == NULL)
		return (0);
	res = 0;
	while (*s)
	{
		res++;
		s++;
	}
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	if (p == NULL)
		return (NULL);
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if (*p == '\0' && c == 0)
		return (p);
	return (NULL);
}

void	ft_strcpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while ((dest[i] || src[i]) && len--)
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		res[i] = s2 [i - len1];
		i++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}
