/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:55:46 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!d && !s)
		return (0);
	while (i < n)
	{
		((unsigned char *)d)[i] = ((unsigned char *)s)[i];
		if ((unsigned char)c == ((unsigned char *)s)[i])
			return (d + i + 1);
		i++;
	}
	return (0);
}
