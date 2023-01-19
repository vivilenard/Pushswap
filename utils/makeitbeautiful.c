/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_makeitbeautiful.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:40:00 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/19 14:13:42 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	one(t_lst *lst)
{
	return (lst->content);
}

int	two(t_lst *lst)
{
	return (lst->next->content);
}

int	three(t_lst *lst)
{
	return (lst->next->next->content);
}
