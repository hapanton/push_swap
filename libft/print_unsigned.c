/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:11:12 by qsergean          #+#    #+#             */
/*   Updated: 2022/01/07 22:47:10 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_unsigned_helper_2(t_print *box, char **u, int count)
{
	if (box->space)
		count += write(1, &" ", 1);
	else if (box->plus)
		count += write(1, &"+", 1);
	while ((box->precision)-- > 0)
		count += write(1, &"0", 1);
	while (*u[0])
		count += write(1, u[0]++, 1);
	while ((box->width)-- > 0)
		count += write(1, &" ", 1);
	return (count);
}

static int	print_unsigned_helper_1(t_print *box, char *u, int ulen, int count)
{
	if (box->zero && !box->dot)
		box->precision = box->width - ulen;
	box->width -= box->zero + box->precision + box->space
		+ box->plus + box->sgn + ulen;
	if (!(box->dash))
	{
		while ((box->width)-- > 0)
			count += write(1, &" ", 1);
		if (box->space)
			count += write(1, &" ", 1);
		else if (box->plus)
			count += write(1, &"+", 1);
		while ((box->precision)-- > 0)
			count += write(1, &"0", 1);
		while (*u)
			count += write(1, u++, 1);
	}
	else if (box->dash)
		count += print_unsigned_helper_2(box, &u, count);
	free(u - ulen);
	return (count);
}

int	print_unsigned(t_print *box)
{
	int		ulen;
	char	*u;
	int		count;

	u = ft_unsigned_itoa(va_arg(box->args, unsigned int));
	if (*u == '0' && box->dot)
	{
		free(u);
		u = ft_strdup("");
	}
	ulen = (int)ft_strlen(u);
	if ((box->plus && box->space))
		box->space = 0;
	if (box->zero && box->dash)
		box->zero = 0;
	if (box->dot && box->zero)
		box->zero = 0;
	if (ulen <= box->precision)
		box->precision -= ulen;
	else
		box->precision = 0;
	count = 0;
	return (print_unsigned_helper_1(box, u, ulen, count));
}
