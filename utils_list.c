/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:36:03 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 14:06:20 by vlenard          ###   ########.fr       */
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
	lst->content = 0;
	lst->next = NULL;
	return (lst);
}

t_lst	*ft_lstaddback(t_lst *lst, char *content)
{
	t_lst	*new;

	new = ft_newlist(content);
	lst->next = new;
	return (new);
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
