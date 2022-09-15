/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:29:08 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/11 23:07:40 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>
# include <sys/errno.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_pre_join(char *s1, char *s2);
char	*ft_strjoin_mod(char *s1, char *s2);
void	ft_strcpy(char *dest, char *src, int len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif
