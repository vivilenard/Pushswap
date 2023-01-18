/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:00:38 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/18 20:57:07 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void ft_deletelst(t_lst **lst)
{
	t_lst	*node;

	while((*lst))
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
	int	i;
	int	listsize;
	t_lst *smallestnode;
	
	listsize = ft_listsize(*lst);
	i = 1;
	while (i <= listsize)
	{
		smallestnode = ft_smallestvalue(lst);
		smallestnode->content = i;
		i++;
	}
}

t_lst	*ft_createlst(t_lst **lstbegin, char **argv)
{
	int		i;
	int		n;
	char	**s;
	t_lst	*node;

	i = 1;
	while (argv[i])
	{
		n = 0;
		s = ft_split(argv[i], ' ');
		if (!s[0])
		{
			return (stop(lstbegin), ft_freedoublepointer(s), NULL);
		}
		if (!node)
		{
			if (ft_wronginput(node, s[n]) == 0)
				return (ft_freedoublepointer(s), NULL);
			node = ft_newlist(s[0]);
			node->content = 0;
			node->state = 0;
			*lstbegin = node;
			n++;
		}
		while (s[n])
		{
		//ft_printf("%s\n", s[n]);
			if (ft_wronginput(*lstbegin, s[n]) == 0)
				return (ft_freedoublepointer(s), NULL);
			ft_lstaddback(node, s[n]);
			node = node->next;
			node->content = 0;
			node->state = 0;
			n++;
		}
		if (s)
			ft_freedoublepointer(s);
		i++;
	}
	return (*lstbegin);
}

int	ft_issorted(t_lst **lst)
{
	t_lst *node;
	
	node = *lst;
	while (node->next != NULL)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	main (int argc, char **argv)
{
	t_lst *lst;

	lst = NULL;
	int	listsize;
	// ft_printf("%d\n", argc);
	if (argc < 2)
		return (0);
	// if (argc == 2 && ft_isdigit(ft_atoi((ft_split(argv[1], ' '))[0])))	//do i need it?
	// 	return (0);
	lst = ft_createlst(&lst, argv);
		//ft_printlst(lst);
	if (!lst)
		return (0);
	ft_assignpositivenumbers(&lst);
	listsize = ft_listsize(lst);
	if (ft_listsize(lst) == 1 || ft_issorted(&lst))
		return (ft_deletelst(&lst), 0);
		//ft_printf("%d\n", listsize);
	if (listsize <= 2)
		sort2(&lst);
	else if (listsize <= 3)
		sort3(&lst);
	else if (listsize <= 5)
		sort5(&lst);
	else if (listsize <= 500)
		sort500(&lst, listsize);
		//ft_printf("---------\nFINAL:\n");
	//ft_printlst(lst);
		//system("leaks push_swap");
	return (ft_deletelst(&lst), 0);
}

//Pfad: ~/Documents/coding/pushswap/push_swap