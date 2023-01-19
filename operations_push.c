/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:52:38 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 13:53:54 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_lst **containing, t_lst **recieving)
{
	t_lst	*node_to_shift;

	if (!containing)
		return ;
	node_to_shift = *containing;
	*containing = (*containing)->next;
	if (*recieving == NULL)
	{
		*recieving = node_to_shift;
		node_to_shift->next = NULL;
	}
	else
	{
		node_to_shift->next = *recieving;
		*recieving = node_to_shift;
	}
}

void	pb(t_lst **stack_a, t_lst **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	pa(t_lst **stack_b, t_lst **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}
