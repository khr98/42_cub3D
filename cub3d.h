/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:02 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/17 15:36:38 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx/mlx.h"
#include "get_next_line.h"
#include "libft/libft.h"
#include "key.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_release 3
# define X_EVENT_KEY_EXIT 17
# define PI 3.1415926535897
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef	struct		s_img
{
	void		*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}			t_img;

typedef	struct		s_ray
{
	double		cameraX;
	double		dirX;
	double		dirY;
	int		mapX;
	int		mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	double		wallX;
	int		texX;
	int		texY;
	double		step;
	double		texPos;
}			t_ray;

typedef	struct		s_player
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		moveSpeed;
	double		rotSpeed;
}			t_player;

typedef	struct		s_sprite
{
	double		x;
	double		y;
	double		distance;
}			t_sprite;

typedef	struct		s_ray_sprite
{
	double		rDistX;
	double		rDistY;
	double		inverse;
	double		transX;
	double		transY;
	int		screenX;
	int		height;
	int		width;
	int		drawStartX;
	int		drawStartY;
	int		drawEndX;
	int		drawEndY;
	int		texX;
	int		texY;
	int		spriteScrX;
}			t_ray_sprite;

typedef	struct		s_screen
{
	void		*mlx;
	void		*win;
	int		screen_width;
	int		screen_height;
	int		map_width;
	int		map_height;
	int		fd;
	char		**map;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*sprite_path;
	int		direction;
	int		floor_color;
	int		ceiling_color;
	int		sprite_num;
	int		**texture;
	int		**buf;
	double		*z_buf;
	char		*line;
	t_img		img;
	t_ray		ray;
	t_player	player;
	t_sprite	*sprite;
	t_ray_sprite	ray_sprite;
}			t_screen;

// end.c
void			print_error(char *str);
int			ft_exit(int ret);
void			ft_free(void *s);
void			ft_free2(char **s);
void			all_free(t_screen *scr);

// fill_texture.c
void			make_image(t_screen * scr, int *texture, char *path, t_img *img);
void			fill_texture(t_screen * scr);

// init.c
void			init_screen(t_screen *scr);

// make_buffer.c
void			make_buffer(t_screen *scr);
void			make_texture(t_screen * scr);

// make_player.c
void			put_player(t_player * player, double radian);
void			make_player(t_screen * scr, int i, int j, int *player_num);

// map_info.c
void			map_info(t_screen *scr);
int			get_info(t_screen *scr, char *line);
void			screen_size(t_screen *scr, char *line);
void			get_texture(char *line, char **s);
void			get_color(t_screen *scr, char *line, char c);

// read_map.c
void			read_map(t_screen *scr, char *line);
int			find_width(t_list *lst);
void			make_map_square(t_screen *scr, t_list *lst);
void			fill_map(t_screen *scr, t_list *lst);
void			make_sprite(t_screen * scr);

// start_raycasting_2.c
void			draw_line(t_screen *scr);
void			exec_texture(t_screen *scr, int x);
void			wall(t_screen * scr);
void			make_dda(t_screen * scr);
void			make_sideDist(t_screen * scr);

//start_raycasting.c
void			make_basic(t_screen * scr, int x);
void			make_floor_ceiling(t_screen * scr);
void			exec_raycasting(t_screen *scr);
int			main_loop(t_screen *scr);
void			start_raycasting(t_screen * scr);

// key_press.c
int			key_press(int key, t_screen *scr);
void			move_u_d(int key, t_screen * scr);
void			move_l_r(int key, t_screen *scr);
void			rotate_right(t_screen *scr);
void			rotate_left(t_screen *scr);


// start_sprite.c
void			draw_sprite_ud(t_screen *scr);
void			draw_sprite(t_screen *scr, int pattern);
void			start_sprite(t_screen *scr);

// main.c
void			int_to_byte(unsigned char * arr, int num);
void			make_bmp_header(t_screen *scr, int fd, int bytePadding);
void			draw_buf(t_screen *scr, int fd, int bytePadding);
void			start_bmp(t_screen *scr);
int			main(int argc, char *argv[]);

//check_check.c
void			command_num(int	argc, char *argv, int *save);
char			*remove_space(char *line);
int			check_direction(int c);
int			check_map(int c);

#endif
