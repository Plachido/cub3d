/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:35:06 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 20:24:13 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	ft_loop(t_all *all)
{
	if (all->info->keyboard[53])
		ft_error(END, all);
	if (all->info->keyboard[123])
		ft_move_left(all);
	if (all->info->keyboard[124])
		ft_move_right(all);
	if (all->info->keyboard[13])
		ft_move_w(all);
	if (all->info->keyboard[0])
		ft_move_a(all);
	if (all->info->keyboard[1])
		ft_move_s(all);
	if (all->info->keyboard[2])
		ft_move_d(all);
	if (all->info->keyboard[13] || all->info->keyboard[0]
		|| all->info->keyboard[1] || all->info->keyboard[2]
		|| all->info->keyboard[123] || all->info->keyboard[124])
		ft_raycasting(all);
	return (0);
}

int	ft_leave(t_all *all)
{
	ft_error(END, all);
	return (0);
}

void	ft_hook(t_all *all)
{
	t_mlx	*mlx;
	t_info	*info;

	mlx = all->mlx;
	info = all->info;
	mlx->win = mlx_new_window(mlx->mlx_ptr, info->R[0], info->R[1], "cub3d");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, info->R[0], info->R[1]);
	mlx->addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
			&mlx->line_length, &mlx->endian);
	ft_set_key(all);
	ft_raycasting(all);
	if (info->save)
		ft_screenshot(all, mlx->addr);
	mlx_hook(all->mlx->win, 2, (1L << 0), ft_key_hit, all);
	mlx_hook(all->mlx->win, 3, (1L << 1), ft_key_release, all);
	mlx_hook(all->mlx->win, 17, 0, ft_leave, all);
	mlx_loop_hook(all->mlx->mlx_ptr, ft_loop, all);
	mlx_loop(all->mlx->mlx_ptr);
	return ;
}
