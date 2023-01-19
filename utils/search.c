/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:22:56 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 15:07:32 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_lst	*ft_smallestvalue(t_lst **lst)
{
	t_lst	*smallestnode;
	t_lst	*highestnode;
	t_lst	*node;

	node = *lst;
	highestnode = node;
	while (node)
	{
		if (node->value > highestnode->value)
			highestnode = node;
		node = node->next;
	}
	smallestnode = highestnode;
	node = *lst;
	while (node)
	{
		if ((node->value < smallestnode->value) && node->content == 0)
			smallestnode = node;
		node = node->next;
	}
	return (smallestnode);
}

t_lst	*ft_smallestnode(t_lst *node)
{
	t_lst	*smallestnode;

	smallestnode = node;
	while (node)
	{
		if (node->content < smallestnode->content)
			smallestnode = node;
		node = node->next;
	}
	return (smallestnode);
}

int	placeoflowestvalue(t_lst *node)
{
	t_lst	*lowestval;
	int		i;
	int		placeoflowestval;

	lowestval = node;
	placeoflowestval = -1;
	i = 0;
	while (node)
	{
		if (node->content < lowestval->content)
		{
			lowestval = node;
			placeoflowestval = i;
		}
		node = node->next;
		i++;
	}
	return (placeoflowestval + 1);
}
