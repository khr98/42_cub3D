/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:29 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/17 11:26:30 by hyerkim          ###   ########.fr       */
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
	scr->player.posX = 0;
	scr->player.posY = 0;
	scr->player.dirX = -1.0;
	scr->player.dirY = 0;
	scr->player.planeX = 0;
	scr->player.planeY = 0.66;
	scr->player.moveSpeed = 0.1;
	scr->player.rotSpeed = 0.05;
}
