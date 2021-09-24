/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:11:42 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*str == c)
			count = 0;
		str++;
	}
	return (i);
}

static int	ft_riemp(char const *s, char c, int i, char **split)
{
	char	*start;
	size_t	size;

	if (*s != c)
	{
		start = (char *)s;
		while (*s && *s != c)
			s++;
		size = s - start + 1;
		split[i] = (char *)malloc(size);
		if (!split[i])
			return (0);
		ft_strlcpy(split[i++], start, size);
	}
	else
		s++;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;

	split = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!s || !split)
		return (0);
	i = 0;
	while (*s)
		ft_riemp(s, c, i, split);
	split[i] = 0;
	return (split);
}
