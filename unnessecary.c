		// while (node)
		// {
		//	ft_printf("%d\n", smallestnode->content);
		// 	if (node->content == 0 && node->value < smallestnode->value)
		// 		smallestnode = node;
		// 	node = node->next;
		// 	ft_printf("Smallestnode %d\n", smallestnode->value);
		// }

			while (argv[2][i])
	{
		if (argv[3][i] != '.' && ft_isdigit(argv[3][i])
			== 0 && argv[2][i] != '-')
			return (0);
			i++;
	}

	// t_lst	*ft_createlst(t_lst *lst, char **argv)
// {
// 	int		i;
// 	t_lst	*beginlst;
	
// 	//s = ft_createstring(lst, argv);
// 	lst = ft_newlist(argv[0]);
// 	i = 2;
// 	beginlst = lst;
// 	while(argv[i])
// 	{
// 		ft_lstaddback(lst, argv[i]);
// 		lst->content = 0;
// 		lst = lst->next;
// 		i++;
// 	}
// 	lst = beginlst;
// 	return (lst);
// }

		if (node_b->content == smallestcontent)
		{
			// node_b->state = 1;
			node_b = node_b->next;
			pa(stack_b, stack_a);
			ra(stack_a);
			smallestcontent++;
		}
		else
		{
			node_b = node_b->next;
			rb(stack_b);
		}
	}

		// while (movements-- >= 0)
	// {
	// 	if (movements == -1)
	// 		groupsize = ft_listsize(*stack_a) - 3;
	// 	ft_group_to_b(stack_a, stack_b, groupbeginning, groupsize);
	// 	groupbeginning += groupsize;
	// }
	movements = listsize / groupsize;  // if listsize % groupsize == 0 (no rest) -> movements -= 1;