/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:07:26 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 20:19:16 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	ft_error(char *text, t_all *all)
{
	printf("%s", text);
	if (ft_strncmp(WRONG_PARAM, text, ft_strlen(text)))
		ft_free(all);
	free(all);
	exit(0);
}
