/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:49:01 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/15 19:55:06 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
// #include <stdio.h>

long long	*fill_list_a(int argc, char **argv, t_list **list_a)
{
	long long	*arr;
	int			i;
	t_list		*iter_a;

	arr = parsing_1(argc, argv);
	if (arr == NULL)
		return (NULL);
	*list_a = ft_lstnew(arr[1]);
	i = 2;
	while (i < arr[0] + 1)
	{
		iter_a = ft_lstnew(arr[i]);
		ft_lstadd_back(list_a, iter_a);
		iter_a = iter_a->next;
		i++;
	}
	bubble_sort(&arr);
	return (arr);
}

void	fill_list_b(t_list **list_a, t_list **list_b, t_values *val)
{
	t_list		*iter_a;
	int			i;

	iter_a = *list_a;
	i = 0;
	while (i < val->size)
	{
		if ((iter_a->content != val->min) && (iter_a->content != val->med)
			&& (iter_a->content != val->max))
		{
			iter_a = iter_a->next;
			make_pb(list_a, list_b, 1);
		}
		else
		{
			iter_a = iter_a->next;
			make_ra(list_a, 1);
		}
		i++;
	}
}

t_values	*fill_val(long long **arr)
{
	t_values	*val;

	if (*arr == NULL)
		return (NULL);
	val = (t_values *)malloc(sizeof(t_values) * 10);
	if (val == NULL)
	{
		free(*arr);
		return (NULL);
	}
	val->size = (int)arr[0][0];
	val->min = (int)arr[0][1];
	val->med = (int)arr[0][arr[0][0] / 2];
	val->max = (int)arr[0][arr[0][0]];
	free(*arr);
	return (val);
}
