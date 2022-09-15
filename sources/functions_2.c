/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:04:04 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/11 22:45:06 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_ra(t_list **list_a, int flag)
{
	t_list	*tmp;

	if (*list_a && (*list_a)->next)
	{
		tmp = *list_a;
		*list_a = (*list_a)->next;
		tmp->next = NULL;
		ft_lstadd_back(list_a, tmp);
	}
	if (flag)
		write(1, &"ra\n", 3);
}

void	make_rb(t_list **list_b, int flag)
{
	t_list	*tmp;

	if (*list_b && (*list_b)->next)
	{
		tmp = *list_b;
		*list_b = (*list_b)->next;
		tmp->next = NULL;
		ft_lstadd_back(list_b, tmp);
	}
	if (flag)
		write(1, &"rb\n", 3);
}

void	make_rra(t_list **list_a, int flag)
{
	t_list	*tmp;
	t_list	*prev;

	if (*list_a && (*list_a)->next)
	{
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
	if (flag)
		write (1, &"rra\n", 4);
}

void	make_rrb(t_list **list_b, int flag)
{
	t_list	*tmp;
	t_list	*prev;

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
		write (1, &"rrb\n", 4);
}
