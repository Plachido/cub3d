/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:45:52 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/22 16:26:17 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static void	ft_check_edges_right(t_all *all, int x, int y)
{
	char	**map;

	map = all->info->map->char_map;
	if (y < all->info->map->col && map[x][y + 1] == '\0')
		if (map[x][y] == '0')
			ft_error(BAD_MAP, all);
}

static void	ft_check_all_char(t_all *all, int x, int y)
{
	char	**map;

	map = all->info->map->char_map;
	if (map[x][y] != 'N' && map[x][y] != 'W' && map[x][y] != 'E' &&
	map[x][y] != 'S' && map[x][y] != '1' && map[x][y] != '0' &&
	map[x][y] != '2' && map[x][y] != ' ')
		ft_error(BAD_MAP, all);
}

static void	ft_check_all_map(t_all *all, int x, int y)
{
	ft_check_edges_right(all, x, y);
	ft_check_all_char(all, x, y);
}

static void	ft_check_edges(t_all *all)
{
	char	**map;
	int		i;
	int		max;

	i = -1;
	map = all->info->map->char_map;
	while (map[0][++i])
		if (map[0][i] == '0')
			ft_error(BAD_MAP, all);
	i = -1;
	while (map[++i][0] && i < all->info->map->rows)
		if (map[i][0] == '0')
			ft_error(BAD_MAP, all);
	max = i;
	i = -1;
	while (map[max][++i])
		if (map[max][i] == '0')
			ft_error(BAD_MAP, all);
}

void	ft_map_check(t_all *all)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	ft_check_edges(all);
	while (all->info->map->char_map[++x])
	{
		y = -1;
		while (y < all->info->map->col - 1 && all->info->map->char_map[x][++y])
		{
			ft_check_all_map(all, x, y);
			if (all->info->map->char_map[x][y] == ' ')
			{
				if (x > 0)
					ft_check_up(all, x, y);
				if (x < all->info->map->rows - 1)
					ft_check_down(all, x, y);
				if (y > 0)
					ft_check_left(all, x, y);
				if (y < all->info->map->col)
					ft_check_right(all, x, y);
			}
		}
	}
}
