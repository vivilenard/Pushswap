/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:51:28 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 14:12:48 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rotate(t_lst **lst)
{
	t_lst	*second;

	if (!lst || !(*lst)->next)
		return ;
	second = (*lst)->next;
	ft_lastlst(*lst)->next = *lst;
	(*lst)->next = NULL;
	*lst = second;
}

void	ra(t_lst **lst)
{
	rotate(lst);
	ft_printf("ra\n");
}

void	rb(t_lst **lst)
{
	rotate(lst);
	ft_printf("rb\n");
}
