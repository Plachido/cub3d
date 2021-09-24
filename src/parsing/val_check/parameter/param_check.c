/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:45:48 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 12:01:57 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static void	ft_check_path(t_all *all)
{
	int	fd[5];
	int	i;

	i = 0;
	fd[0] = open(all->info->NO, O_RDONLY);
	fd[1] = open(all->info->SO, O_RDONLY);
	fd[2] = open(all->info->EA, O_RDONLY);
	fd[3] = open(all->info->WE, O_RDONLY);
	fd[4] = open(all->info->S, O_RDONLY);
	while (i < 5)
		if (fd[i++] < 0)
			ft_error(WRONG_PATH, all);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	close(fd[4]);
}

void	ft_check_rgb(int *arr, t_all *all)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!(arr[i] >= 0 && arr[i] <= 255))
			ft_error(BAD_RGB, all);
		i++;
	}
}

static void	ft_check_resolution(t_all *all)
{
	int	x;
	int	y;

	if (!all->info->R[0] || !all->info->R[1])
		ft_error(BAD_PAR, all);
	mlx_get_screen_size(all->mlx->mlx_ptr, &x, &y);
	if ((all->info->R[0] > x) || (all->info->R[1] > y))
	{
		if (all->info->R[0] > x)
			all->info->R[0] = x;
		if (all->info->R[1] > y)
			all->info->R[1] = y;
		printf("GIVEN RESOLUTION IS TOO BIG - SETTING TO MAX\n");
	}
}

void	ft_param_check(t_all *all)
{
	ft_check_path(all);
	ft_check_resolution(all);
	ft_map_check(all);
}
