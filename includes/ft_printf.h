/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:38:24 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/15 19:44:55 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);

typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	int		zero;
	int		dot;
	int		dash;
	int		sgn;
	int		space;
	int		num;
	int		plus;
}		t_print;

size_t	ft_strlen(const char *s);
void	*ft_bzero(void *b, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
int		ft_unsigned_numlen(unsigned int n);
char	*ft_unsigned_itoa(unsigned int n);

char	*upper_hexadec(unsigned int n);
char	*lower_hexadec(unsigned long long n);

t_print	*struct_initialize(t_print *box);
char	*ft_strrev(char *str);

int		print_char(t_print *box);
int		print_string(t_print *box);
int		print_integer(t_print *box);
int		print_unsigned(t_print *box);
int		print_lhexadecimal(t_print *box);
int		print_uhexadecimal(t_print *box);
int		print_address(t_print *box);
int		print_percent(t_print *box);

#endif
