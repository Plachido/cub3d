/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:13:54 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 11:59:58 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	ft_init_walls(t_all *all)
{
	t_tex	*NO;
	t_tex	*SO;
	t_tex	*EA;
	t_tex	*WE;
	t_tex	*S;

	NO = ft_calloc(1, sizeof(t_tex));
	SO = ft_calloc(1, sizeof(t_tex));
	EA = ft_calloc(1, sizeof(t_tex));
	WE = ft_calloc(1, sizeof(t_tex));
	S = ft_calloc(1, sizeof(t_tex));
	if (!NO || !SO || !EA || !WE || !S)
		ft_error(MALLOC_FAIL, all);
	all->walls->NO = NO;
	all->walls->SO = SO;
	all->walls->EA = EA;
	all->walls->WE = WE;
	all->spr->tex = S;
	ft_load_tex(all);
}

static void	ft_init_raycasting(t_all *all)
{
	t_mlx		*mlx;
	t_walls		*walls;
	t_print		*print;
	t_coord		*coord;
	t_sprite	*spr;

	mlx = ft_calloc(1, sizeof(t_mlx));
	walls = ft_calloc(1, sizeof(t_walls));
	coord = ft_calloc(1, sizeof(t_coord));
	print = ft_calloc(1, sizeof(t_print));
	spr = ft_calloc(1, sizeof(t_sprite));
	if (!mlx || !walls || !coord || !print || !spr)
		ft_error(MALLOC_FAIL, all);
	all->mlx = mlx;
	all->walls = walls;
	all->print = print;
	all->coord = coord;
	all->spr = spr;
}

void	ft_init(t_all *all)
{
	t_info	*info;
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	info = ft_calloc(1, sizeof(t_info));
	ft_init_raycasting(all);
	if (!info || !map)
		ft_error(MALLOC_FAIL, all);
	info->map = map;
	all->info = info;
}

void	ft_init_pos(t_all *all)
{
	all->coord->posx = (int)all->info->map->start / all->info->map->col;
	all->coord->posy = (int)all->info->map->start % all->info->map->col;
}

void	ft_load_tex(t_all *all)
{
	t_tex	*tex;

	tex = all->walls->NO;
	tex->tex_ptr = mlx_xpm_file_to_image(all->mlx->mlx_ptr, all->info->NO,
			&tex->texwidth, &tex->texheight);
	tex->addrestex = mlx_get_data_addr(tex->tex_ptr, &all->mlx->bpp,
			&all->mlx->line_length, &all->mlx->endian);
	tex = all->walls->SO;
	tex->tex_ptr = mlx_xpm_file_to_image(all->mlx->mlx_ptr, all->info->SO,
			&tex->texwidth, &tex->texheight);
	tex->addrestex = mlx_get_data_addr(tex->tex_ptr, &all->mlx->bpp,
			&all->mlx->line_length, &all->mlx->endian);
	tex = all->walls->EA;
	tex->tex_ptr = mlx_xpm_file_to_image(all->mlx->mlx_ptr, all->info->EA,
			&tex->texwidth, &tex->texheight);
	tex->addrestex = mlx_get_data_addr(tex->tex_ptr, &all->mlx->bpp,
			&all->mlx->line_length, &all->mlx->endian);
	ft_load_tex2(all);
}
