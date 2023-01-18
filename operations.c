/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:03:02 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/18 21:40:32 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
