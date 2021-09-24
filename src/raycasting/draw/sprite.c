/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:57:23 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	ft_control_sprite(t_all *all)
{
	t_sprite	*spr;
	t_coord		*coord;

	spr = all->spr;
	coord = all->coord;
	if (spr->draw_spr_y < 0)
		spr->draw_spr_y = 0;
	spr->end_draw_y = spr->spr_height / 2 + all->info->R[1] / 2;
	if (spr->end_draw_y >= all->info->R[1])
		spr->end_draw_y = all->info->R[1] - 1;
	spr->spr_width = abs((int)(all->info->R[1] / (spr->trans_y)));
	spr->draw_spr_x = -spr->spr_width / 2 + spr->spr_screen;
	if (spr->draw_spr_x < 0)
		spr->draw_spr_x = 0;
	spr->end_draw_x = spr->spr_width / 2 + spr->spr_screen;
	if (spr->end_draw_x >= all->info->R[0])
		spr->end_draw_x = all->info->R[0] - 1;
	spr->stripe = spr->draw_spr_x;
}

static void	ft_addr_sprite(t_all *all, int z)
{
	int			i;
	t_sprite	*spr;
	t_tex		*tex;

	spr = all->spr;
	tex = all->spr->tex;
	i = (4 * all->info->R[0] * z) + (4 * spr->stripe);
	all->mlx->addr[i] = tex->addrestex[(all->mlx->bpc * tex->texwidth
			* spr->texY) + (all->mlx->bpc * spr->texX)];
	all->mlx->addr[i + 1] = tex->addrestex[(all->mlx->bpc * tex->texwidth
			* spr->texY) + (all->mlx->bpc * spr->texX) + 1];
	all->mlx->addr[i + 2] = tex->addrestex[(all->mlx->bpc * tex->texwidth
			* spr->texY) + (all->mlx->bpc * spr->texX) + 2];
}

static void	ft_controll_addr(t_all *all, int z)
{
	int			i;
	t_sprite	*spr;
	t_tex		*tex;

	spr = all->spr;
	tex = all->spr->tex;
	i = (all->mlx->bpc * tex->texwidth
			* spr->texY) + (all->mlx->bpc * spr->texX);
	if (tex->addrestex[i] != (char)0x00
		|| tex->addrestex[i + 1] != (char)0x00
		|| tex->addrestex[i + 2] != (char)0x00)
		ft_addr_sprite(all, z);
}

static void	ft_controll_2(t_all *all, double *zbuffer)
{
	int			z;
	int			d;
	t_sprite	*spr;
	t_tex		*tex;

	spr = all->spr;
	tex = all->spr->tex;
	if (spr->trans_y > 0 && spr->stripe > 0 && spr->stripe
		< all->info->R[0] && spr->trans_y < zbuffer[spr->stripe])
	{
		z = spr->draw_spr_y;
		while (z < spr->end_draw_y)
		{
			d = (z) * 256 - all->info->R[1]
				* 128 + spr->spr_height * 128;
			spr->texY = ((d * 64) / spr->spr_height) / 256;
			ft_controll_addr(all, z);
			z++;
		}
	}
}

void	ft_draw_sprite(t_all *all, double *zbuffer)
{
	int			i;
	t_sprite	*spr;
	t_tex		*tex;

	spr = all->spr;
	ft_order_sprite(all);
	i = -1;
	tex = all->spr->tex;
	while (++i < spr->numsprite)
	{
		ft_calcolate_sprite(all, i);
		ft_control_sprite(all);
		while (spr->stripe < spr->end_draw_x)
		{
			spr->texX = (int)(256 * (spr->stripe - (-spr->spr_width / 2
							+ spr->spr_screen)) * 64 / spr->spr_width) / 256;
			ft_controll_2(all, zbuffer);
			spr->stripe++;
		}
	}
}
