/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:15:35 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/06 01:31:13 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	count_score_b_r_rr(t_list **list_b)
{
	int		i;
	int		size;
	t_list	*iter;

	iter = *list_b;
	size = list_size(iter);
	i = 0;
	while (iter)
	{
		iter->b_r = i;
		iter->b_rr = size - i;
		iter = iter->next;
		i++;
	}
}

static int	count_helper(t_list **iter_a, t_list **iter_b, int *i, int a_size)
{
	while (*iter_a && ((*iter_a)->content > (*iter_b)->content))
	{
		*i += 1;
		*iter_a = (*iter_a)->next;
	}
	if ((*iter_a)->content < (*iter_b)->content && ((*iter_a)->next) == NULL)
	{
		(*iter_b)->a_r = *i;
		(*iter_b)->a_rr = (a_size - *i);
		return (-1);
	}
	else if ((*iter_a)->content < (*iter_b)->content
		&& ((*iter_a)->next)->content > (*iter_b)->content)
	{
		(*iter_b)->a_r = *i;
		(*iter_b)->a_rr = (a_size - *i);
		return (-1);
	}
	else
	{
		(*iter_a) = (*iter_a)->next;
		*i += 1;
	}
	return (0);
}

void	count_score_a_r_rr(t_list **list_a, t_list **list_b)
{
	t_list	*iter_a;
	t_list	*iter_b;
	int		i;
	int		a_size;

	a_size = list_size(*list_a);
	iter_b = *list_b;
	while (iter_b)
	{
		iter_a = *list_a;
		i = 1;
		while (iter_a)
		{
			if (count_helper(&iter_a, &iter_b, &i, a_size) == -1)
				break ;
		}
		iter_b = iter_b->next;
	}
}
