/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:23:24 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 18:23:13 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	stop(t_lst **lst)
{
	ft_deletelst(lst);
	ft_putstr_fd("Error\n", 2);
}

void	ft_deletelst(t_lst **lst)
{
	t_lst	*node;

	while ((*lst))
	{
		node = ft_onebeforelastlst(lst);
		if (!node)
			return (free(*lst));
		free(ft_lastlst(*lst));
		node->next = NULL;
	}
}

int	ft_samevalue(t_lst *lst, char *s)
{
	t_lst	*node;

	node = lst;
	while (node != NULL && ft_listsize(lst) >= 1)
	{
		if (node->value == ft_atoi(s))
			return (0);
		node = node->next;
	}
	return (1);
}

int	ft_nonumber(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_wronginput(t_lst *lst, char *s)
{
	if (!s)
	{
		stop(&lst);
		return (0);
	}
	if (ft_nonumber(s) == 0 || ft_samevalue(lst, s) == 0)
	{
		stop(&lst);
		return (0);
	}
	if (ft_atoi(s) > 2147483647 || ft_atoi(s) < -2147483648)
	{
		stop(&lst);
		return (0);
	}	
	return (1);
}
