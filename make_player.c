/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:27:11 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/17 11:27:13 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		put_player(t_player * player, double radian)
{
	double	old_dirX;
	double	old_planeX;

	old_dirX = player->dirX;
	player->dirX = old_dirX * cos(radian) - player->dirY * sin(radian);
	player->dirY = old_dirX * sin(radian) + player->dirY * cos(radian);
	old_planeX = player->planeX;
	player->planeX = old_planeX * cos(radian) - player->planeY * sin(radian);
	player->planeY = old_planeX * sin(radian) + player->planeY * cos(radian);
}

void		make_player(t_screen * scr, int i, int j, int *player_num)
{
	int	degree;

	degree = 0;
	if (check_direction(scr->map[i][j]) == 1)
	{
		scr->player.posX = 0.5f + i;
		scr->player.posY = 0.5f + j;
		(*player_num)++;
		scr->direction = scr->map[i][j];
		if (scr->direction == 'W')
			degree = 0;
		else if (scr->direction == 'S')
			degree = 90;
		else if (scr->direction == 'E')
			degree = 180;
		else if (scr->direction == 'N')
			degree = 270;
		put_player(&scr->player, degree * (PI / 180));
	}
}
