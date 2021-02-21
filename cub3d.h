/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:02 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/21 22:32:05 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "get_next_line.h"
# include "libft/libft.h"
# include "key.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define PI 3.1415926535897
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct		s_count
{
	int				size;
	int				east;
	int				west;
	int				south;
	int				north;
	int				s;
	int				f;
	int				c;
}					t_count;

typedef	struct		s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;

typedef	struct		s_ray
{
	double			camera_x;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			side_distx;
	double			side_disty;
	double			delta_distx;
	double			delta_disty;
	double			perpwall_dist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				line_height;
	int				drawstart;
	int				drawend;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
}					t_ray;

typedef	struct		s_player
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			movespeed;
	double			rotspeed;
}					t_player;

typedef	struct		s_sprite
{
	double			x;
	double			y;
	double			distance;
}					t_sprite;

typedef	struct		s_ray_sprite
{
	double			rdist_x;
	double			rdist_y;
	double			inverse;
	double			trans_x;
	double			trans_y;
	int				screen_x;
	int				height;
	int				width;
	int				drawstart_x;
	int				drawstart_y;
	int				drawend_x;
	int				drawend_y;
	int				tex_x;
	int				tex_y;
	int				sprite_screen_x;
}					t_ray_sprite;

typedef	struct		s_screen
{
	void			*mlx;
	void			*win;
	int				screen_width;
	int				screen_height;
	int				map_width;
	int				map_height;
	int				fd;
	char			**map;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			*sprite_path;
	int				direction;
	int				floor_color;
	int				ceiling_color;
	int				sprite_num;
	int				**texture;
	int				**buf;
	double			*z_buf;
	char			*line;
	t_img			img;
	t_ray			ray;
	t_player		player;
	t_sprite		*sprite;
	t_ray_sprite	ray_sprite;
}					t_screen;

void				print_error(char *str);
int					ft_exit(int ret);
void				ft_free(void *s);
void				ft_free2(char **s);
void				all_free(t_screen *scr);

void				make_image(t_screen *scr, int *texture, char *path,
		t_img *img);
void				fill_texture(t_screen *scr);

void				init_screen(t_screen *scr);
void				init_count(t_count *count);

void				make_buffer(t_screen *scr);
void				make_texture(t_screen *scr);

void				put_player(t_player *player, double radian);
void				make_player(t_screen *scr, int i, int j, int *player_num);

void				map_info(t_screen *scr, t_count *count);
int					get_info(t_screen *scr, char *line, t_count *count);
void				screen_size(t_screen *scr, char *line, int count);
void				get_texture(char *line, char **s, int count);
void				get_color(t_screen *scr, char *line, char c, int count);

void				read_map(t_screen *scr, char *line);
int					find_width(t_list *lst);
void				make_map_square(t_screen *scr, t_list *lst);
void				fill_map(t_screen *scr, t_list *lst);
void				make_sprite(t_screen *scr);

void				draw_line(t_screen *scr);
void				exec_texture(t_screen *scr, int x);
void				wall(t_screen *scr);
void				make_dda(t_screen *scr);
void				make_sidedist(t_screen *scr);

void				make_basic(t_screen *scr, int x);
void				make_floor_ceiling(t_screen *scr);
void				exec_raycasting(t_screen *scr);
int					main_loop(t_screen *scr);
void				start_raycasting(t_screen *scr);

int					key_press(int key, t_screen *scr);
void				move_u_d(int key, t_screen *scr);
void				move_l_r(int key, t_screen *scr);
void				rotate_right(t_screen *scr);
void				rotate_left(t_screen *scr);

void				draw_sprite_ud(t_screen *scr);
void				draw_sprite(t_screen *scr, int pattern);
void				start_sprite(t_screen *scr);

void				int_to_byte(unsigned char *arr, int num);
void				make_bmp_header(t_screen *scr, int fd, int bytepadding);
void				draw_buf(t_screen *scr, int fd, int bytepadding);
void				start_bmp(t_screen *scr);
int					main(int argc, char *argv[]);

void				command_num(int	argc, char *argv, int *save);
char				*remove_space(char *line);
int					check_direction(int c);
int					check_map(int c);
void				is_info_invaild(t_screen *scr);

void				is_map_invaild(t_screen *scr);

void				check_color_factor(char **rgb);
int					search_file(char *line, char *xpm);
void				factor_is_digit(char **s);

#endif
