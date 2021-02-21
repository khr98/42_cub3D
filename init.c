/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:29 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/21 21:55:09 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_screen(t_screen *scr)
{
	scr->screen_width = 0;
	scr->screen_height = 0;
	scr->map_width = 0;
	scr->map_height = 0;
	scr->map = NULL;
	scr->north_texture = NULL;
	scr->south_texture = NULL;
	scr->west_texture = NULL;
	scr->east_texture = NULL;
	scr->sprite_path = NULL;
	scr->direction = 0;
	scr->floor_color = 0;
	scr->ceiling_color = 0;
	scr->sprite_num = 0;
	scr->buf = NULL;
	scr->texture = NULL;
	scr->player.posx = 0;
	scr->player.posy = 0;
	scr->player.dirx = -1.0;
	scr->player.diry = 0;
	scr->player.planex = 0;
	scr->player.planey = 0.66;
	scr->player.movespeed = 0.1;
	scr->player.rotspeed = 0.05;
}

void	init_count(t_count *count)
{
	count->size = 0;
	count->east = 0;
	count->west = 0;
	count->south = 0;
	count->north = 0;
	count->s = 0;
	count->f = 0;
	count->c = 0;
}
