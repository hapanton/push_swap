/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:23:55 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/11 22:51:17 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	triple_sort(t_list **list_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = *list_a;
	second = first->next;
	third = second->next;
	if (((first->content > second->content) && (second->content
				> third->content) && (first->content > third->content))
		|| (first->content > second->content && second->content
			< third->content && first->content < third->content)
		|| (first->content < second->content && second->content
			> third->content && first->content < third->content))
		make_sa(list_a, 1);
}

static int	count_r(t_list **list_a, t_list *min)
{
	t_list	*iter;
	int		r;

	r = 0;
	iter = *list_a;
	while (iter)
	{
		if (iter->content == min->content)
			break ;
		r++;
		iter = iter->next;
	}
	return (r);
}

void	final_sort(t_list **list_a)
{
	t_list	*iter;
	t_list	*min;
	int		r;
	int		rr;

	min = *list_a;
	iter = (*list_a)->next;
	while (iter)
	{
		if (iter->content < min->content)
			min = iter;
		iter = iter->next;
	}
	r = count_r(list_a, min);
	rr = list_size(*list_a) - r;
	if (r < rr)
	{
		while (r--)
			make_ra(list_a, 1);
	}
	else
	{
		while (rr--)
			make_rra(list_a, 1);
	}
}

int	already_sorted(t_list **list_a)
{
	t_list	*iter_a;

	iter_a = *list_a;
	while (iter_a && iter_a->next)
	{
		if (iter_a->content > (iter_a->next)->content)
			return (0);
		iter_a = iter_a->next;
	}
	return (1);
}
