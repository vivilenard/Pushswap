/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:21:15 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/18 21:41:29 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
		}
		else
		{
			node_a = node_a->next;
			ra(stack_a);
		}
	}
}

int	ft_ishighval(t_lst *node, int highestcontent, int *schalter)
{
	if (node->content == highestcontent)
		return (1);
	else if (node->content == highestcontent + *schalter)
	{
		if (*schalter == -1)
			*schalter = 1;
		else if (*schalter == 1)
			*schalter = -1;
		return (1);
	}
	else
		return (0);
}

int	ft_highestinupperhalf(t_lst **stack_b, int highestcontent, int schalter)
{
	int		sizeupperhalf;
	t_lst	*node;

	node = *stack_b;
	sizeupperhalf = ft_listsize(*stack_b) / 2;
	while (sizeupperhalf-- && node)
	{
		if (ft_ishighval(node, highestcontent, &schalter))
			return (1);
		node = node->next;
	}
	return (0);
}

void	ft_clean_b(t_lst **stack_a, t_lst **stack_b)
{
	int		highestcontent;
	int		schalter;
	int		i;

	i = 0;
	schalter = -1;
	highestcontent = ft_listsize(*stack_b);
	while (ft_listsize(*stack_b) > 0)
	{
		if (ft_ishighval(*stack_b, highestcontent, &schalter))
		{
			pa(stack_b, stack_a);
			highestcontent--;
		}
		else if (ft_ishighval(*stack_b, highestcontent, &schalter))
		{
			rrb(stack_b);
			pa(stack_b, stack_a);
			highestcontent--;
		}
		else if (ft_highestinupperhalf(stack_b, highestcontent, schalter))
			rb(stack_b);
		else
			rrb(stack_b);
		if ((ft_listsize(*stack_a) > 1) && (*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
		i++;
	}
}

void	sort500(t_lst **stack_a)
{
	t_lst	*imaginary;
	t_lst	**stack_b;
	int		groupsize;
	int		groupstart;
	int		amount;

	imaginary = NULL;
	stack_b = &imaginary;
	groupsize = 20;
	amount = 100;
	if (ft_listsize(*stack_a) > 100)
	{
		amount = 500;
		groupsize = 62;
	}
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
	if (ft_listsize(*stack_a) == 3)
		sort3(stack_a);
	if (ft_listsize(*stack_a) == 2)
		sort2(stack_a);
	if (ft_listsize(*stack_b) < groupsize)
		groupsize = ft_listsize(*stack_b);
	ft_clean_b(stack_a, stack_b);
	ft_deletelst(stack_b);
}
