/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeitbeautiful.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:40:00 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 15:07:04 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	one(t_lst *lst)
{
	return (lst->content);
}

int	two(t_lst *lst)
{
	return (lst->next->content);
}

int	three(t_lst *lst)
{
	return (lst->next->next->content);
}

int	ft_addnode(t_lst **lst, t_lst *beginning, char **s, int n)
{
	while (s[n])
	{
		if (ft_wronginput(beginning, s[n]) == 0)
			return (ft_freedoublepointer(s), 0);
		*lst = ft_lstaddback(*lst, s[n]);
		n++;
	}
	return (1);
}

void	ft_printlst(t_lst *lst)
{
	ft_printf("---------\n");
	while (lst)
	{
		ft_printf("_%d_ (%d)\n", lst->content, lst->value);
		lst = lst->next;
	}
	ft_printf("---------\n");
}
