/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:36:03 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/18 21:38:22 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_lst	*ft_newlist(char *content)
{
	t_lst	*lst;

	lst = (t_lst *)malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->value = ft_atoi(content);
	lst->next = NULL;
	return (lst);
}

void	ft_lstaddback(t_lst *lst, char *content)
{
	t_lst	*new;

	new = ft_newlist(content);
	lst->next = new;
}

t_lst	*ft_lastlst(t_lst *begin)
{
	t_lst	*lst;

	lst = begin;
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	ft_listsize(t_lst *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

t_lst	*ft_onebeforelastlst(t_lst *begin)
{
	t_lst	*lst;

	lst = begin;
	if (!lst || ft_listsize(lst) < 2)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
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
