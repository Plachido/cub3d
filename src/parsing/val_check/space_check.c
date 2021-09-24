/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:31:10 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/21 17:07:37 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_check_up(t_all *all, int x, int y)
{
	char	**map;

	map = all->info->map->char_map;
	if (map[x - 1][y] == '0')
		ft_error(BAD_MAP, all);
}

void	ft_check_down(t_all *all, int x, int y)
{
	char	**map;

	map = all->info->map->char_map;
	if (map[x + 1][y] == '0')
		ft_error(BAD_MAP, all);
}

void	ft_check_left(t_all *all, int x, int y)
{
	char	**map;

	map = all->info->map->char_map;
	if (map[x][y - 1] == '0')
		ft_error(BAD_MAP, all);
}

void	ft_check_right(t_all *all, int x, int y)
{
	char	**map;

	map = all->info->map->char_map;
	if (map[x][y + 1] == '0')
		ft_error(BAD_MAP, all);
}
