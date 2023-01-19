/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:00:38 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 11:09:19 by vlenard          ###   ########.fr       */
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

int	ft_addnode(t_lst **lst, char **s, int n)
{
	while (s[++n])
	{
		if (ft_wronginput(*lst, s[n]) == 0)
			return (ft_freedoublepointer(s), 0);
		*lst = ft_lstaddback(*lst, s[n]);
	}
	return (1);
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
		if (ft_addnode(lst, s, n) == 0)
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
	t_lst	*lst;
	int		listsize;

	lst = NULL;
	if (argc < 2)
		return (0);
	lst = ft_createlst(&lst, argv, 1, 0);
	if (!lst)
		return (0);
	ft_assignpositivenumbers(&lst);
	listsize = ft_listsize(lst);
	if (ft_listsize(lst) == 1 || ft_issorted(&lst))
		return (ft_deletelst(&lst), 0);
	if (listsize <= 2)
		sort2(&lst);
	else if (listsize <= 3)
		sort3(&lst);
	else if (listsize <= 5)
		sort5(&lst);
	else if (listsize <= 500)
		sort500(&lst);
	return (ft_deletelst(&lst), 0);
}
//Pfad: ~/Documents/coding/pushswap/push_swap