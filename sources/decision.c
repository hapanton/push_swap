/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 01:33:56 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/15 19:55:34 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	smallest_r_rr(t_list **list_b,
	t_list **res_r, t_list **res_rr)
{
	t_list	*iter;

	*res_r = *list_b;
	*res_rr = *list_b;
	iter = (*list_b)->next;
	while (iter)
	{
		if (ft_max(iter->a_r, iter->b_r)
			< ft_max((*res_r)->a_r, (*res_r)->b_r))
			*res_r = iter;
		if (ft_max(iter->a_rr, iter->b_rr)
			< ft_max((*res_rr)->a_rr, (*res_rr)->b_rr))
			*res_rr = iter;
		iter = iter->next;
	}
}

static void	smallest_ra_rb(t_list **list_b,
	t_list **res_ra_rrb, t_list **res_rra_rb)
{
	t_list	*iter;

	*res_ra_rrb = *list_b;
	*res_rra_rb = *list_b;
	iter = (*list_b)->next;
	while (iter)
	{
		if ((iter->a_r + iter->b_rr)
			< ((*res_ra_rrb)->a_r + (*res_ra_rrb)->b_rr))
			*res_ra_rrb = iter;
		if ((iter->a_rr + iter->b_r)
			< ((*res_rra_rb)->a_rr + (*res_rra_rb)->b_r))
			*res_rra_rb = iter;
		iter = iter->next;
	}
}

void	make_decision(t_list **list_a, t_list **list_b)
{
	t_list	*r;
	t_list	*rr;
	t_list	*ra_rrb;
	t_list	*rra_rb;

	smallest_r_rr(list_b, &r, &rr);
	smallest_ra_rb(list_b, &ra_rrb, &rra_rb);
	if ((ft_max(r->a_r, r->b_r) <= ft_max(rr->a_rr, rr->b_rr))
		&& (ft_max(r->a_r, r->b_r) <= (ra_rrb->a_r + ra_rrb->b_rr))
		&& (ft_max(r->a_r, r->b_r) <= (rra_rb->a_rr + rra_rb->b_r)))
		initiate_r(list_a, list_b, &r);
	else if ((ft_max(rr->a_rr, rr->b_rr) <= ft_max(r->a_r, r->b_r))
		&& (ft_max(rr->a_rr, rr->b_rr) <= (ra_rrb->a_r + ra_rrb->b_rr))
		&& (ft_max(rr->a_rr, rr->b_rr) <= (rra_rb->a_rr + rra_rb->b_r)))
		initiate_rr(list_a, list_b, &rr);
	else if ((ra_rrb->a_r + ra_rrb->b_rr) < (rra_rb->a_rr + rra_rb->b_r))
		initiate_ra_rrb(list_a, list_b, &ra_rrb);
	else
		initiate_rra_rb(list_a, list_b, &rra_rb);
}

size_t	ft_arrlen(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
