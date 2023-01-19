/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:33:52 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 14:05:29 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct s_lst
{
	int				content;
	int				value;
	struct s_lst	*next;
}				t_lst;

void	sort2(t_lst **ptr);
void	sort3(t_lst **ptr, int listsize);
void	sort5(t_lst **ptr, t_lst **ptr_b, int listsize);
void	sort500(t_lst **ptr_a, t_lst **ptr_b, int listsize, int groupsize);
int		one(t_lst *lst);
int		two(t_lst *lst);
int		three(t_lst *lst);
void	ft_printlst(t_lst *lst);
int		ft_listsize(t_lst *lst);
t_lst	*ft_newlist(char *content);
t_lst	*ft_lstaddback(t_lst *lst, char *content);
t_lst	*ft_lastlst(t_lst *lst);
t_lst	*ft_onebeforelastlst(t_lst *begin);
t_lst	*ft_smallestvalue(t_lst **lst);
t_lst	*ft_smallestnode(t_lst *node);
int		ft_addnode(t_lst **lst, t_lst *beginning, char **s, int n);
int		placeoflowestvalue(t_lst *node);
void	ft_deletelst(t_lst **lst);
void	swap(t_lst **lst);
void	sa(t_lst **lst);
void	sb(t_lst **lst);
void	rotate(t_lst **lst);
void	ra(t_lst **lst);
void	rb(t_lst **lst);
void	reverserotate(t_lst **lst);
void	rra(t_lst **lst);
void	rrb(t_lst **lst);
void	push(t_lst **containing, t_lst **recieving);
void	pa(t_lst **stack_b, t_lst **stack_a);
void	pb(t_lst **stack_a, t_lst **stack_b);
void	stop(t_lst **lst);
int		ft_samevalue(t_lst *lst, char *s);
int		ft_nonumber(char *s);
int		ft_wronginput(t_lst *lst, char *s);
t_lst	*ft_createlst(t_lst **lstbegin, char **argv, int i, int n);
int		ft_highestinupperhalf(t_lst **stack_b,
			int highestcontent, int schalter);
int		ft_findhighestval(t_lst **stack_b, t_lst **stack_a,
			int highestcontent, int *schalter);
int		ft_ishighval(t_lst *node, int highestcontent, int *schalter);

#endif