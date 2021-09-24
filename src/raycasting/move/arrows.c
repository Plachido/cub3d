/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:59:46 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/29 18:00:17 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_move_left(t_all *all)
{
	double	olddirx;
	double	oldplanex;
	t_map	*map;
	t_coord	*coord;

	map = all->info->map;
	coord = all->coord;
	olddirx = coord->dirx;
	coord->dirx = coord->dirx * cos(ROTATESPEED / 2)
		- coord->diry * sin(ROTATESPEED / 2);
	coord->diry = olddirx * sin(ROTATESPEED / 2)
		+ coord->diry * cos(ROTATESPEED / 2);
	oldplanex = coord->planex;
	coord->planex = coord->planex * cos(ROTATESPEED / 2)
		- coord->planey * sin(ROTATESPEED / 2);
	coord->planey = oldplanex * sin(ROTATESPEED / 2)
		+ coord->planey * cos(ROTATESPEED / 2);
}

void	ft_move_right(t_all *all)
{
	double	olddirx;
	double	oldplanex;
	t_map	*map;
	t_coord	*coord;

	map = all->info->map;
	coord = all->coord;
	olddirx = coord->dirx;
	coord->dirx = coord->dirx * cos(-ROTATESPEED / 2) - coord->diry
		* sin(-ROTATESPEED / 2);
	coord->diry = olddirx * sin(-ROTATESPEED / 2) + coord->diry
		* cos(-ROTATESPEED / 2);
	oldplanex = coord->planex;
	coord->planex = coord->planex * cos(-ROTATESPEED / 2) - coord->planey
		* sin(-ROTATESPEED / 2);
	coord->planey = oldplanex * sin(-ROTATESPEED / 2) + coord->planey
		* cos(-ROTATESPEED / 2);
}
