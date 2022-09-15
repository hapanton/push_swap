/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:18:02 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/11 22:49:50 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initiate_r(t_list **list_a, t_list **list_b, t_list **node)
{
	int	rr;
	int	ra;
	int	rb;

	rr = ft_min((*node)->a_r, (*node)->b_r);
	ra = (*node)->a_r - rr;
	rb = (*node)->b_r - rr;
	while (rr--)
		make_rr(list_a, list_b, 1);
	while (ra--)
		make_ra(list_a, 1);
	while (rb--)
		make_rb(list_b, 1);
	make_pa(list_a, list_b, 1);
}

void	initiate_rr(t_list **list_a, t_list **list_b, t_list **node)
{
	int	rrr;
	int	rra;
	int	rrb;

	rrr = ft_min((*node)->a_rr, (*node)->b_rr);
	rra = (*node)->a_rr - rrr;
	rrb = (*node)->b_rr - rrr;
	while (rrr--)
		make_rrr(list_a, list_b, 1);
	while (rra--)
		make_rra(list_a, 1);
	while (rrb--)
		make_rrb(list_b, 1);
	make_pa(list_a, list_b, 1);
}

void	initiate_ra_rrb(t_list **list_a, t_list **list_b, t_list **node)
{
	int	ra;
	int	rrb;

	ra = (*node)->a_r;
	rrb = (*node)->b_rr;
	while (ra--)
		make_ra(list_a, 1);
	while (rrb--)
		make_rrb(list_b, 1);
	make_pa(list_a, list_b, 1);
}

void	initiate_rra_rb(t_list **list_a, t_list **list_b, t_list **node)
{
	int	rra;
	int	rb;

	rra = (*node)->a_rr;
	rb = (*node)->b_r;
	while (rra--)
		make_rra(list_a, 1);
	while (rb--)
		make_rb(list_b, 1);
	make_pa(list_a, list_b, 1);
}
