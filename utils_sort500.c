/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:59:55 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 14:04:06 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	ft_findhighestval(t_lst **stack_b, t_lst **stack_a,
	int highestcontent, int *schalter)
{
	if (ft_ishighval(*stack_b, highestcontent, schalter))
	{
		pa(stack_b, stack_a);
		highestcontent--;
	}
	else if (ft_ishighval(*stack_b, highestcontent, schalter))
	{
		rrb(stack_b);
		pa(stack_b, stack_a);
		highestcontent--;
	}
	else if (ft_highestinupperhalf(stack_b, highestcontent, *schalter))
		rb(stack_b);
	else
		rrb(stack_b);
	return (highestcontent);
}
