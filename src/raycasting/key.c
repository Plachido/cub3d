/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:35:06 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	ft_key_hit(int keycode, t_all *all)
{
	if (keycode < 255)
		all->info->keyboard[keycode] = 1;
	return (0);
}

int	ft_key_release(int keycode, t_all *all)
{
	if (keycode < 255)
		all->info->keyboard[keycode] = 0;
	return (0);
}

void	ft_set_key(t_all *all)
{
	int	i;

	i = 0;
	while (i < 256)
		all->info->keyboard[i++] = 0;
}
