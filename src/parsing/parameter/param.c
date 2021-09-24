/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:48:57 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 10:13:03 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

static void	ft_parse_crf(char *string, t_all *all, char crf)
{
	int		i;
	int		col;
	int		*arr;

	i = -1;
	col = 0;
	if (crf != 'R')
		ft_check_vir(string, all);
	ft_check_bad(string, all, crf, string);
	arr = ft_calloc(3, sizeof(int));
	if (!arr)
	{
		free(string);
		ft_error(MALLOC_FAIL, all);
	}
	while (++i < (int)ft_strlen(string))
	{
		while (string[i] >= '0' && string[i] <= '9')
			arr[col] = (arr[col] * 10) + (string[i++] - 48);
		if (arr[col] >= 0 && string[i] != ' ')
			col++;
	}
	ft_set_crf(arr, crf, all);
	free(arr);
}

static void	ft_assign_card(t_all *all, char par, char *string)
{
	char	*sub;
	char	*arg;

	sub = ft_substr(string, 3, ft_strlen(string) - 3);
	arg = ft_strtrim(sub, " \t");
	free(sub);
	if ((par == 'N') && !(all->info->NO))
		all->info->NO = arg;
	else if ((par == 'S') && !(all->info->SO))
		all->info->SO = arg;
	else if ((par == 'W') && !(all->info->WE))
		all->info->WE = arg;
	else if ((par == 'E') && !(all->info->EA))
		all->info->EA = arg;
	else
	{
		free(string);
		free(arg);
		ft_error(DOUBLE_PAR, all);
	}
	free(string);
}

static void	ft_assign_crsf(t_all *all, char par, char *string, char *checked)
{
	char	*sub;

	sub = ft_strtrim(string + 1, " \t");
	free(string);
	if ((par == 'C') && !(ft_strchr(checked, 'C')))
		ft_parse_crf(sub, all, 'C');
	else if ((par == 'R') && !(ft_strchr(checked, 'R')))
		ft_parse_crf(sub, all, 'R');
	else if ((par == 'S') && !(ft_strchr(checked, 'S')))
		all->info->S = sub;
	else if ((par == 'F') && !(ft_strchr(checked, 'F')))
		ft_parse_crf(sub, all, 'F');
	else
	{
		free(sub);
		ft_error(DOUBLE_PAR, all);
	}
	if (par != 'S')
		free(sub);
	checked[ft_strlen(checked)] = par;
}

static int	ft_get_other(char *string, char *checked, t_all *all)
{
	int		len;
	char	*trimmed;
	char	first;

	trimmed = ft_strtrim(string, " ");
	first = trimmed[0];
	free(trimmed);
	len = ft_strlen(checked);
	if (first == '1')
		return (0);
	if (string[0] == 'C' && ((string[1] == ' ') || (string[1] == '\t')))
		ft_assign_crsf(all, 'C', string, checked);
	else if (string[0] == 'R' && ((string[1] == ' ') || (string[1] == '\t')))
		ft_assign_crsf(all, 'R', string, checked);
	else if (string[0] == 'S' && ((string[1] == ' ') || (string[1] == '\t')))
		ft_assign_crsf(all, 'S', string, checked);
	else if (string[0] == 'F' && ((string[1] == ' ') || (string[1] == '\t')))
		ft_assign_crsf(all, 'F', string, checked);
	else if (ft_strlen(string))
		ft_bad_par(BAD_PAR, string, checked, all);
	else if ((len == (int)ft_strlen(checked)) && (string[0] != '\0'))
		ft_bad_par(DOUBLE_PAR, string, checked, all);
	else if (!ft_strlen(string))
		free(string);
	return (1);
}

char	*ft_get_param(int fd, t_all *all)
{
	char	*string;
	char	*checked;

	checked = ft_calloc(5, sizeof(char));
	if (!checked)
		ft_error(MALLOC_FAIL, all);
	while (ft_gnl(fd, &string, all))
	{
		if (string[0] == 'N' && string[1] == 'O' && string[2] == ' ')
			ft_assign_card(all, 'N', string);
		else if (string[0] == 'S' && string[1] == 'O' && string[2] == ' ')
			ft_assign_card(all, 'S', string);
		else if (string[0] == 'W' && string[1] == 'E' && string[2] == ' ')
			ft_assign_card(all, 'W', string);
		else if (string[0] == 'E' && string[1] == 'A' && string[2] == ' ')
			ft_assign_card(all, 'E', string);
		else if (!(ft_get_other(string, checked, all)))
			break ;
	}
	free (checked);
	return (string);
}
