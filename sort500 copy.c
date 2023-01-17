/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort500.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:21:15 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/13 15:56:47 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_group_to_b(t_lst **stack_a, t_lst **stack_b, int groupbeginning, int groupsize)
{
	t_lst	*node_a;
	int		listsize_a;
	int		listsize_b;
	int		sorted_out;

	listsize_a = ft_listsize(*stack_a);
	listsize_b = ft_listsize(*stack_b);	//do i need?
	//ft_printf("LISTSIZE %d\n", listsize);
	node_a = *stack_a;
	sorted_out = 0;
	while (listsize_a-- > 0)
	{
		if (node_a->content >= groupbeginning && node_a->content < groupbeginning + groupsize)
		{
			//if (node_a->content >= groupbeginning + groupsize)// / 2) //go to top
			//{
				node_a = node_a->next;
				pb(stack_a, stack_b);
				sorted_out++;
			//}
			// else // is it necessary to divide in smaller and bigger? Do i need a pivot ?(one extra move per shift)
			// {
			// 	node_a = node_a->next;
			// 	pb(stack_a, stack_b);
			// 	rb(stack_b);
			// }
		//ft_printf("%d\n", sorted_out);
		}
		// else if (sorted_out == 20 && (groupbeginning > (listsize_a + groupsize) / 2))
		// {
		// 	ft_printf("GB %d\n", groupbeginning);
		// 	ft_printlst(*stack_a);
		// 	while (ft_lastlst(*stack_a)->state == 0)
		// 		rra(stack_a);											//TODO lst create state and set it to 0 and to 1 if sorted
			// break;
		// }
		else
		{
			node_a = node_a->next;
			ra(stack_a);
		}
	}
}

// int	ft_placeof(t_lst *node, int n)
// {
// 	int	place;

// 	place = 0;
// 	while (node != NULL)
// 	{
// 		if (node->content == n)
// 			break;
// 		node = node->next;
// 		place++;
// 	}
// 	return (place);
// }

void	ft_clean_b(t_lst **stack_a, t_lst **stack_b, int smallestcontent, int groupsize)
{
	t_lst *node_b;
	//int		highestcontent;
	node_b = *stack_b;
	
	//highestcontent = smallestcontent + groupsize - 1;	//hae 19?
	while (ft_listsize(*stack_b) > 0)
	{
		// if (node_b->content == highestcontent)
		// {
		// 	node_b = node_b->next;
		// 	pa(stack_b, stack_a);
		// 	highestcontent++;
		// }
		if (node_b->content == smallestcontent)
		{
			node_b->state = 1;
			node_b = node_b->next;
			pa(stack_b, stack_a);
			ra(stack_a);
			smallestcontent++;
			groupsize--;
		}
		else
		{
			//if (ft_placeof(*stack_b, smallestcontent) >= 0)//groupsize / 2)
				node_b = node_b->next;
				rb(stack_b);
		}
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
				//ft_printlst(*stack_a);
				//ft_printlst(*stack_b);
		ft_clean_b(stack_a, stack_b, groupbeginning, groupsize);
		groupbeginning += groupsize;
	}
	//ft_pushgroup(stack_a, stack_b, groupbeginning, groupsize);
	ft_deletelst(stack_b);
}


//put first 25 in B and sort them
//put them back
//put next 25 and sort them