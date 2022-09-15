/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:12:04 by qsergean          #+#    #+#             */
/*   Updated: 2022/01/07 22:48:40 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_lhexadecimal_helper(t_print *box, char *h,
	int hlen, int count)
{
	if (!(box->dash))
	{
		while ((box->width)-- > 0)
			count += write(1, &" ", 1);
		if (box->num && (h[0] != '0'))
			count += write(1, &"0x", 2);
		while ((box->precision)-- > 0)
			count += write(1, &"0", 1);
		while (*h)
			count += write(1, h++, 1);
	}
	else if (box->dash)
	{
		if (box->num && (h[0] != '0'))
			count += write(1, &"0x", 2);
		while ((box->precision)-- > 0)
			count += write(1, &"0", 1);
		while (*h)
			count += write(1, h++, 1);
		while ((box->width)-- > 0)
			count += write(1, &" ", 1);
	}
	free(h - hlen);
	return (count);
}

int	print_lhexadecimal(t_print *box)
{
	int		count;
	char	*h;
	int		hlen;

	h = lower_hexadec(va_arg(box->args, unsigned int));
	if (*h == '0' && box->dot)
	{
		free(h);
		h = ft_strdup("");
	}
	hlen = (int)ft_strlen(h);
	if (hlen <= box->precision)
		box->precision -= hlen;
	else
		box->precision = 0;
	if (box->zero && !box->dot)
		box->precision = box->width - hlen;
	box->width -= hlen + box->precision + box->num;
	count = 0;
	return (print_lhexadecimal_helper(box, h, hlen, count));
}

static int	print_uhexadecimal_helper(t_print *box, char *h,
	int hlen, int count)
{
	if (!(box->dash))
	{
		while ((box->width)-- > 0)
			count += write(1, &" ", 1);
		if (box->num && (h[0] != '0'))
			count += write(1, &"0X", 2);
		while ((box->precision)-- > 0)
			count += write(1, &"0", 1);
		while (*h)
			count += write(1, h++, 1);
	}
	else if (box->dash)
	{
		if (box->num && (h[0] != '0'))
			count += write(1, &"0X", 2);
		while ((box->precision)-- > 0)
			count += write(1, &"0", 1);
		while (*h)
			count += write(1, h++, 1);
		while ((box->width)-- > 0)
			count += write(1, &" ", 1);
	}
	free(h - hlen);
	return (count);
}

int	print_uhexadecimal(t_print *box)
{
	int		count;
	char	*h;
	int		hlen;

	h = upper_hexadec(va_arg(box->args, unsigned int));
	if (*h == '0' && box->dot)
	{
		free(h);
		h = ft_strdup("");
	}
	hlen = (int)ft_strlen(h);
	if (hlen <= box->precision)
		box->precision -= hlen;
	else
		box->precision = 0;
	if (box->zero && !box->dot)
		box->precision = box->width - hlen;
	box->width -= hlen + box->precision + box->num;
	count = 0;
	return (print_uhexadecimal_helper(box, h, hlen, count));
}
