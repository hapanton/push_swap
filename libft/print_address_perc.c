/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address_perc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:13:15 by qsergean          #+#    #+#             */
/*   Updated: 2022/01/10 14:16:51 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_address_helper(t_print *box, char *p, int plen)
{
	int	count;

	count = 0;
	if (!(box->dash))
	{
		while ((box->width)-- > 0)
			count += write(1, &" ", 1);
		count += write(1, &"0x", 2);
		while ((box->precision)-- > 0)
			count += write(1, &"0", 1);
		while (*p)
			count += write(1, p++, 1);
	}
	else if (box->dash)
	{
		count += write(1, &"0x", 2);
		while ((box->precision)-- > 0)
			count += write(1, &"0", 1);
		while (*p)
			count += write(1, p++, 1);
		while ((box->width)-- > 0)
			count += write(1, &" ", 1);
	}
	free(p - plen);
	return (count);
}

int	print_address(t_print *box)
{
	char	*p;
	int		plen;

	p = lower_hexadec(va_arg(box->args, unsigned long long));
	if (*p == '0' && box->dot)
	{
		free(p);
		p = ft_strdup("");
	}
	plen = (int)ft_strlen(p);
	if (plen <= box->precision)
		box->precision -= plen;
	box->width -= plen + box->precision + 2;
	return (print_address_helper(box, p, plen));
}

int	print_percent(t_print *box)
{
	int	count;

	box->precision = 0;
	if (box->zero && !(box->dash))
		box->precision = box->width - 1;
	else
		box->zero = 0;
	box->width -= box->zero + box->precision + box->plus + 1;
	count = 0;
	if (!(box->dash))
	{
		while ((box->width)-- > 0)
			count += write(1, &" ", 1);
		while ((box->precision)-- > 0)
			count += write(1, &"0", 1);
		count += write(1, &"%", 1);
	}
	else if (box->dash)
	{
		count += write(1, &"%", 1);
		while ((box->width)-- > 0)
			count += write(1, &" ", 1);
	}
	return (count);
}
