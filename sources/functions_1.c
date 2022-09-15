/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:21:41 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/11 22:43:27 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_sa(t_list **list_a, int flag)
{
	t_list	*tmp;
	t_list	*nxt;

	if (*list_a && (*list_a)->next)
	{
		tmp = *list_a;
		nxt = (*list_a)->next;
		(*list_a)->next = nxt->next;
		nxt->next = tmp;
		(*list_a) = nxt;
	}
	if (flag)
		write (1, &"sa\n", 3);
}

void	make_sb(t_list **list_b, int flag)
{
	t_list	*tmp;
	t_list	*nxt;

	if (*list_b && (*list_b)->next)
	{
		tmp = *list_b;
		nxt = (*list_b)->next;
		(*list_b)->next = nxt->next;
		nxt->next = tmp;
		(*list_b) = nxt;
	}
	if (flag)
		write (1, &"sb\n", 3);
}

void	make_ss(t_list **list_a, t_list **list_b, int flag)
{
	t_list	*tmp;
	t_list	*nxt;

	if (*list_a && (*list_a)->next)
	{
		tmp = *list_a;
		nxt = (*list_a)->next;
		(*list_a)->next = nxt->next;
		nxt->next = tmp;
		(*list_a) = nxt;
	}
	if (*list_b && (*list_b)->next)
	{
		tmp = *list_b;
		nxt = (*list_b)->next;
		(*list_b)->next = nxt->next;
		nxt->next = tmp;
		(*list_b) = nxt;
	}
	if (flag)
		write (1, &"ss\n", 3);
}

void	make_pa(t_list **list_a, t_list **list_b, int flag)
{
	t_list	*tmp;
	t_list	*p;

	if (*list_b)
	{
		tmp = *list_a;
		p = *list_b;
		*list_b = (*list_b)->next;
		*list_a = p;
		(*list_a)->next = tmp;
	}
	if (flag)
		write (1, &"pa\n", 3);
}

void	make_pb(t_list **list_a, t_list **list_b, int flag)
{
	t_list	*tmp;
	t_list	*p;

	if (*list_a)
	{
		tmp = *list_b;
		p = *list_a;
		*list_a = (*list_a)->next;
		*list_b = p;
		(*list_b)->next = tmp;
	}
	if (flag)
		write (1, &"pb\n", 3);
}
