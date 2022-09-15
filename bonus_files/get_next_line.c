/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:24:37 by qsergean          #+#    #+#             */
/*   Updated: 2021/12/19 18:55:39 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>

char	*ft_pre_join(char *s1, char *s2)
{
	if (s1 == NULL && s2 == NULL)
		return (ft_strdup(""));
	else if (s1 == NULL)
		return (ft_strdup(s2));
	else if (s2 == NULL)
		return (ft_strdup(s1));
	else
		return (ft_strjoin_mod(s1, s2));
}

char	*ft_read_and_save(char *remain, int fd)
{
	char	*buf;
	int		nb;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	nb = 1;
	while (nb > 0)
	{
		nb = read (fd, buf, BUFFER_SIZE);
		if (nb < 0)
		{
			free(buf);
			return (NULL);
		}
		if (nb == 0)
			break ;
		buf[nb] = '\0';
		remain = ft_pre_join(remain, buf);
		if (ft_strchr(remain, '\n'))
			break ;
	}
	free(buf);
	return (remain);
}

char	*ft_get_line(char *remain)
{
	size_t	len;
	char	*line;
	size_t	i;

	line = NULL;
	len = 0;
	while (remain[len] && remain[len] != '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (remain[i])
	{
		line[i] = remain[i];
		if (remain[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_remainder(char *remain)
{
	size_t	i;
	size_t	len;
	char	*new;

	i = 0;
	new = NULL;
	if (remain[i])
	{
		while (remain[i] && remain[i] != '\n')
			i++;
		len = ft_strlen(&remain[i + 1]);
		if (remain[i] == '\0' || len == 0)
		{
			free(remain);
			return (NULL);
		}
		new = (char *)malloc(sizeof(char) * (len + 1));
		if (new == NULL)
			return (NULL);
		new[len] = '\0';
		ft_strcpy(new, &remain[i + 1], len);
		free(remain);
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	remainder = ft_read_and_save(remainder, fd);
	if (remainder == NULL)
		return (NULL);
	line = ft_get_line(remainder);
	if (line == NULL)
	{
		return (NULL);
	}
	remainder = ft_get_remainder(remainder);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*res;
// 	size_t	i;

// 	fd = open("eight_v.txt", O_RDONLY);
// 	res = get_next_line(fd);
// 	i = 0;
// 	while (res)
// 	{
// 		printf("%s", res);
// 		free (res);
// 		res = get_next_line(fd);
// 		if (!res)
// 			break ;
// 		i++;
// 	}
// 	close(fd);
// 	// while (1)
// 	// {
// 	// }
// }
