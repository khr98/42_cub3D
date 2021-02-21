/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:27:37 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/21 13:32:27 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		make_basic(t_screen *scr, int x)
{
	scr->ray.cameraX = 2 * x / (double)scr->screen_width - 1;
	scr->ray.dirX = scr->player.dirX +
		scr->player.planeX * scr->ray.cameraX;
	scr->ray.dirY = scr->player.dirY +
		scr->player.planeY * scr->ray.cameraX;
	scr->ray.mapX = (int)scr->player.posX;
	scr->ray.mapY = (int)scr->player.posY;
	scr->ray.deltaDistX = fabs(1 / scr->ray.dirX);
	scr->ray.deltaDistY = fabs(1 / scr->ray.dirY);
	scr->ray.hit = 0;
}

void		make_floor_ceiling(t_screen *scr)
{
	int		x;
	int		y;

	y = 0;
	while (y < scr->screen_height)
	{
		x = 0;
		while (x < scr->screen_width)
		{
			if (y > scr->screen_height / 2)
				scr->buf[y][x] = scr->floor_color;
			else
				scr->buf[y][x] = scr->ceiling_color;
			x++;
		}
		y++;
	}
}

void		exec_raycasting(t_screen *scr)
{
	int		x;

	make_floor_ceiling(scr);
	x = 0;
	while (x < scr->screen_width)
	{
		make_basic(scr, x);
		make_sidedist(scr);
		make_dda(scr);
		wall(scr);
		exec_texture(scr, x);
		scr->z_buf[x] = scr->ray.perpWallDist;
		x++;
	}
}

int			main_loop(t_screen *scr)
{
	exec_raycasting(scr);
	start_sprite(scr);
	draw_line(scr);
	return (0);
}

void		start_raycasting(t_screen *scr)
{
	scr->win = mlx_new_window(scr->mlx, scr->screen_width,
			scr->screen_height, "cub3D");
	scr->img.img = mlx_new_image(scr->mlx, scr->screen_width,
			scr->screen_height);
	scr->img.data = (int *)mlx_get_data_addr(scr->img.img,
			&scr->img.bpp, &scr->img.size_l, &scr->img.endian);
	mlx_loop_hook(scr->mlx, main_loop, scr);
	mlx_hook(scr->win, X_EVENT_KEY_PRESS, 0, key_press, scr);
	mlx_hook(scr->win, X_EVENT_KEY_EXIT, 0, ft_exit, 0);
	mlx_loop(scr->mlx);
}
