/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:22:10 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/11 19:44:15 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void	ft_strjoin(char **s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (*s1 == NULL || s2 == NULL)
		return ;
	len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	i = 0;
	while (i < len1)
		i++;
	while (i - len1 < len2)
	{
		s1[0][i] = s2 [i - len1];
		i++;
	}
	s1[0][i] = '\0';
}

// int	main(void)
// {
// 	char	*pre = NULL;
// 	char	*post = "cringe";

// 	printf("%s\n", ft_strjoin(pre, post));
// }
