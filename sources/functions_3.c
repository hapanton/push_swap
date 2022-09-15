/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:05:35 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/11 22:44:50 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_rr(t_list **list_a, t_list **list_b, int flag)
{
	t_list	*tmp;

	if (*list_a && (*list_a)->next)
	{
		tmp = *list_a;
		*list_a = (*list_a)->next;
		tmp->next = NULL;
		ft_lstadd_back(list_a, tmp);
	}
	if (*list_b && (*list_b)->next)
	{
		tmp = *list_b;
		*list_b = (*list_b)->next;
		tmp->next = NULL;
		ft_lstadd_back(list_b, tmp);
	}
	if (flag)
		write(1, &"rr\n", 3);
}

static void	rrr_helper(t_list **list_a)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *list_a;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = *list_a;
	*list_a = tmp;
	prev->next = NULL;
}

void	make_rrr(t_list **list_a, t_list **list_b, int flag)
{
	t_list	*tmp;
	t_list	*prev;

	if (*list_a && (*list_a)->next)
		rrr_helper(list_a);
	if (*list_b && (*list_b)->next)
	{
		tmp = *list_b;
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		tmp->next = *list_b;
		*list_b = tmp;
		prev->next = NULL;
	}
	if (flag)
		write (1, &"rrr\n", 4);
}
