/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:24:16 by plpelleg          #+#    #+#             */
/*   Updated: 2021/04/29 17:53:39 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

/*
Map parsing happens in this file.
*/

static int	ft_get_col(t_list *map_lines, int list_len)
{
	int	max;
	int	line_len;

	max = 0;
	while (list_len-- > 0)
	{
		line_len = ft_strlen(map_lines->content);
		if (line_len > max)
			max = line_len;
		map_lines = map_lines->next;
	}
	return (max);
}

static void	ft_map_padding(t_list **map_lines, t_all *all)
{
	int		len;
	int		list_len;
	char	*new_string;
	t_list	*elem;

	elem = *map_lines;
	list_len = ft_lstsize(elem);
	all->info->map->rows = list_len - 1;
	all->info->map->col = ft_get_col(elem, list_len);
	while (--list_len)
	{
		elem = elem->next;
		len = ft_strlen(elem->content);
		new_string = ft_calloc(all->info->map->col + 1, sizeof(char));
		if (!new_string)
		{
			ft_lstclear(map_lines, free);
			ft_error(MALLOC_FAIL, all);
		}
		ft_memcpy(new_string, elem->content, len);
		while (all->info->map->col - len++)
			new_string[len] = ' ';
		free(elem->content);
		elem->content = new_string;
	}
}

/*
This function populates a list with the rows of the .cub file indicating
the map. Technically, each row becomes the 'content' element of the t_list
object. When the end of line is read, the last row gets too but would be
excluded from the loop: this is why at the end, the same code written inside
the loop is repeated once.
*/

static void	ft_map_list(int fd, char *first, t_list **map_lines, t_all *all)
{
	char	*line;
	t_list	*elem;

	*map_lines = ft_lstnew(first);
	if (!map_lines)
		ft_error(MALLOC_FAIL, all);
	while (ft_gnl(fd, &line, all) && ft_strlen(line))
	{
		elem = ft_lstnew(line);
		if (!elem)
		{
			ft_lstclear(map_lines, free);
			ft_error(MALLOC_FAIL, all);
		}
		ft_lstadd_back(map_lines, elem);
	}
	elem = ft_lstnew(line);
	if (!elem)
	{
		ft_lstclear(map_lines, free);
		ft_error(MALLOC_FAIL, all);
	}
	ft_lstadd_back(map_lines, elem);
	ft_map_padding(map_lines, all);
}

/*
This is the main map parsing function. Here a list is created, in order to know
what size the matrix containing the map should be. After having populated that
list with the use of ft_map_list, all parsed strings containing the map are put
inside the matrix. The list is freed at the end of the function.
*/

void	ft_get_map(int fd, t_all *all, char *first)
{
	t_list	*map_lines;
	int		i;

	if (!ft_strlen(first))
	{
		free(first);
		ft_error(BAD_MAP, all);
	}
	ft_map_list(fd, first, &map_lines, all);
	i = ft_lstsize(map_lines);
	if (i == 1)
		ft_error(BAD_PAR, all);
	all->info->map->char_map = ft_calloc(i + 1, sizeof(char *));
	if (!all->info->map)
	{
		free(map_lines);
		ft_error(MALLOC_FAIL, all);
	}
	while (i-- > 0)
	{
		all->info->map->char_map[i] = (char *)ft_lstlast(map_lines)->content;
		ft_lstrm_last(map_lines);
	}
	free(map_lines);
	ft_start_pos(all);
}
