/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:33:55 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	ft_load_tex2(t_all *all)
{
	t_tex	*tex;

	tex = all->walls->WE;
	tex->tex_ptr = mlx_xpm_file_to_image(all->mlx->mlx_ptr, all->info->WE,
			&tex->texwidth, &tex->texheight);
	tex->addrestex = mlx_get_data_addr(tex->tex_ptr, &all->mlx->bpp,
			&all->mlx->line_length, &all->mlx->endian);
	tex = all->spr->tex;
	tex->tex_ptr = mlx_xpm_file_to_image(all->mlx->mlx_ptr, all->info->S,
			&tex->texwidth, &tex->texheight);
	tex->addrestex = mlx_get_data_addr(tex->tex_ptr, &all->mlx->bpp,
			&all->mlx->line_length, &all->mlx->endian);
}
