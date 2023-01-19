/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:03:02 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 14:06:05 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_lst **lst)
{
	t_lst	*front;
	t_lst	*end;

	front = (*lst)->next;
	end = front->next;
	front->next = (*lst);
	(*lst)->next = end;
	*lst = front;
}

void	sa(t_lst **lst)
{
	swap(lst);
	ft_printf("sa\n");
}

void	sb(t_lst **lst)
{
	swap(lst);
	ft_printf("sa\n");
}
