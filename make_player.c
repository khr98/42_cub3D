/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:27:11 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/21 22:16:40 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		put_player(t_player *player, double radian)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = player->dirx;
	player->dirx = old_dirx * cos(radian) - player->diry * sin(radian);
	player->diry = old_dirx * sin(radian) + player->diry * cos(radian);
	old_planex = player->planex;
	player->planex = old_planex * cos(radian) - player->planey * sin(radian);
	player->planey = old_planex * sin(radian) + player->planey * cos(radian);
}

void		make_player(t_screen *scr, int i, int j, int *player_num)
{
	int	degree;

	degree = 0;
	if (check_direction(scr->map[i][j]) == 1)
	{
		scr->player.posx = 0.5f + i;
		scr->player.posy = 0.5f + j;
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
