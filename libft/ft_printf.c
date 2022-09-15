/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:20:46 by qsergean          #+#    #+#             */
/*   Updated: 2022/02/04 18:39:52 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	middle_parsing_3(const char *s, int *res, t_print *box)
{
	if (*s == 'c')
		*res += print_char(box);
	else if (*s == 's')
		*res += print_string(box);
	else if (*s == 'd' || *s == 'i')
		*res += print_integer(box);
	else if (*s == 'u')
		*res += print_unsigned(box);
	else if (*s == 'x')
		*res += print_lhexadecimal(box);
	else if (*s == 'X')
		*res += print_uhexadecimal(box);
	else if (*s == 'p')
		*res += print_address(box);
	else if (*s == '%')
		*res += print_percent(box);
}

void	middle_parsing_2(const char **s, int i, t_print *box)
{
	while (i--)
	{
		if (*s[0] == '.')
		{
			box->dot = 1;
			s[0]++;
			while (*s[0] >= '0' && *s[0] <= '9')
			{
				box->precision = box->precision * 10 + *s[0] - '0';
				s[0]++;
			}
		}
		else
		{
			while (*s[0] >= '0' && *s[0] <= '9')
			{
				box->width = box->width * 10 + *s[0] - '0';
				s[0]++;
			}
			if (*s[0] == '.')
				continue ;
		}
	}
}

void	middle_parsing_1(const char *s, int i, int *res, t_print *box)
{
	while (*s == '-' || *s == '#' || *s == ' ' || *s == '+' || *s == '0')
	{
		if (*s == '-')
			box->dash = 1;
		else if (*s == '#')
			box->num = 2;
		else if (*s == ' ')
			box->space = 1;
		else if (*s == '+')
			box->plus = 1;
		else if (*s == '0')
			box->zero = 1;
		s++;
		i--;
	}
	middle_parsing_2(&s, i, box);
	middle_parsing_3(s, res, box);
}

void	middle_parsing_0(int i, const char *s, int *res, t_print *box)
{
	while (*s)
	{
		while (*s)
		{
			if (*s == '%')
			{
				s++;
				break ;
			}
			*res += write(1, s, 1);
			s++;
		}
		if (!*s)
			break ;
		i = 0;
		while (*s != 'c' && *s != 's' && *s != 'd' && *s != 'i'
			&& *s != 'u' && *s != 'x' && *s != 'X' && *s != 'p' && *s != '%')
		{
			s++;
			i++;
		}
		box = struct_initialize(box);
		middle_parsing_1(s - i, i, res, box);
		s++;
	}
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		res;
	t_print	*box;

	box = (t_print *)malloc(sizeof(t_print));
	if (box == NULL)
		return (0);
	va_start(box->args, s);
	res = 0;
	i = 0;
	middle_parsing_0(i, s, &res, box);
	va_end(box->args);
	free(box);
	return (res);
}

// int	main(void)
// {
// 	int s = (int)malloc(sizeof(int));
// 	s = 32546789765432;
// 	printf("\nresult_ft: %d\n\n", ft_printf("% +p", (void *)s));
// 	printf("\nresult_c : %d\n",      printf("% +p", (void *)s));
// 	// biba boba
// }

// int	main(void)
// {	
// 	// int	q = 32546789765432;
// 	int		a = -4;
// 	int		b = 0;
// 	char	c = 'a';
// 	int		d = 2147483647;
// 	int		e = -2147483648;
// 	int		f = 42;
// 	int		g = 25;
// 	int		h = 4200;
// 	int		i = 8;
// 	int		j = -12;
// 	int		k = 123456789;
// 	int		l = 0;
// 	int		m = -12345678;
// 	char	*n = "abcdefghijklmnop";
// 	char	*o = "-a";
// 	char	*p = "-12";
// 	char	*q = "0";
// 	char	*r = "%%";
// 	char	*s = "-2147483648";
// 	char	*t = "0x12345678";
// 	char	*u = "-0";

// 	ft_printf("%.1%");
// 	printf("\n");
// 	printf("%.1%");

// 	// printf("\nresult_ft: %d\n\n", ft_printf("%1.d", l));
// 	// printf("\nresult_c : %d\n\n",    printf("%1.d", l));

// 	// printf("\nresult_ft: %d\n\n", ft_printf("%8c %-8c %-8c", 'm', 'a', 'c'));
// 	// printf("\nresult_c : %d\n",    printf("%8c %-8c %-8c", 'm', 'a', 'c'));

// 	// printf("\nresult_ft: %d\n\n", ft_printf("%.18s", NULL));
// 	// printf("\nresult_c : %d\n",      printf("%.18s", NULL));

// 	// printf("\nresult_ft: %d\n\n", ft_printf("%2.1s", "biba"));
// 	// printf("\nresult_c : %d\n",      printf("%2.1s", "biba"));

// 	// printf("\nresult_ft: %d\n\n", ft_printf("%04i", 9));
// 	// printf("\nresult_c : %d\n",      printf("%04i", 9));

// 	// printf("\nresult_ft: %d\n\n", ft_printf("%.1d", 99));
// 	// printf("\nresult_c : %d\n",      printf("%.1d", 99));

// 	// printf("\nresult_ft: %d\n\n", ft_printf("%.2u", -1));
// 	// printf("\nresult_c : %d\n",      printf("%.2u", -1));

// 	// printf("\nresult_ft: %d\n\n", ft_printf("%50.23x", -42));
// 	// printf("\nresult_c : %d\n",      printf("%50.23x", -42));

// 	// printf("\nresult_ft: %d\n\n", ft_printf("%#50.23X", 0));
// 	// printf("\nresult_c : %d\n",      printf("%#50.23X", 0));

// 	// printf("\nresult_ft: %d\n\n", ft_printf("%-2p", 1));
// 	// printf("\nresult_c : %d\n",      printf("%-2p", 1));

// 	// printf("\nresult_ft: %d\n\n", ft_printf("%6.5%"));
// 	// printf("\nresult_c : %d\n",      printf("%6.5%"));

// 	// unsigned int	biba = -55;
// 	// char *boba = ft_itoa(biba);
// 	// while (*boba)
// 	// 	write(1,boba++,1);	

// 	// while (1)
// 	// {
// 	// }
// }

// printf("\n$ dot=%d 0=%d prc=%d spc=%d +=%d len=%d wdt=%d $\n", box->dot,
// 	box->zero, box->precision, box->space, box->plus, slen, box->width);