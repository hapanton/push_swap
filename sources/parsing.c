/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 18:23:20 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/15 19:55:12 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <limits.h>
// #include <stdio.h>

static int	argv_checker(int argc, char **v)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (!v[i][0])
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		j = 0;
		while (v[i][j])
		{
			if ((v[i][j] != ' ' && v[i][j] != '-' && !(v[i][j] >= '0'
				&& v[i][j] <= '9')) || (v[i][j] == '-' && !v[i][j + 1]))
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	reps_checker(long long *arr, long long size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size + 1)
	{
		if (arr[i] > INT_MAX || arr[i] < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		j = size;
		while (j > i)
		{
			if (arr[i] == arr[j])
			{
				write(2, "Error\n", 6);
				return (-1);
			}
			j--;
		}
		i++;
	}
	return (0);
}

static long long	*parsing_2(char **new)
{
	size_t		i;
	long long	*nums;
	size_t		arrlen;

	arrlen = ft_arrlen(new);
	nums = (long long *)malloc(sizeof(long long) * (arrlen + 1));
	if (nums == NULL)
		return (NULL);
	nums[0] = (int)arrlen;
	i = 1;
	while (i < arrlen + 1)
	{
		nums[i] = ft_ll_atoi(new[i - 1]);
		free(new[i - 1]);
		i++;
	}
	free(new);
	if (reps_checker(nums, arrlen) == -1)
	{
		free(nums);
		return (NULL);
	}
	i = 0;
	return (nums);
}

static int	calc_total_len(int argc, char **argv)
{
	int	i;
	int	res;

	i = 1;
	res = argc;
	while (i < argc)
		res += ft_strlen(argv[i++]);
	return (res);
}

long long	*parsing_1(int argc, char **argv)
{
	size_t		i;
	char		*input;
	char		**new;
	int			total_len;

	if (argc < 2)
		return (NULL);
	if (argv_checker(argc, argv) == -1)
		return (NULL);
	total_len = calc_total_len(argc, argv);
	input = ft_strdup_new(argv[1], total_len);
	if (input == NULL)
		return (NULL);
	i = 2;
	while ((int)i < argc)
	{
		ft_strjoin(&input, " ");
		ft_strjoin(&input, argv[i++]);
	}
	new = ft_split(input, ' ');
	free(input);
	return (parsing_2(new));
}
