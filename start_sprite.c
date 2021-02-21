/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:28:07 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/21 22:15:15 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_sprite_ud(t_screen *scr)
{
	scr->ray_sprite.height = abs((int)(scr->screen_height
				/ scr->ray_sprite.trans_y));
	scr->ray_sprite.drawstart_y = -scr->ray_sprite.height
		/ 2 + scr->screen_height / 2;
	if (scr->ray_sprite.drawstart_y < 0)
		scr->ray_sprite.drawstart_y = 0;
	scr->ray_sprite.drawend_y = scr->ray_sprite.height
		/ 2 + scr->screen_height / 2;
	if (scr->ray_sprite.drawend_y >= scr->screen_height)
		scr->ray_sprite.drawend_y = scr->screen_height - 1;
	scr->ray_sprite.width = abs((int)(scr->screen_height
				/ scr->ray_sprite.trans_y));
	scr->ray_sprite.drawstart_x = -scr->ray_sprite.width
		/ 2 + scr->ray_sprite.screen_x;
	if (scr->ray_sprite.drawstart_x < 0)
		scr->ray_sprite.drawstart_x = 0;
	scr->ray_sprite.drawend_x = scr->ray_sprite.width
		/ 2 + scr->ray_sprite.screen_x;
	if (scr->ray_sprite.drawend_x >= scr->screen_width)
		scr->ray_sprite.drawend_x = scr->screen_width - 1;
}

void			draw_sprite(t_screen *scr, int stripe)
{
	int			d;
	int			color;
	int			y;

	scr->ray_sprite.tex_x = (int)((256 * (stripe - (-scr->ray_sprite.width / 2
						+ scr->ray_sprite.screen_x)) * TEX_WIDTH
				/ scr->ray_sprite.width) / 256);
	if (scr->ray_sprite.trans_y > 0 && stripe > 0 && stripe < scr->screen_width
			&& scr->ray_sprite.trans_y < scr->z_buf[stripe])
	{
		y = scr->ray_sprite.drawstart_y;
		while (y < scr->ray_sprite.drawend_y)
		{
			d = y * 256 - scr->screen_height * 128
				+ scr->ray_sprite.height * 128;
			scr->ray_sprite.tex_y = ((d * TEX_HEIGHT)
					/ scr->ray_sprite.height) / 256;
			color = scr->texture[4][TEX_WIDTH * scr->ray_sprite.tex_y
				+ scr->ray_sprite.tex_x];
			if ((color & 0x00FFFFFF) != 0)
				scr->buf[y][stripe] = color;
			y++;
		}
	}
}

void			sort_sprite(t_screen *scr)
{
	int			i;
	int			j;
	t_sprite	temp;

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
}

void			sprite_location(t_screen *scr, int i)
{
		scr->ray_sprite.rdist_x = scr->sprite[i].x - scr->player.posx;
		scr->ray_sprite.rdist_y = scr->sprite[i].y - scr->player.posy;
		scr->ray_sprite.inverse = 1.0 / (scr->player.diry * scr->player.planex
				- scr->player.dirx * scr->player.planey);
		scr->ray_sprite.trans_x = scr->ray_sprite.inverse * (scr->player.diry
				* scr->ray_sprite.rdist_x - scr->player.dirx
				* scr->ray_sprite.rdist_y);
		scr->ray_sprite.trans_y = scr->ray_sprite.inverse * (-scr->player.planey
				* scr->ray_sprite.rdist_x + scr->player.planex
				* scr->ray_sprite.rdist_y);
		scr->ray_sprite.screen_x = (int)((scr->screen_width / 2)
				* (1 + scr->ray_sprite.trans_x / scr->ray_sprite.trans_y));
}

void			start_sprite(t_screen *scr)
{
	int			i;
	int			j;
	int			stripe;


	i = -1;
	while (++i < scr->sprite_num)
	{
		scr->sprite[i].distance = ((scr->player.posx - scr->sprite[i].x) *
				(scr->player.posx - scr->sprite[i].x) + (scr->player.posy
					- scr->sprite[i].y) * (scr->player.posy
						- scr->sprite[i].y));
	}
	sort_sprite(scr);
	i = -1;
	while (++i < scr->sprite_num)
	{
		sprite_location(scr, i);
		draw_sprite_ud(scr);
		stripe = scr->ray_sprite.drawstart_x;
		while (stripe < scr->ray_sprite.drawend_x)
		{
			draw_sprite(scr, stripe);
			stripe++;
		}
	}
}
