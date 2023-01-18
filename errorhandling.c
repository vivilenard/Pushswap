/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:23:24 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/18 20:29:12 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stop(t_lst **lst)
{
	ft_deletelst(lst);
	ft_putstr_fd("Error\n", 2);
	
}

int	ft_samevalue(t_lst *lst, char *s)  //funktioniert nicht so wie es sollte
{
	t_lst *node;
	node = lst;
	while (node != NULL && ft_listsize(lst) >= 1)
	{
		//	ft_printf("node: %d, s %d", node->value, ft_atoi(s));
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

