/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:18:58 by qsergean          #+#    #+#             */
/*   Updated: 2022/01/07 22:16:09 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hex_len(unsigned long long n)
{
	int	len;

	len = 1;
	while (n / 16)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static char	to_upper_hex(unsigned int n)
{
	if ((n % 16) > 9)
		return ((n % 16) + 55);
	else
		return ((n % 16) + 48);
}

static char	to_lower_hex(unsigned long long n)
{
	if ((n % 16) > 9)
		return ((n % 16) + 87);
	else
		return ((n % 16) + 48);
}

char	*upper_hexadec(unsigned int n)
{
	char	*res;
	char	*rev;
	int		i;

	res = (char *)ft_calloc(sizeof(char), (hex_len(n) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (n / 16)
	{
		res[i] = to_upper_hex(n);
		i++;
		n /= 16;
	}
	res[i] = to_upper_hex(n);
	rev = ft_strrev(res);
	free(res);
	return (rev);
}

char	*lower_hexadec(unsigned long long n)
{
	char	*res;
	char	*rev;
	int		i;

	res = (char *)ft_calloc(sizeof(char), (hex_len(n) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (n / 16)
	{
		res[i] = to_lower_hex(n);
		i++;
		n /= 16;
	}
	res[i] = to_lower_hex(n);
	rev = ft_strrev(res);
	free(res);
	return (rev);
}

// int	main(void)
// {
// 	long long int n = 245368476582;

// 	printf("%s\n", lower_hexadec(n));
// 	printf("%s\n", upper_hexadec(n));
// 	printf("%X\n", (int)n);
// 	// printf("%p\n", );
// 	// printf("%    %\n", (int)n);
// }
