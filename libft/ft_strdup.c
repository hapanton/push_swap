/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:14:12 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/15 19:45:48 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/errno.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*res;
	char	*start;
	size_t	len;

	len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	start = res;
	while (len--)
	{
		*res = *s1;
		s1++;
		res++;
	}
	*res = '\0';
	return (start);
}

char	*ft_strdup_new(const char *s1, int total)
{
	char	*res;
	char	*start;
	size_t	len;

	len = ft_strlen(s1);
	res = (char *)ft_calloc(sizeof(char), (total + 1));
	if (res == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	start = res;
	while (len--)
	{
		*res = *s1;
		s1++;
		res++;
	}
	*res = '\0';
	return (start);
}

// int main(void)
// {
// 	char *str = "biba \0i bobla";
// 	char *resultik = ft_strdup(str);

// 	printf("%s\n%s\n", str, resultik);
// }
