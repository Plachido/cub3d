/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:17:41 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

t_tex	*ft_get_texture(int side, t_all *all)
{
	t_tex	*tex;

	tex = NULL;
	if (!side && all->coord->raydirx > 0)
		tex = all->walls->SO;
	else if (!side && all->coord->raydirx <= 0)
		tex = all->walls->NO;
	else if (side && all->coord->raydiry > 0)
		tex = all->walls->EA;
	else if (side && all->coord->raydiry <= 0)
		tex = all->walls->WE;
	return (tex);
}

static void	ft_shadows(int x, int y, t_tex *tex, t_all *all)
{
	t_mlx	*mlx;

	mlx = all->mlx;
	all->mlx->addr[(mlx->bpc * all->info->R[0] * y)
		+ (mlx->bpc * x)] = tex->addrestex[(mlx->bpc * tex->texwidth
			* tex->tex_y) + (mlx->bpc * tex->tex_x)] >> 1 & 8355711;
	all->mlx->addr[(mlx->bpc * all->info->R[0] * y)
		+ (mlx->bpc * x) + 1] = tex->addrestex[(mlx->bpc * tex->texwidth
			* tex->tex_y) + (mlx->bpc * tex->tex_x) + 1] >> 1 & 8355711;
	all->mlx->addr[(mlx->bpc * all->info->R[0] * y)
		+ (mlx->bpc * x) + 2] = tex->addrestex[(mlx->bpc * tex->texwidth
			* tex->tex_y) + (mlx->bpc * tex->tex_x) + 2] >> 1 & 8355711;
}

static void	ft_text_to_addr(int x, int y, t_tex *tex, t_all *all)
{
	t_mlx	*mlx;

	mlx = all->mlx;
	all->mlx->addr[(mlx->bpc * all->info->R[0] * y)
		+ (mlx->bpc * x)] = tex->addrestex[(mlx->bpc * tex->texwidth
			* tex->tex_y) + (mlx->bpc * tex->tex_x)];
	all->mlx->addr[(mlx->bpc * all->info->R[0] * y)
		+ (mlx->bpc * x) + 1] = tex->addrestex[(mlx->bpc * tex->texwidth
			* tex->tex_y) + (mlx->bpc * tex->tex_x) + 1];
	all->mlx->addr[(mlx->bpc * all->info->R[0] * y)
		+ (mlx->bpc * x) + 2] = tex->addrestex[(mlx->bpc * tex->texwidth
			* tex->tex_y) + (mlx->bpc * tex->tex_x) + 2];
}

void	ft_print_wall(t_all *all, int x, t_tex *tex, double *zbuffer)
{
	int		y;
	double	step;
	t_print	*print;
	t_coord	*coord;
	t_mlx	*mlx;

	mlx = all->mlx;
	print = all->print;
	coord = all->coord;
	y = print->drawstart;
	step = 1.0 * tex->texheight / print->lineheight;
	tex->texpos = (print->drawstart - all->info->R[1]
			/ 2 + print->lineheight / 2) * step;
	while (y < print->drawend)
	{
		tex->tex_y = (int)tex->texpos & (tex->texheight - 1);
		tex->texpos += step;
		if (!coord->side)
			ft_text_to_addr(x, y, tex, all);
		else
			ft_shadows(x, y, tex, all);
		y++;
	}
	zbuffer[x] = coord->perpwalldist;
}
