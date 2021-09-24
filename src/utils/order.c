/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:13:57 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	ft_switch(double *dist, int **sprite, int j)
{
	int		*tmp;
	double	temp;

	temp = dist[j];
	dist[j] = dist[j + 1];
	dist[j + 1] = temp;
	tmp = sprite[j];
	sprite[j] = sprite[j + 1];
	sprite[j + 1] = tmp;
}

void	ft_order_sprite(t_all *all)
{
	int		i;
	int		j;
	int		**sprite;
	double	*dist;
	t_coord	*coord;

	coord = all->coord;
	if (!all->spr->dist)
		all->spr->dist = ft_calloc(all->spr->numsprite, sizeof(double));
	dist = all->spr->dist;
	i = -1;
	sprite = all->info->map->sprite;
	while (++i < all->spr->numsprite)
		dist[i] = ((coord->posx - sprite[i][0]) * (coord->posx - sprite[i][0])
				+ (coord->posy - sprite[i][1]) * (coord->posy - sprite[i][1]));
	i = -1;
	j = -1;
	while (++i < all->spr->numsprite - 1)
	{
		j = -1;
		while (++j < all->spr->numsprite - 1 - i)
			if (dist[j] < dist[j + 1])
				ft_switch(dist, sprite, j);
	}
}
