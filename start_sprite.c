/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:28:07 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/17 11:34:42 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_sprite_ud(t_screen *scr)
{
	scr->ray_sprite.height = abs((int)(scr->screen_height / scr->ray_sprite.transY));
	scr->ray_sprite.drawStartY = -scr->ray_sprite.height / 2 + scr->screen_height / 2;
	if (scr->ray_sprite.drawStartY < 0)
		scr->ray_sprite.drawStartY = 0;
	scr->ray_sprite.drawEndY = scr->ray_sprite.height / 2 + scr->screen_height / 2;
	if (scr->ray_sprite.drawEndY >= scr->screen_height)
		scr->ray_sprite.drawEndY = scr->screen_height - 1;
	scr->ray_sprite.width = abs((int)(scr->screen_height / scr->ray_sprite.transY));
	scr->ray_sprite.drawStartX = -scr->ray_sprite.width / 2 + scr->ray_sprite.screenX;
	if (scr->ray_sprite.drawStartX < 0)
		scr->ray_sprite.drawStartX = 0;
	scr->ray_sprite.drawEndX = scr->ray_sprite.width / 2 + scr->ray_sprite.screenX;
	if (scr->ray_sprite.drawEndX >= scr->screen_width)
		scr->ray_sprite.drawEndX = scr->screen_width - 1;
}

void			draw_sprite(t_screen *scr, int stripe)
{
	int		draw;
	int		color;
	int		y;

	scr->ray_sprite.texX = (int)((256 * (stripe - (-scr->ray_sprite.width / 2 + scr->ray_sprite.screenX)) * TEX_WIDTH / scr->ray_sprite.width) / 256);
	if (scr->ray_sprite.transY > 0 && stripe > 0 && stripe < scr->screen_width && scr->ray_sprite.transY < scr->z_buf[stripe])
	{
		y = scr->ray_sprite.drawStartY;
		while (y < scr->ray_sprite.drawEndY)
		{
			draw = y * 256 - scr->screen_height * 128 + scr->ray_sprite.height * 128;
			scr->ray_sprite.texY = ((draw * TEX_HEIGHT) / scr->ray_sprite.height) / 256;
			color = scr->texture[4][TEX_WIDTH * scr->ray_sprite.texY + scr->ray_sprite.texX];
			if ((color & 0x00FFFFFF) != 0)
				scr->buf[y][stripe] = color;
			y++;
		}
	}
}

void			start_sprite(t_screen *scr)
{
	int		i;
	int		j;
	int		stripe;
	t_sprite	temp;

	i = -1;
	while (++i < scr->sprite_num)
	{
		scr->sprite[i].distance = ((scr->player.posX - scr->sprite[i].x) * (scr->player.posX - scr->sprite[i].x) + (scr->player.posY - scr->sprite[i].y) * (scr->player.posY - scr->sprite[i].y));
	}
	i = -1;
	while (++i < scr->sprite_num - 1)
	{
		j = -1;
		while (++j < scr->sprite_num - 1 - i)
		{
			if (scr->sprite[j].distance < scr->sprite[j + 1].distance)
			{
				temp = scr->sprite[j];
				scr->sprite[j] = scr->sprite[j + 1];
				scr->sprite[j + 1] = temp;
			}
		}
	}
	i = -1;
	while (++i < scr->sprite_num)
	{
		scr->ray_sprite.rDistX = scr->sprite[i].x - scr->player.posX;
		scr->ray_sprite.rDistY = scr->sprite[i].y - scr->player.posY;
		scr->ray_sprite.inverse = 1.0 / (scr->player.dirY * scr->player.planeX - scr->player.dirX * scr->player.planeY);
		scr->ray_sprite.transX = scr->ray_sprite.inverse * (scr->player.dirY * scr->ray_sprite.rDistX - scr->player.dirX * scr->ray_sprite.rDistY);
		scr->ray_sprite.transY = scr->ray_sprite.inverse * (-scr->player.planeY * scr->ray_sprite.rDistX + scr->player.planeX * scr->ray_sprite.rDistY);
		scr->ray_sprite.screenX = (int)((scr->screen_width / 2) * (1 + scr->ray_sprite.transX / scr->ray_sprite.transY));
		draw_sprite_ud(scr);
		stripe = scr->ray_sprite.drawStartX;
		while (stripe < scr->ray_sprite.drawEndX)
		{
			draw_sprite(scr, stripe);
			stripe++;
		}
	}
}
