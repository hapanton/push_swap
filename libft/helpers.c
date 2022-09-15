/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:14:32 by qsergean          #+#    #+#             */
/*   Updated: 2022/01/08 15:10:12 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_unsigned_numlen(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*res;
	int		i;

	i = ft_unsigned_numlen(n);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	res[i--] = '\0';
	while (i >= 0)
	{
		res[i] = '0' + n % 10;
		n = n / 10;
		i--;
	}
	return (res);
}

t_print	*struct_initialize(t_print *box)
{
	box->width = 0;
	box->precision = 0;
	box->zero = 0;
	box->dot = 0;
	box->dash = 0;
	box->sgn = 0;
	box->space = 0;
	box->num = 0;
	box->plus = 0;
	return (box);
}

char	*ft_strrev(char *str)
{
	char	*res;
	size_t	len;
	int		i;

	len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (len)
	{
		res[i] = str[len - 1];
		i++;
		len--;
	}
	res[i] = '\0';
	return (res);
}
