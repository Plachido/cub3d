/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 10:08:19 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/29 19:20:18 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	ft_set_dir(int dirx, int diry, t_all *all)
{
	all->coord->dirx = dirx;
	all->coord->diry = diry;
}

static void	ft_set_pos(t_all *all, int set, int x, int y)
{
	if (set)
		ft_error(POS_ERR, all);
	all->info->map->start = (x * all->info->map->col) + y;
	if (all->info->map->char_map[x][y] == 'N' && ++set)
	{
		ft_set_dir(-1, 0, all);
		all->coord->planey = 0.66;
	}
	else if (all->info->map->char_map[x][y] == 'S' && ++set)
	{
		ft_set_dir(1, 0, all);
		all->coord->planey = -0.66;
	}
	else if (all->info->map->char_map[x][y] == 'E' && ++set)
	{
		ft_set_dir(0, 1, all);
		all->coord->planex = 0.66;
	}
	else if (all->info->map->char_map[x][y] == 'W' && ++set)
	{
		ft_set_dir(0, -1, all);
		all->coord->planex = -0.66;
	}
	all->info->map->char_map[x][y] = '0';
}

void	ft_start_pos(t_all *all)
{
	int		x;
	int		y;
	int		set;
	t_map	*map;

	map = all->info->map;
	x = -1;
	set = 0;
	while (map->char_map[++x])
	{
		y = -1;
		while (map->char_map[x][++y])
		{
			if (map->char_map[x][y] == 'N' || map->char_map[x][y] == 'S' ||
			map->char_map[x][y] == 'E' || map->char_map[x][y] == 'W')
				ft_set_pos(all, set, x, y);
		}
		if (x == map->rows - 1)
			break ;
	}
}
