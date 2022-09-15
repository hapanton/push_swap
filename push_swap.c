/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:40:58 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/15 20:02:52 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static void	cleaner(long long **arr, t_list **list_a)
{
	ft_lstclear(list_a);
	free (*arr);
}

static void	iterator(t_list **list_a, t_list **list_b)
{
	count_score_a_r_rr(list_a, list_b);
	count_score_b_r_rr(list_b);
	make_decision(list_a, list_b);
}

static void	finisher(t_list **list_a)
{
	final_sort(list_a);
	ft_lstclear(list_a);
}

int	main(int argc, char **argv)
{
	long long	*arr;
	t_list		*list_a;
	t_list		*list_b;
	t_values	*val;

	arr = fill_list_a(argc, argv, &list_a);
	if (arr == NULL)
		return (-1);
	if (already_sorted(&list_a))
	{
		cleaner(&arr, &list_a);
		return (0);
	}
	val = fill_val(&arr);
	if (val == NULL)
		return (-1);
	list_b = NULL;
	if (val->size > 3)
		fill_list_b(&list_a, &list_b, val);
	if (val->size > 2)
		triple_sort(&list_a);
	while (list_b)
		iterator(&list_a, &list_b);
	finisher(&list_a);
	free(val);
}
