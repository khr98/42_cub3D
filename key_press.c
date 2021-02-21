/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:46 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/21 22:01:03 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			key_press(int key, t_screen *scr)
{
	if (key == K_W || key == K_AR_U)
		move_u_d(key, scr);
	if (key == K_S || key == K_AR_D)
		move_u_d(key, scr);
	if (key == K_A)
		move_l_r(key, scr);
	if (key == K_D)
		move_l_r(key, scr);
	if (key == K_AR_R)
		rotate_right(scr);
	if (key == K_AR_L)
		rotate_left(scr);
	if (key == K_ESC)
		exit(0);
	return (0);
}

void		move_u_d(int key, t_screen *scr)
{
	if (key == K_W || key == K_AR_U)
	{
		if (scr->map[(int)(scr->player.posx + scr->player.dirx *
					scr->player.movespeed)][(int)(scr->player.posy)] != '1')
			scr->player.posx += scr->player.dirx * scr->player.movespeed;
		if (scr->map[(int)(scr->player.posx)][(int)(scr->player.posy +
					scr->player.diry * scr->player.movespeed)] != '1')
			scr->player.posy += scr->player.diry * scr->player.movespeed;
	}
	if (key == K_S || key == K_AR_D)
	{
		if (scr->map[(int)(scr->player.posx - scr->player.dirx *
					scr->player.movespeed)][(int)(scr->player.posy)] != '1')
			scr->player.posx -= scr->player.dirx * scr->player.movespeed;
		if (scr->map[(int)(scr->player.posx)][(int)(scr->player.posy -
					scr->player.diry * scr->player.movespeed)] != '1')
			scr->player.posy -= scr->player.diry * scr->player.movespeed;
	}
}

void		move_l_r(int key, t_screen *scr)
{
	if (key == K_A)
	{
		if (scr->map[(int)(scr->player.posx)][(int)(scr->player.posy +
					scr->player.dirx * scr->player.movespeed)] != '1')
			scr->player.posy += scr->player.dirx * scr->player.movespeed;
		if (scr->map[(int)(scr->player.posx - scr->player.diry *
					scr->player.movespeed)][(int)scr->player.posy] != '1')
			scr->player.posx -= scr->player.diry * scr->player.movespeed;
	}
	if (key == K_D)
	{
		if (scr->map[(int)(scr->player.posx)][(int)(scr->player.posy -
					scr->player.dirx * scr->player.movespeed)] != '1')
			scr->player.posy -= scr->player.dirx * scr->player.movespeed;
		if (scr->map[(int)(scr->player.posx + scr->player.diry *
					scr->player.movespeed)][(int)scr->player.posy] != '1')
			scr->player.posx += scr->player.diry * scr->player.movespeed;
	}
}

void		rotate_right(t_screen *scr)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = scr->player.dirx;
	old_plane_x = scr->player.planex;
	scr->player.dirx = scr->player.dirx * cos(-scr->player.rotspeed) -
						scr->player.diry * sin(-scr->player.rotspeed);
	scr->player.diry = old_dir_x * sin(-scr->player.rotspeed) +
						scr->player.diry * cos(-scr->player.rotspeed);
	scr->player.planex = scr->player.planex * cos(-scr->player.rotspeed) -
							scr->player.planey * sin(-scr->player.rotspeed);
	scr->player.planey = old_plane_x * sin(-scr->player.rotspeed) +
							scr->player.planey * cos(-scr->player.rotspeed);
}

void		rotate_left(t_screen *scr)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = scr->player.dirx;
	old_plane_x = scr->player.planex;
	scr->player.dirx = scr->player.dirx * cos(scr->player.rotspeed) -
						scr->player.diry * sin(scr->player.rotspeed);
	scr->player.diry = old_dir_x * sin(scr->player.rotspeed) +
						scr->player.diry * cos(scr->player.rotspeed);
	scr->player.planex = scr->player.planex * cos(scr->player.rotspeed) -
						scr->player.planey * sin(scr->player.rotspeed);
	scr->player.planey = old_plane_x * sin(scr->player.rotspeed) +
						scr->player.planey * cos(scr->player.rotspeed);
}
