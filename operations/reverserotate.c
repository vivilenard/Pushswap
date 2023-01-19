/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:51:25 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 14:12:45 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	reverserotate(t_lst **lst)
{
	t_lst	*front;
	t_lst	*onebeforelast;

	if (!lst || !(*lst)->next)
		return ;
	front = ft_lastlst(*lst);
	onebeforelast = ft_onebeforelastlst(*lst);
	front->next = *lst;
	onebeforelast->next = NULL;
	*lst = front;
}

void	rra(t_lst **lst)
{
	reverserotate(lst);
	ft_printf("rra\n");
}

void	rrb(t_lst **lst)
{
	reverserotate(lst);
	ft_printf("rrb\n");
}
