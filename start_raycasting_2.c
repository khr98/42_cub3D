/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_raycasting_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:27:52 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/21 13:32:04 by hyerkim          ###   ########.fr       */
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
			scr->img.data[y * scr->screen_width + x] = scr->buf[y][x];
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
		scr->ray.wallX = scr->player.posY + scr->ray.perpWallDist
			* scr->ray.dirY;
	else
		scr->ray.wallX = scr->player.posX + scr->ray.perpWallDist
			* scr->ray.dirX;
	scr->ray.wallX -= floor(scr->ray.wallX);
	scr->ray.texX = (int)(scr->ray.wallX * (double)TEX_WIDTH);
	if (scr->ray.side == 1 || scr->ray.side == 2)
		scr->ray.texX = TEX_WIDTH - scr->ray.texX - 1;
	scr->ray.step = 1.0 * TEX_HEIGHT / scr->ray.lineHeight;
	scr->ray.texPos = (scr->ray.drawStart - scr->screen_height
			/ 2 + scr->ray.lineHeight / 2) * scr->ray.step;
	y = scr->ray.drawStart - 1;
	while (++y < scr->ray.drawEnd)
	{
		scr->ray.texY = (int)scr->ray.texPos & (TEX_HEIGHT - 1);
		scr->ray.texPos += scr->ray.step;
		color = scr->texture[scr->ray.side][TEX_HEIGHT
			* scr->ray.texY + scr->ray.texX];
		scr->buf[y][x] = color;
	}
}

void		wall(t_screen *scr)
{
	if (scr->ray.side <= 1)
		scr->ray.perpWallDist = (scr->ray.mapX - scr->player.posX
				+ (1 - scr->ray.stepX) / 2) / scr->ray.dirX;
	else
		scr->ray.perpWallDist = (scr->ray.mapY - scr->player.posY
				+ (1 - scr->ray.stepY) / 2) / scr->ray.dirY;
	scr->ray.lineHeight = (int)(scr->screen_height / scr->ray.perpWallDist);
	scr->ray.drawStart = -scr->ray.lineHeight / 2 + scr->screen_height / 2;
	if (scr->ray.drawStart < 0)
		scr->ray.drawStart = 0;
	scr->ray.drawEnd = scr->ray.lineHeight / 2 + scr->screen_height / 2;
	if (scr->ray.drawEnd >= scr->screen_height)
		scr->ray.drawEnd = scr->screen_height - 1;
}

void		make_dda(t_screen *scr)
{
	while (scr->ray.hit == 0)
	{
		if (scr->ray.sideDistX < scr->ray.sideDistY)
		{
			scr->ray.sideDistX += scr->ray.deltaDistX;
			scr->ray.mapX += scr->ray.stepX;
			if (scr->ray.stepX == -1)
				scr->ray.side = 0;
			else
				scr->ray.side = 1;
		}
		else
		{
			scr->ray.sideDistY += scr->ray.deltaDistY;
			scr->ray.mapY += scr->ray.stepY;
			if (scr->ray.stepY == -1)
				scr->ray.side = 2;
			else
				scr->ray.side = 3;
		}
		if (scr->map[scr->ray.mapX][scr->ray.mapY] == '1')
			scr->ray.hit = 1;
	}
}

void		make_sidedist(t_screen *scr)
{
	if (scr->ray.dirX < 0)
	{
		scr->ray.stepX = -1;
		scr->ray.sideDistX = (scr->player.posX - scr->ray.mapX)
			* scr->ray.deltaDistX;
	}
	else
	{
		scr->ray.stepX = 1;
		scr->ray.sideDistX = (scr->ray.mapX + 1.0 - scr->player.posX)
			* scr->ray.deltaDistX;
	}
	if (scr->ray.dirY < 0)
	{
		scr->ray.stepY = -1;
		scr->ray.sideDistY = (scr->player.posY - scr->ray.mapY)
			* scr->ray.deltaDistY;
	}
	else
	{
		scr->ray.stepY = 1;
		scr->ray.sideDistY = (scr->ray.mapY + 1.0 - scr->player.posY)
			* scr->ray.deltaDistY;
	}
}
