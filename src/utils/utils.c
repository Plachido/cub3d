/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:34:28 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/29 17:54:45 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

/*
This file containes useful functions of various types.
*/

/*
This function joins two strings, and frees only the first one passed.
*/

char	*ft_append(char *string, char *app)
{
	char	*ret;

	ret = ft_strjoin(string, app);
	free(string);
	return (ret);
}

/* Frees the correct variables, in the eventuality a bad parameter is found.
These frees could not be included inside ft_error, since it does take only
the structure and the error message as parameters.
*/

void	ft_bad_par(char *error, char *string, char *checked, t_all *all)
{
	free(string);
	free(checked);
	checked = NULL;
	ft_error(error, all);
}

/* Removes the last elements of a t_list. */

void	ft_lstrm_last(t_list *list)
{
	int		i;
	int		j;
	t_list	*elem;

	i = 1;
	j = ft_lstsize(list);
	while (i++ < j - 1)
		list = list->next;
	elem = list->next;
	list->next = NULL;
	free(elem);
}

void	ft_char_to_int(t_all *all)
{
	t_map	*map;
	int		*int_map;
	int		i;

	map = all->info->map;
	int_map = ft_calloc(map->col * map->rows, sizeof(int));
	if (!int_map)
		ft_error(MALLOC_FAIL, all);
	i = -1;
	while (++i < map->col * map->rows)
	{
		if (map->char_map[i / map->col][i % map->col] == ' ')
			int_map[i] = -1;
		else
			int_map[i] = map->char_map[i / map->col][i % map->col] - 48;
	}
	i = -1;
	while (map->char_map[++i])
		free(map->char_map[i]);
	free(map->char_map);
	map->char_map = NULL;
	map->int_map = int_map;
}

void	ft_perp_dist(int side, t_coord *coord)
{
	if (!side)
		coord->perpwalldist = (coord->mapx - coord->posx + (1 - coord->stepx)
				/ 2) / coord->raydirx;
	else
		coord->perpwalldist = (coord->mapy - coord->posy + (1 - coord->stepy)
				/ 2) / coord->raydiry;
}
