/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_raycasting_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:27:52 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/25 13:16:15 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_line(t_screen *scr)
{
	int		x;
	int		y;

	y = 0;
	while (y < scr->screen_height)
	{
		x = 0;
		while (x < scr->screen_width)
		{
			scr->img.data[y * scr->img.size_l / scr->img.bpp * 8 + x] = scr->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(scr->mlx, scr->win, scr->img.img, 0, 0);
}

void		exec_texture(t_screen *scr, int x)
{
	int		y;
	int		color;

	if (scr->ray.side <= 1)
		scr->ray.wall_x = scr->player.posy + scr->ray.perpwall_dist
			* scr->ray.dir_y;
	else
		scr->ray.wall_x = scr->player.posx + scr->ray.perpwall_dist
			* scr->ray.dir_x;
	scr->ray.wall_x -= floor(scr->ray.wall_x);
	scr->ray.tex_x = (int)(scr->ray.wall_x * (double)TEX_WIDTH);
	if (scr->ray.side == 1 || scr->ray.side == 2)
		scr->ray.tex_x = TEX_WIDTH - scr->ray.tex_x - 1;
	scr->ray.step = 1.0 * TEX_HEIGHT / scr->ray.line_height;
	scr->ray.tex_pos = (scr->ray.drawstart - scr->screen_height
			/ 2 + scr->ray.line_height / 2) * scr->ray.step;
	y = scr->ray.drawstart - 1;
	while (++y < scr->ray.drawend)
	{
		scr->ray.tex_y = (int)scr->ray.tex_pos & (TEX_HEIGHT - 1);
		scr->ray.tex_pos += scr->ray.step;
		color = scr->texture[scr->ray.side][TEX_HEIGHT
			* scr->ray.tex_y + scr->ray.tex_x];
		scr->buf[y][x] = color;
	}
}

void		wall(t_screen *scr)
{
	if (scr->ray.side <= 1)
		scr->ray.perpwall_dist = (scr->ray.map_x - scr->player.posx
				+ (1 - scr->ray.stepx) / 2) / scr->ray.dir_x;
	else
		scr->ray.perpwall_dist = (scr->ray.map_y - scr->player.posy
				+ (1 - scr->ray.stepy) / 2) / scr->ray.dir_y;
	scr->ray.line_height = (int)(scr->screen_height / scr->ray.perpwall_dist);
	scr->ray.drawstart = -scr->ray.line_height / 2 + scr->screen_height / 2;
	if (scr->ray.drawstart < 0)
		scr->ray.drawstart = 0;
	scr->ray.drawend = scr->ray.line_height / 2 + scr->screen_height / 2;
	if (scr->ray.drawend >= scr->screen_height)
		scr->ray.drawend = scr->screen_height - 1;
}

void		make_dda(t_screen *scr)
{
	while (scr->ray.hit == 0)
	{
		if (scr->ray.side_distx < scr->ray.side_disty)
		{
			scr->ray.side_distx += scr->ray.delta_distx;
			scr->ray.map_x += scr->ray.stepx;
			if (scr->ray.stepx == -1)
				scr->ray.side = 0;
			else
				scr->ray.side = 1;
		}
		else
		{
			scr->ray.side_disty += scr->ray.delta_disty;
			scr->ray.map_y += scr->ray.stepy;
			if (scr->ray.stepy == -1)
				scr->ray.side = 2;
			else
				scr->ray.side = 3;
		}
		if (scr->map[scr->ray.map_x][scr->ray.map_y] == '1')
			scr->ray.hit = 1;
	}
}

void		make_sidedist(t_screen *scr)
{
	if (scr->ray.dir_x < 0)
	{
		scr->ray.stepx = -1;
		scr->ray.side_distx = (scr->player.posx - scr->ray.map_x)
			* scr->ray.delta_distx;
	}
	else
	{
		scr->ray.stepx = 1;
		scr->ray.side_distx = (scr->ray.map_x + 1.0 - scr->player.posx)
			* scr->ray.delta_distx;
	}
	if (scr->ray.dir_y < 0)
	{
		scr->ray.stepy = -1;
		scr->ray.side_disty = (scr->player.posy - scr->ray.map_y)
			* scr->ray.delta_disty;
	}
	else
	{
		scr->ray.stepy = 1;
		scr->ray.side_disty = (scr->ray.map_y + 1.0 - scr->player.posy)
			* scr->ray.delta_disty;
	}
}
