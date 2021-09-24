/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 11:29:51 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	ft_side_dist(t_coord *coord)
{
	if (coord->raydirx < 0)
	{
		coord->stepx = -1;
		coord->sidedistx = (coord->posx - coord->mapx) * coord->deltadistx;
	}
	else
	{
		coord->stepx = 1;
		coord->sidedistx = (coord->mapx + 1.0 - coord->posx)
			* coord->deltadistx;
	}
	if (coord->raydiry < 0)
	{
		coord->stepy = -1;
		coord->sidedisty = (coord->posy - coord->mapy) * coord->deltadisty;
	}
	else
	{
		coord->stepy = 1;
		coord->sidedisty = (coord->mapy + 1.0 - coord->posy)
			* coord->deltadisty;
	}
}

void	ft_calcolate_pos(t_all *all, int x)
{
	double	camera;
	t_coord	*coord;

	coord = all->coord;
	camera = 2 * x / (double)all->info->R[0] - 1;
	coord->raydirx = coord->dirx + coord->planex * camera;
	coord->raydiry = coord->diry + coord->planey * camera;
	coord->mapx = (int)coord->posx;
	coord->mapy = (int)coord->posy;
	if (!coord->raydiry)
		coord->deltadistx = 0;
	else if (!coord->raydirx)
		coord->deltadistx = 1;
	else
		coord->deltadistx = fabs(1 / coord->raydirx);
	if (!coord->raydirx)
		coord->deltadisty = 0;
	else if (!coord->raydiry)
		coord->deltadisty = 1;
	else
		coord->deltadisty = fabs(1 / coord->raydiry);
	ft_side_dist(coord);
}

int	ft_dda(t_all *all)
{
	int		side;
	t_map	*map;
	t_coord	*coord;

	coord = all->coord;
	map = all->info->map;
	while (!(map->int_map[(coord->mapx * map->col) + all->coord->mapy] == 1))
	{
		if (coord->sidedistx < coord->sidedisty)
		{
			coord->sidedistx += coord->deltadistx;
			coord->mapx += coord->stepx;
			side = 0;
		}
		else
		{
			coord->sidedisty += coord->deltadisty;
			coord->mapy += coord->stepy;
			side = 1;
		}
	}
	ft_perp_dist(side, coord);
	return (side);
}

t_tex	*ft_start_draw(t_all *all, int side)
{
	double	wallx;
	t_coord	*coord;
	t_tex	*tex;

	coord = all->coord;
	tex = NULL;
	ft_control_print(all);
	if (side == 0)
		wallx = coord->posy + coord->perpwalldist * coord->raydiry;
	else
		wallx = coord->posx + coord->perpwalldist * coord->raydirx;
	wallx -= floor(wallx);
	tex = ft_get_texture(side, all);
	tex->tex_x = (int)(wallx * (double)tex->texwidth);
	if (side == 0 && coord->raydirx > 0)
		tex->tex_x = tex->texwidth - tex->tex_x - 1;
	if (side == 1 && coord->raydiry < 0)
		tex->tex_x = tex->texwidth - tex->tex_x - 1;
	return (tex);
}

void	ft_raycasting(t_all *all)
{
	int		x;
	double	*zbuffer;

	x = -1;
	all->mlx->bpc = all->mlx->bpp / 8;
	zbuffer = ft_calloc(all->info->R[0], sizeof(double));
	if (!zbuffer)
		ft_error(MALLOC_FAIL, all);
	while (++x < all->info->R[0])
	{
		ft_calcolate_pos(all, x);
		all->coord->side = ft_dda(all);
		ft_print_wall(all, x, ft_start_draw(all, all->coord->side), zbuffer);
		ft_draw_floorcel(all, x);
	}
	ft_draw_sprite(all, zbuffer);
	mlx_put_image_to_window(all->mlx->mlx_ptr, all->mlx->win, all->mlx->img_ptr,
		0, 0);
	free(zbuffer);
}
