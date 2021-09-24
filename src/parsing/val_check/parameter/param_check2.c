/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:18:07 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

void	ft_check_vir(char *str, t_all *all)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			count++;
		if (str[i] == ',' && (str[i - 1] < '0' || str[i - 1] > '9'))
			ft_error(BAD_PAR, all);
	}
	if (count != 2)
		ft_error(BAD_PAR, all);
}

static void	ft_free_str(t_all *all, char *string)
{
	free(string);
	ft_error(NEG_NUM, all);
}

void	ft_check_bad(char *str, t_all *all, char crf, char *string)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			ft_free_str(all, string);
	}
	i = -1;
	while (str[++i] && crf == 'R')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '\t')
			ft_free_str(all, string);
	}
	i = -1;
	while (str[++i] && (crf == 'F' || crf == 'C'))
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '\t'
			&& str[i] != ',')
			ft_free_str(all, string);
	}
}
