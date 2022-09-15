/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:09:48 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/15 21:24:07 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "bonus_files/get_next_line.h"

void	execute_cmd(t_list **list_a, t_list **list_b, char *cmd)
{
	size_t	s;

	s = ft_strlen(cmd) - 1;
	if (!ft_strncmp(cmd, "sa", s))
		make_sa(list_a, 0);
	else if (!ft_strncmp(cmd, "sb", s))
		make_sb(list_b, 0);
	else if (!ft_strncmp(cmd, "ss", s))
		make_ss(list_a, list_b, 0);
	else if (!ft_strncmp(cmd, "pa", s))
		make_pa(list_a, list_b, 0);
	else if (!ft_strncmp(cmd, "pb", s))
		make_pb(list_a, list_b, 0);
	else if (!ft_strncmp(cmd, "ra", s))
		make_ra(list_a, 0);
	else if (!ft_strncmp(cmd, "rb", s))
		make_rb(list_b, 0);
	else if (!ft_strncmp(cmd, "rr", s))
		make_rr(list_a, list_b, 0);
	else if (!ft_strncmp(cmd, "rra", s))
		make_rra(list_a, 0);
	else if (!ft_strncmp(cmd, "rrb", s))
		make_rrb(list_b, 0);
	else if (!ft_strncmp(cmd, "rrr", s))
		make_rrr(list_a, list_b, 0);
}

int	check_cmd(char *cmd)
{
	size_t	s;

	s = ft_strlen(cmd) - 1;
	if (s < 2)
	{
		write(1, &"Error\n", 6);
		return (0);
	}
	if (!ft_strncmp(cmd, "sa", s) || !ft_strncmp(cmd, "sb", s)
		|| !ft_strncmp(cmd, "ss", s) || !ft_strncmp(cmd, "pa", s)
		|| !ft_strncmp(cmd, "pb", s) || !ft_strncmp(cmd, "ra", s)
		|| !ft_strncmp(cmd, "rb", s) || !ft_strncmp(cmd, "rr", s)
		|| !ft_strncmp(cmd, "rra", s) || !ft_strncmp(cmd, "rrb", s)
		|| !ft_strncmp(cmd, "rrr", s))
		return (1);
	write(1, &"Error\n", 6);
	return (0);
}

void	check_and_finish(t_list **list_a, t_list **list_b)
{
	if (*list_b == NULL && already_sorted(list_a))
		write(1, &"OK\n", 3);
	else
		write(1, &"KO\n", 3);
}

static void	free_them(t_list **list_a, t_list **list_b, char **cmd)
{
	ft_lstclear(list_a);
	ft_lstclear(list_b);
	free(*cmd);
}

int	main(int argc, char **argv)
{
	long long	*arr;
	t_list		*list_a;
	t_list		*list_b;
	char		*cmd;

	arr = fill_list_a(argc, argv, &list_a);
	if (arr == NULL)
		return (-1);
	free(arr);
	list_b = NULL;
	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		if (!check_cmd(cmd))
		{
			free_them(&list_a, &list_b, &cmd);
			return (-1);
		}
		execute_cmd(&list_a, &list_b, cmd);
		free(cmd);
	}
	check_and_finish(&list_a, &list_b);
	free_them(&list_a, &list_b, &cmd);
}
