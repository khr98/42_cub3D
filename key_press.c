/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:46 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/20 15:02:31 by hyerkim          ###   ########.fr       */
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
		if (scr->map[(int)(scr->player.posX + scr->player.dirX *
					scr->player.moveSpeed)][(int)(scr->player.posY)] != '1')
			scr->player.posX += scr->player.dirX * scr->player.moveSpeed;
		if (scr->map[(int)(scr->player.posX)][(int)(scr->player.posY +
					scr->player.dirY * scr->player.moveSpeed)] != '1')
			scr->player.posY += scr->player.dirY * scr->player.moveSpeed;
	}
	if (key == K_S || key == K_AR_D)
	{
		if (scr->map[(int)(scr->player.posX - scr->player.dirX *
					scr->player.moveSpeed)][(int)(scr->player.posY)] != '1')
			scr->player.posX -= scr->player.dirX * scr->player.moveSpeed;
		if (scr->map[(int)(scr->player.posX)][(int)(scr->player.posY -
					scr->player.dirY * scr->player.moveSpeed)] != '1')
			scr->player.posY -= scr->player.dirY * scr->player.moveSpeed;
	}
}

void		move_l_r(int key, t_screen *scr)
{
	if (key == K_A)
	{
		if (scr->map[(int)(scr->player.posX)][(int)(scr->player.posY +
					scr->player.dirX * scr->player.moveSpeed)] != '1')
			scr->player.posY += scr->player.dirX * scr->player.moveSpeed;
		if (scr->map[(int)(scr->player.posX - scr->player.dirY *
					scr->player.moveSpeed)][(int)scr->player.posY] != '1')
			scr->player.posX -= scr->player.dirY * scr->player.moveSpeed;
	}
	if (key == K_D)
	{
		if (scr->map[(int)(scr->player.posX)][(int)(scr->player.posY -
					scr->player.dirX * scr->player.moveSpeed)] != '1')
			scr->player.posY -= scr->player.dirX * scr->player.moveSpeed;
		if (scr->map[(int)(scr->player.posX + scr->player.dirY *
					scr->player.moveSpeed)][(int)scr->player.posY] != '1')
			scr->player.posX += scr->player.dirY * scr->player.moveSpeed;
	}
}

void		rotate_right(t_screen *scr)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = scr->player.dirX;
	old_plane_x = scr->player.planeX;
	scr->player.dirX = scr->player.dirX * cos(-scr->player.rotSpeed) -
						scr->player.dirY * sin(-scr->player.rotSpeed);
	scr->player.dirY = old_dir_x * sin(-scr->player.rotSpeed) +
						scr->player.dirY * cos(-scr->player.rotSpeed);
	scr->player.planeX = scr->player.planeX * cos(-scr->player.rotSpeed) -
							scr->player.planeY * sin(-scr->player.rotSpeed);
	scr->player.planeY = old_plane_x * sin(-scr->player.rotSpeed) +
							scr->player.planeY * cos(-scr->player.rotSpeed);
}

void		rotate_left(t_screen *scr)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = scr->player.dirX;
	old_plane_x = scr->player.planeX;
	scr->player.dirX = scr->player.dirX * cos(scr->player.rotSpeed) -
						scr->player.dirY * sin(scr->player.rotSpeed);
	scr->player.dirY = old_dir_x * sin(scr->player.rotSpeed) +
						scr->player.dirY * cos(scr->player.rotSpeed);
	scr->player.planeX = scr->player.planeX * cos(scr->player.rotSpeed) -
						scr->player.planeY * sin(scr->player.rotSpeed);
	scr->player.planeY = old_plane_x * sin(scr->player.rotSpeed) +
						scr->player.planeY * cos(scr->player.rotSpeed);
}
