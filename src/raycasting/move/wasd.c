/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:35:06 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_move_w(t_all *all)
{
	t_map	*map;
	t_coord	*coord;

	map = all->info->map;
	coord = all->coord;
	if (!map->int_map[(map->col * (int)(coord->posx + coord->dirx))
		+ (int)(coord->posy + coord->diry)])
	{
		coord->posx += coord->dirx * SPEEDMOVE;
		coord->posy += coord->diry * SPEEDMOVE;
	}
}

void	ft_move_a(t_all *all)
{
	t_map	*map;
	t_coord	*coord;

	map = all->info->map;
	coord = all->coord;
	if (!map->int_map[(map->col * (int)(coord->posx - coord->diry))
		+ (int)(coord->posy + coord->dirx)])
	{	
		coord->posx -= coord->diry * SPEEDMOVE;
		coord->posy += coord->dirx * SPEEDMOVE;
	}
}

void	ft_move_s(t_all *all)
{
	t_map	*map;
	t_coord	*coord;

	map = all->info->map;
	coord = all->coord;
	if (!map->int_map[(map->col * (int)(coord->posx - coord->dirx))
		+ (int)(coord->posy - coord->diry)])
	{
		coord->posx -= coord->dirx * SPEEDMOVE;
		coord->posy -= coord->diry * SPEEDMOVE;
	}
}

void	ft_move_d(t_all *all)
{
	t_map	*map;
	t_coord	*coord;

	map = all->info->map;
	coord = all->coord;
	if (!map->int_map[(map->col * (int)(coord->posx + coord->diry))
		+ (int)(coord->posy - coord->dirx)])
	{
		coord->posx += coord->diry * SPEEDMOVE;
		coord->posy -= coord->dirx * SPEEDMOVE;
	}
}
