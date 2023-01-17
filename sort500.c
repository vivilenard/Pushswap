/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:21:15 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/17 17:04:37 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_group_to_b(t_lst **stack_a, t_lst **stack_b, int groupbeginning, int groupsize)
{
	t_lst	*node_a;
	int		listsize_a;
	int		meridian;

	listsize_a = ft_listsize(*stack_a);
	node_a = *stack_a;
	meridian = groupbeginning + groupsize / 2;
	while (listsize_a-- > 0)
	{
		if (node_a->content >= groupbeginning && node_a->content < groupbeginning + groupsize)
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

int ft_highestinupperhalf(t_lst **stack_b, int highestcontent, int schalter)
{
	int	sizeupperhalf;
	t_lst *node;

	node = *stack_b;
	sizeupperhalf = ft_listsize(*stack_b) / 2;
	while(sizeupperhalf-- && node)
	{
		if (ft_ishighval(node, highestcontent, &schalter))
			return (1);
		node = node->next;
	}
	return (0);
}
void	ft_clean_b(t_lst **stack_a, t_lst **stack_b) //int groupbeginning, int groupsize)
{																						//hier bin ich
	int		highestcontent;
	int		i = 0;
	int		schalter;
	
	schalter = -1;
	highestcontent = ft_listsize(*stack_b);
			//ft_printlst(*stack_b);
	//ft_printf("GB %d\nGZ %d\nHighestc %d\n", groupbeginning, groupsize, highestcontent);
	while (ft_listsize(*stack_b) > 0)
	{
		if (ft_ishighval(*stack_b, highestcontent, &schalter))
		{
			pa(stack_b, stack_a);
					//ft_printlst(*stack_b);
					//ft_printlst(*stack_a);
			highestcontent--;
		}
		else if (ft_ishighval(*stack_b, highestcontent, &schalter))
		{
			rrb(stack_b);
			pa(stack_b, stack_a);
					//ft_printlst(*stack_b);
					//ft_printlst(*stack_a);
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

void	sort500(t_lst **stack_a, int listsize)
{
	t_lst	*imaginary;
	t_lst	**stack_b;
	int		groupsize;
	int		groupbeginning;
	int		movements;
	
	imaginary = NULL;
	stack_b = &imaginary;
	groupsize = 20;
	groupbeginning = 1;
	movements = listsize / groupsize;
	while (movements-- >= 0)
	{
		ft_group_to_b(stack_a, stack_b, groupbeginning, groupsize);
		groupbeginning += groupsize;
	}
	// ft_printlst(*stack_b);
	// movements = listsize / groupsize;
	// while (movements-- >= 0)
	// {
	// 	ft_clean_b(stack_a, stack_b, groupbeginning, groupsize);
	// 	groupbeginning += groupsize;
	// }
	if (ft_listsize(*stack_b) < groupsize)
		groupsize = ft_listsize(*stack_b);
	ft_clean_b(stack_a, stack_b);
	ft_deletelst(stack_b);
}


//put first 25 in B and sort them
//put them back
//put next 25 and sort them

// void	ft_clean_b(t_lst **stack_a, t_lst **stack_b, int smallestcontent, int groupsize)
// {
// 	t_lst *node_b;
// 	node_b = *stack_b;
	
// 	while (ft_listsize(*stack_b) > 0)
// 	{
// 		if (node_b->content == smallestcontent)
// 		{
// 			node_b->state = 1;
// 			node_b = node_b->next;
// 			pa(stack_b, stack_a);
// 			ra(stack_a);
// 			smallestcontent++;
// 			groupsize--;
// 		}
// 		else
// 		{
// 				node_b = node_b->next;
// 				rb(stack_b);
// 		}
// 	}
// }