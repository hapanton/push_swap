/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:39:54 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/11 23:07:11 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_values
{
	int	min;
	int	med;
	int	max;
	int	size;
}		t_values;

int			list_size(t_list *list);
void		bubble_sort(long long **arr);
void		print_stacks(t_list *list_a, t_list *list_b);
int			ft_max(int a, int b);
int			ft_min(int a, int b);

void		count_score_b_r_rr(t_list **list_b);
void		count_score_a_r_rr(t_list **list_a, t_list **list_b);

void		initiate_r(t_list **list_a, t_list **list_b, t_list **node);
void		initiate_rr(t_list **list_a, t_list **list_b, t_list **node);
void		initiate_ra_rrb(t_list **list_a, t_list **list_b, t_list **node);
void		initiate_rra_rb(t_list **list_a, t_list **list_b, t_list **node);

void		triple_sort(t_list **list_a);
void		final_sort(t_list **list_a);
int			already_sorted(t_list **list_a);

void		make_decision(t_list **list_a, t_list **list_b);

long long	*fill_list_a(int argc, char **argv, t_list **list_a);
void		fill_list_b(t_list **list_a, t_list **list_b, t_values *val);
t_values	*fill_val(long long **arr);

long long	ft_ll_atoi(const char *str);
long long	*parsing_1(int argc, char **argv);
size_t		ft_arrlen(char **arr);
void		make_sa(t_list **list_a, int flag);
void		make_sb(t_list **list_b, int flag);
void		make_ss(t_list **list_a, t_list **list_b, int flag);
void		make_pa(t_list **list_a, t_list **list_b, int flag);
void		make_pb(t_list **list_a, t_list **list_b, int flag);
void		make_ra(t_list **list_a, int flag);
void		make_rb(t_list **list_b, int flag);
void		make_rr(t_list **list_a, t_list **list_b, int flag);
void		make_rra(t_list **list_a, int flag);
void		make_rrb(t_list **list_b, int flag);
void		make_rrr(t_list **list_a, t_list **list_b, int flag);

#endif
