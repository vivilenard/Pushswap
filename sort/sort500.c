/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:21:15 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 17:23:38 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_lst	*ft_pushme(t_lst **stack_a, t_lst **stack_b,
	t_lst *node_a, int meridian)
{
	if (node_a->content >= meridian)
	{
		node_a = node_a->next;
		pb(stack_a, stack_b);
	}
	else if (node_a->content < meridian)
	{
		node_a = node_a->next;
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	return (node_a);
}

void	ft_group_to_b(t_lst **stack_a,
	t_lst **stack_b, int groupstart, int groupsize)
{
	t_lst	*node_a;
	int		listsize_a;
	int		meridian;

	listsize_a = ft_listsize(*stack_a);
	node_a = *stack_a;
	meridian = groupstart + groupsize / 2;
	while (listsize_a-- > 0)
	{
		if (node_a->content >= groupstart
			&& node_a->content < groupstart + groupsize)
			node_a = ft_pushme(stack_a, stack_b, node_a, meridian);
		else
		{
			node_a = node_a->next;
			ra(stack_a);
		}
	}
}

void	ft_clean_b(t_lst **stack_a, t_lst **stack_b)
{
	int		highestcontent;
	int		schalter;

	schalter = -1;
	highestcontent = ft_listsize(*stack_b);
	while (ft_listsize(*stack_b) > 0)
	{
		highestcontent = ft_findhighestval(stack_b,
				stack_a, highestcontent, &schalter);
		if ((ft_listsize(*stack_a) > 1)
			&& (*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
}

void	ft_push_to_b(t_lst **stack_a, t_lst **stack_b,
	int amount, int groupsize)
{
	int	groupstart;

	groupstart = 1;
	while (ft_listsize(*stack_a) > 3)
	{
		if (amount == 500)
			groupsize -= 3;
		if (ft_listsize(*stack_a) <= groupsize)
			groupsize = ft_listsize(*stack_a) - 3;
		ft_group_to_b(stack_a, stack_b, groupstart, groupsize);
		groupstart += groupsize;
	}
}

void	sort500(t_lst **stack_a, t_lst **stack_b, int listsize, int groupsize)
{
	int		amount;

	amount = 100;
	if (listsize > 100)
	{
		amount = 500;
		groupsize = 62;
	}
	ft_push_to_b(stack_a, stack_b, amount, groupsize);
	if (ft_listsize(*stack_a) == 3)
		sort3(stack_a, listsize);
	ft_clean_b(stack_a, stack_b);
}
