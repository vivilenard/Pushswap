/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:00:38 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 15:02:19 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_deletelst(t_lst **lst)
{
	t_lst	*node;

	while ((*lst))
	{
		node = ft_onebeforelastlst(*lst);
		if (!node)
			return (free(*lst));
		free(ft_lastlst(*lst));
		node->next = NULL;
	}
}

void	ft_assignpositivenumbers(t_lst **lst)
{
	int		i;
	int		listsize;
	t_lst	*smallestnode;

	listsize = ft_listsize(*lst);
	i = 1;
	while (i <= listsize)
	{
		smallestnode = ft_smallestvalue(lst);
		smallestnode->content = i;
		i++;
	}
}

t_lst	*ft_createlst(t_lst **lst, char **argv, int i, int n)
{
	char	**s;
	t_lst	*beginning;

	while (argv[i])
	{
		n = -1;
		s = ft_split(argv[i], ' ');
		if (!s[0])
			return (stop(lst), ft_freedoublepointer(s), NULL);
		if (!beginning)
		{
			if (ft_wronginput(beginning, s[0]) == 0)
				return (ft_freedoublepointer(s), NULL);
			beginning = ft_newlist(s[0]);
			*lst = beginning;
			n++;
		}
		if (ft_addnode(lst, beginning, s, n + 1) == 0)
			return (NULL);
		if (s)
			ft_freedoublepointer(s);
		i++;
	}
	return (beginning);
}

int	ft_issorted(t_lst **lst)
{
	t_lst	*node;

	node = *lst;
	while (node->next != NULL)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_lst	*stack_a;
	t_lst	*stack_b;
	int		listsize;

	if (argc < 2)
		return (0);
	stack_a = ft_createlst(&stack_a, argv, 1, 0);
	if (!stack_a)
		return (0);
	ft_assignpositivenumbers(&stack_a);
	listsize = ft_listsize(stack_a);
	if (ft_listsize(stack_a) == 1 || ft_issorted(&stack_a))
		return (ft_deletelst(&stack_a), 0);
	if (listsize <= 3)
		sort3(&stack_a, listsize);
	else if (listsize <= 5)
		sort5(&stack_a, &stack_b, listsize);
	else if (listsize <= 500)
		sort500(&stack_a, &stack_b, listsize, 20);
	return (ft_deletelst(&stack_a), 0);
}