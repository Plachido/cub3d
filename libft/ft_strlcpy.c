/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:43:49 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict d, const char *restrict s, size_t dstsize)
{
	size_t	i;
	size_t	res;

	i = 0;
	if (!d || !s)
		return (0);
	res = ft_strlen(s);
	if (dstsize > 0)
	{
		while (s[i] && i < (dstsize - 1))
		{
			d[i] = s[i];
			i++;
		}
		d[i] = 0;
	}
	return (res);
}
