/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:51:44 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_calcolate_sprite(t_all *all, int i)
{
	t_sprite	*spr;
	t_coord		*coord;

	spr = all->spr;
	coord = all->coord;
	spr->sprite_x = (all->info->map->sprite[i][0] - coord->posx) + 0.5;
	spr->sprite_y = (all->info->map->sprite[i][1] - coord->posy) + 0.5;
	spr->invdet = 1.0 / (coord->planex * coord->diry
			- coord->dirx * coord->planey);
	spr->trans_x = spr->invdet * (coord->diry * spr->sprite_x
			- coord->dirx * spr->sprite_y);
	spr->trans_y = spr->invdet * (-coord->planey * spr->sprite_x
			+ coord->planex * spr->sprite_y);
	spr->spr_screen = (int)((all->info->R[0] / 2)
			* (1 + spr->trans_x / spr->trans_y));
	spr->spr_height = abs((int)(all->info->R[1] / (spr->trans_y)));
	spr->draw_spr_y = -spr->spr_height / 2 + all->info->R[1] / 2;
}
