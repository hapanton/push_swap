/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:07:35 by qsergean          #+#    #+#             */
/*   Updated: 2022/01/07 22:46:52 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_integer_helper_2(t_print *box, char **i, int *count)
{
	if (box->space)
		*count += write(1, &" ", 1);
	else if (box->plus)
		*count += write(1, &"+", 1);
	else if (box->sgn)
		*count += write(1, &"-", 1);
	while ((box->precision)-- > 0)
		*count += write(1, &"0", 1);
	while (*i[0])
		*count += write(1, i[0]++, 1);
	while ((box->width)-- > 0)
		*count += write(1, &" ", 1);
}

static void	print_integer_helper_1(t_print *box, char **i, int *count)
{
	while ((box->width)-- > 0)
		*count += write(1, &" ", 1);
	if (box->space)
		*count += write(1, &" ", 1);
	else if (box->plus)
		*count += write(1, &"+", 1);
	else if (box->sgn)
		*count += write(1, &"-", 1);
	while ((box->precision)-- > 0)
		*count += write(1, &"0", 1);
	while (*i[0])
		*count += write(1, i[0]++, 1);
}

static void	print_integer_checker_2(t_print *box, int *slen)
{
	if ((box->plus && box->space) || box->sgn)
		box->space = 0;
	if (box->dot && box->zero)
		box->zero = 0;
	if (*slen <= box->precision)
		box->precision -= *slen;
	else
		box->precision = 0;
	if (box->zero && !box->dot)
		box->precision = box->width - *slen - box->sgn;
	box->width -= box->zero + box->precision + box->space
		+ box->plus + box->sgn + *slen;
}

static void	print_integer_checker_1(t_print *box, int *slen, char **i)
{
	if (*i[0] == '0' && box->dot)
	{
		free(i[0]);
		i[0] = ft_strdup("");
	}
	*slen = (int)ft_strlen(i[0]);
	if (*i[0] == '-')
	{
		box->sgn = 1;
		box->plus = 0;
		i[0]++;
		slen[0]--;
	}
	if (box->zero && box->dash)
		box->zero = 0;
}

int	print_integer(t_print *box)
{
	int		slen;
	char	*i;
	int		count;

	i = ft_itoa(va_arg(box->args, int));
	print_integer_checker_1(box, &slen, &i);
	print_integer_checker_2(box, &slen);
	count = 0;
	if (!(box->dash))
		print_integer_helper_1(box, &i, &count);
	else if (box->dash)
		print_integer_helper_2(box, &i, &count);
	free(i - slen - box->sgn);
	return (count);
}
