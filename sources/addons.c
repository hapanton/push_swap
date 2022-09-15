/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:36:06 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/06 00:08:40 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/ft_printf.h"

int	list_size(t_list *list)
{
	t_list	*iter;
	int		i;

	iter = list;
	i = 0;
	while (iter)
	{
		i++;
		iter = iter->next;
	}
	return (i);
}

void	bubble_sort(long long **arr)
{
	int			i;
	int			j;
	long long	tmp;

	i = 0;
	while (i < arr[0][0])
	{
		j = 1;
		while (j < arr[0][0] - i)
		{
			if (arr[0][j] > arr[0][j + 1])
			{
				tmp = arr[0][j];
				arr[0][j] = arr[0][j + 1];
				arr[0][j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	print_stacks(t_list *list_a, t_list *list_b)
{
	t_list	*iter_p;

	iter_p = list_a;
	ft_printf("\n*-STACK_A-*\n");
	while (iter_p)
	{
		ft_printf("|   %-6d|\n", (int)(iter_p->content));
		iter_p = iter_p->next;
	}
	ft_printf("*---------*\n");
	iter_p = list_b;
	ft_printf("\n*-STACK_B-*\n");
	while (iter_p)
	{
		ft_printf("|   %-6d|\n", (int)(iter_p->content));
		iter_p = iter_p->next;
	}
	ft_printf("*---------*\n\n");
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
