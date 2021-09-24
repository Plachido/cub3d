/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:36:58 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/26 11:24:03 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static int	ft_conversion_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
The following function manages the storing of values
contained in the integer array created in ft_parse_crf (param.c file)
to the correct field of the 'info' variable, inside the main
t_all type variable.
*/

void	ft_set_crf(int *arr, char par, t_all *all)
{
	if (par == 'C')
	{
		ft_check_rgb(arr, all);
		all->mlx->cel = ft_conversion_rgb(0, arr[0], arr[1], arr[2]);
	}
	if (par == 'R')
	{
		all->info->R[0] = arr[0];
		all->info->R[1] = arr[1];
	}
	if (par == 'F')
	{
		ft_check_rgb(arr, all);
		all->mlx->floor = ft_conversion_rgb(0, arr[0], arr[1], arr[2]);
	}
}
