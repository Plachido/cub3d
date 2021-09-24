/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:17:16 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	*ft_memset2(void *b, int c, size_t len)
{
	char	*str;
	size_t	cont;

	str = (char *)b;
	cont = 0;
	while (cont < len)
	{
		str[cont] = (unsigned char)c;
		cont++;
	}
	return (b);
}

void	ft_bzero2(void *s, size_t n)
{
	if (n != 0)
		ft_memset2(s, '\0', n);
}

int	write_header(int fd, t_all *all, int tmp, int file_size)
{
	char	header[54];

	ft_bzero2(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(file_size);
	header[3] = (unsigned char)(file_size >> 8);
	header[4] = (unsigned char)(file_size >> 16);
	header[5] = (unsigned char)(file_size >> 24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(tmp);
	header[19] = (unsigned char)(tmp >> 8);
	header[20] = (unsigned char)(tmp >> 16);
	header[21] = (unsigned char)(tmp >> 24);
	tmp = -all->info->R[1];
	header[22] = (unsigned char)(tmp);
	header[23] = (unsigned char)(tmp >> 8);
	header[24] = (unsigned char)(tmp >> 16);
	header[25] = (unsigned char)(tmp >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
	return (1);
}

int	write_data(int fd, t_all *all, char *img)
{
	char	*tmp;

	tmp = img;
	write(fd, tmp, (all->info->R[0] * all->info->R[1] * 4));
	return (1);
}

void	ft_screenshot(t_all *all, char *img)
{
	int	tmp;
	int	fd;
	int	file_size;

	fd = open("./screenshot.bmp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	file_size = 14 + 40 + (all->info->R[0] * all->info->R[1]) * 4 ;
	tmp = all->info->R[0];
	write_header(fd, all, tmp, file_size);
	write_data(fd, all, img);
	close(fd);
}
