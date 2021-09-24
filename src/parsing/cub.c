/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:57:50 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	ft_check_ext(char *path, t_all *all)
{
	int	len;

	len = ft_strlen(path);
	if (len - 4 < 0)
		len = 0;
	else
		len = len - 4;
	if ((ft_strncmp(path + len, ".cub", 4)))
		ft_error(NOT_CUB, all);
}

static void	ft_freesprite(t_all *all, int j, int **sprite)
{
	int	x;

	x = -1;
	while (++x < j)
	{
		sprite[x] = ft_calloc(2, sizeof(int));
		if (!sprite[x])
		{
			j = -1;
			while (++j < x)
				free(sprite[x++]);
			free(sprite);
			ft_error(MALLOC_FAIL, all);
		}
	}
}

static void	ft_search_coord(t_all *all, int len, int **sprite)
{
	int	j;
	int	x;

	j = 0;
	x = -1;
	while (++x < len)
	{
		if (all->info->map->int_map[x] == 2)
		{
			sprite[j][0] = x / all->info->map->col;
			sprite[j++][1] = x % all->info->map->col;
		}
	}
}

static void	ft_sprite_coord(t_all *all)
{
	int	len;
	int	j;
	int	x;
	int	**sprite;

	j = 0;
	x = -1;
	len = all->info->map->col * all->info->map->rows;
	while (++x < len)
		if (all->info->map->int_map[x] == 2)
			j++;
	all->spr->numsprite = j;
	sprite = ft_calloc(j + 1, sizeof(int *));
	if (!sprite)
		ft_error(MALLOC_FAIL, all);
	ft_freesprite(all, j, sprite);
	ft_search_coord(all, len, sprite);
	all->info->map->sprite = sprite;
}

void	ft_elab_cub(char *path, t_all *all)
{
	int		fd;
	char	*param;

	ft_check_ext(path, all);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error(FILE_NOT_FOUND, all);
	param = ft_get_param(fd, all);
	ft_get_map(fd, all, param);
	all->mlx->mlx_ptr = mlx_init();
	ft_param_check(all);
	ft_map_check(all);
	ft_char_to_int(all);
	ft_sprite_coord(all);
	ft_init_walls(all);
	close(fd);
}
