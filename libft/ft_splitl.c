/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlenard <vlenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:23:19 by vlenard           #+#    #+#             */
/*   Updated: 2023/01/12 14:26:52 by vlenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_length(const char *s, size_t i, char c)
{
	size_t	count;

	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

static char	*ft_fillstr(char const *s, size_t i, char c)
{
	char	*stl;
	size_t	k;
	size_t	t;

	k = 0;
	t = ft_word_length(s, i, c);
	stl = ft_calloc(t + 1, sizeof(char));
	if (!stl)
		return (NULL);
	while (s[i] != c && s[i])
	{
		stl[k] = s[i];
		k++;
		i++;
	}
	return (stl);
}

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	if (c == 0)
		return (1);
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	if (!s)
		return (NULL);
	str = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			str[j] = ft_fillstr(s, i, c);
			if (!str[j])
				return (ft_free(str));
			i += ft_strlen(str[j]);
		}
		j++;
	}
	return (str);
}
