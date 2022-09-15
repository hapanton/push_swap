/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:10:09 by qsergean          #+#    #+#             */
/*   Updated: 2022/01/07 22:46:12 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_char(t_print *box)
{
	char	c;
	int		count;

	c = va_arg(box->args, int);
	count = 0;
	if (!(box->dash))
	{
		while ((box->width)-- > 1)
			count += write(1, &" ", 1);
		count += write(1, &c, 1);
	}
	else if (box->dash)
	{
		count += write(1, &c, 1);
		while ((box->width)-- > 1)
			count += write(1, &" ", 1);
	}
	return (count);
}

static int	print_string_helper(t_print *box, char *str, int slen)
{
	int	count;

	count = 0;
	if (!(box->dash))
	{
		while ((box->width)-- > 1)
			count += write(1, &" ", 1);
		while (*str && slen--)
			count += write(1, str++, 1);
	}
	else if (box->dash)
	{
		while (*str && slen--)
			count += write(1, str++, 1);
		while ((box->width)-- > 1)
			count += write(1, &" ", 1);
	}
	return (count);
}

int	print_string(t_print *box)
{
	char	*str;
	int		slen;

	str = va_arg(box->args, char *);
	if (str == NULL)
		str = "(null)";
	if (!box->precision && box->dot)
		str = "";
	slen = (int)ft_strlen(str);
	if (box->precision && (slen > box->precision))
		slen = box->precision;
	box->width -= slen - 1;
	return (print_string_helper(box, str, slen));
}
