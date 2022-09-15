/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsergean <qsergean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 19:47:27 by qsergean          #+#    #+#             */
/*   Updated: 2022/03/06 00:29:13 by qsergean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/ft_printf.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*iter;

	if (lst == NULL)
		return (NULL);
	iter = lst;
	while (iter->next)
		iter = iter->next;
	return (iter);
}
