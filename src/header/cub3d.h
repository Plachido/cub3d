/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plpelleg <plpelleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:08:06 by plpelleg          #+#    #+#             */
/*   Updated: 2021/06/08 19:25:24 by plpelleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "minilibx_mms_20200219/mlx.h"
# include "error.h"

# define SPEEDMOVE 0.2
# define ROTATESPEED 0.1

typedef struct s_tex
{
	void		*tex_ptr;
	int			texwidth;
	int			texheight;
	char		*addrestex;
	int			tex_x;
	int			tex_y;
	double		texpos;
}				t_tex;

typedef struct s_print
{
	int			lineheight;
	int			drawstart;
	int			drawend;
}				t_print;

typedef struct s_coord
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			side;
	int			mapy;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	double		sidedistx;
	double		sidedisty;
	double		perpwalldist;
}				t_coord;

typedef struct s_map
{
	char		**char_map;
	int			*int_map;
	int			rows;
	int			col;
	double		start;
	int			**sprite;
}				t_map;

typedef struct s_info
{
	int			R[2];
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*S;
	int			keyboard[256];
	int			save;
	t_map		*map;
}				t_info;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*img_ptr;
	void		*win;
	char		*addr;
	int			endian;
	int			bpp;
	int			bpc;
	int			line_length;
	int			cel;
	int			floor;
}				t_mlx;

typedef struct s_walls
{
	t_tex		*NO;
	t_tex		*SO;
	t_tex		*EA;
	t_tex		*WE;
}				t_walls;

typedef struct s_sprite
{
	int		spr_screen;
	int		spr_height;
	int		spr_width;
	int		draw_spr_x;
	int		end_draw_x;
	int		draw_spr_y;
	int		end_draw_y;
	int		stripe;
	int		numsprite;
	int		texX;
	int		texY;
	t_tex	*tex;
	double	*dist;
	double	sprite_x;
	double	sprite_y;
	double	invdet;
	double	trans_x;
	double	trans_y;
}				t_sprite;

typedef struct s_all
{
	t_mlx		*mlx;
	t_info		*info;
	t_coord		*coord;
	t_print		*print;
	t_walls		*walls;
	t_sprite	*spr;
}				t_all;

int				ft_gnl(int fd, char **line, t_all *all);
void			ft_elab_cub(char *path, t_all *all);
char			*ft_get_param(int fd, t_all *all);
void			ft_set_crf(int RGB[3], char par, t_all *all);
void			ft_error(char *text, t_all *all);
void			ft_free(t_all *all);
void			ft_ultimate_controll(t_all *all);
char			*ft_append(char *string, char *app);
void			ft_lstrm_last(t_list *list);
void			ft_perp_dist(int side, t_coord *coord);
void			ft_char_to_int(t_all *all);
void			ft_bad_par(char *error, char *string, char *checked,
					t_all *all);
void			ft_print_all(t_all *all);
void			ft_init(t_all *all);
void			ft_init_pos(t_all *all);
void			ft_load_tex(t_all *all);
void			ft_get_map(int fd, t_all *all, char *first);
void			ft_start_pos(t_all *all);
void			ft_map_check(t_all *all);
void			ft_check_up(t_all *all, int x, int y);
void			ft_check_down(t_all *all, int x, int y);
void			ft_check_left(t_all *all, int x, int y);
void			ft_check_right(t_all *all, int x, int y);
void			ft_param_check(t_all *all);
void			ft_check_rgb(int *arrgb, t_all *all);
void			ft_check_bad(char *str, t_all *all, char crf, char *string);
void			ft_check_vir(char *str, t_all *all);
void			ft_hook(t_all *all);
int				ft_key_hit(int keycode, t_all *all);
int				ft_key_release(int keycode, t_all *all);
void			ft_set_key(t_all *all);
void			ft_move_w(t_all *all);
void			ft_move_a(t_all *all);
void			ft_move_s(t_all *all);
void			ft_move_d(t_all *all);
void			ft_move_left(t_all *all);
void			ft_move_right(t_all *all);
void			ft_raycasting(t_all *all);
void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
void			ft_draw_floorcel(t_all *all, int x);
void			ft_load_tex(t_all *all);
void			ft_print_wall(t_all *all, int x, t_tex *tex, double *zbuffer);
t_tex			*ft_get_texture(int side, t_all *all);
void			ft_order_sprite(t_all *all);
void			ft_draw_sprite(t_all *all, double *zbuffer);
void			ft_screenshot(t_all *all, char *img);
void			ft_init_walls(t_all *all);
void			ft_control_print(t_all *all);
void			ft_load_tex2(t_all *all);
void			ft_calcolate_sprite(t_all *all, int i);

#endif
