/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3and5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:26:55 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 11:29:19 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort2(t_lst **lst)
{
	if (one(*lst) > two(*lst))
		sa(lst);
}

void	sort3(t_lst **lst, int listsize)
{
	if (listsize <= 2)
		sort2(lst);
	if (one(*lst) > two(*lst)
		&& (two(*lst) > three(*lst) || three(*lst) > one(*lst)))
		sa(lst);
	if (one(*lst) < two(*lst) && one(*lst) < three(*lst)
		&& two(*lst) > three(*lst))
		sa(lst);
	if (one(*lst) < two(*lst) && two(*lst) > three(*lst))
		rra(lst);
	if (one(*lst) > two(*lst))
		ra(lst);
}

void	ft_reduceto3(t_lst **stack_a, t_lst **stack_b)
{
	int	i;

	while (ft_listsize(*stack_a) > 3)
	{
		i = placeoflowestvalue(*stack_a);
		if (i <= 2)
		{
			while (i-- >= 0 && i > 0)
				ra(stack_a);
		}
		else
		{
			i = ft_listsize(*stack_a) - placeoflowestvalue(*stack_a);
			while (i-- >= 0 && placeoflowestvalue(*stack_a) > 0)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
}

void	sort5(t_lst **stack_a, int listsize)
{
	t_lst	*imaginary;
	t_lst	**stack_b;

	imaginary = NULL;
	stack_b = &imaginary;
	ft_reduceto3(stack_a, stack_b);
	sort3(stack_a, listsize);
	pa(stack_b, stack_a);
	if (*stack_b)
		pa(stack_b, stack_a);
	ft_deletelst(stack_b);
}
