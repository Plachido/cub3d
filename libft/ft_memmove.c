/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:34:25 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*des;
	unsigned char	*res;

	i = 0;
	des = (unsigned char *)str1;
	res = (unsigned char *)str2;
	if (!des && !res)
		return (0);
	if (des > res)
		while (++i <= n)
			des[n - i] = res[n - i];
	else
	{
		while (i < n)
		{
			des[i] = res[i];
			i++;
		}
	}
	return (des);
}
