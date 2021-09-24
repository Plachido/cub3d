/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 18:15:08 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	ft_control_print(t_all *all)
{
	all->print->lineheight = (int)(all->info->R[1] / all->coord->perpwalldist);
	all->print->drawstart = -all->print->lineheight / 2 + all->info->R[1] / 2;
	if (all->print->drawstart > all->info->R[1])
		all->print->drawstart = all->info->R[1];
	if (all->print->drawstart < 0)
		all->print->drawstart = 0;
	all->print->drawend = all->print->lineheight / 2 + all->info->R[1] / 2;
	if (all->print->drawend >= all->info->R[1])
		all->print->drawend = all->info->R[1] - 1;
	if (all->print->drawend <= 0)
		all->print->drawend = 0;
}
