/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:53:31 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		count;
	size_t				i;
	char				*str;

	i = 0;
	if (!s)
		return (0);
	count = ft_strlen(s);
	str = (char *)malloc((sizeof(char)) * (len + 1));
	if (!str)
		return (0);
	if (count < start)
	{
		str[0] = '\0';
		return (str);
	}
	while (i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
