/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:07:16 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:56:29 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	main(int argc, char **argv)
{
	t_all	*all;
	int		l;
	int		len;

	all = ft_calloc(1, sizeof(t_all));
	if (!all)
	{
		printf(MALLOC_FAIL);
		return (0);
	}
	if (argc >= 2)
	{
		ft_init(all);
		ft_elab_cub(argv[1], all);
		if (argv[2])
		{
			l = ft_strlen(argv[2]);
			len = ft_strlen("--save");
		}
		if (argv[2] && l == len && ft_strncmp(argv[2], "--save", l) == 0)
			all->info->save = 1;
		ft_init_pos(all);
		ft_hook(all);
	}
	ft_error(WRONG_PARAM, all);
}
