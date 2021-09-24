/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_cel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:22:37 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->mlx->addr + (y * all->mlx->line_length + x
			* (all->mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_floorcel(t_all *all, int x)
{
	int	y;

	y = 0;
	all->mlx->addr = mlx_get_data_addr(all->mlx->img_ptr, &all->mlx->bpp,
			&all->mlx->line_length, &all->mlx->endian);
	while (y < all->print->drawstart)
		ft_my_mlx_pixel_put(all, x, y++, all->mlx->cel);
	y = all->print->drawend;
	while (y < all->info->R[1])
		ft_my_mlx_pixel_put(all, x, y++, all->mlx->floor);
}
