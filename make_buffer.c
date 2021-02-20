/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:27:03 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/20 15:07:56 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		make_buffer(t_screen *scr)
{
	int	i;
	int	j;

	if (!(scr->buf = (int **)malloc(sizeof(int *) * scr->screen_height)))
		print_error("malloc fail");
	i = -1;
	while (++i < scr->screen_height)
	{
		if (!(scr->buf[i] = (int *)malloc(sizeof(int) * scr->screen_width)))
			print_error("malloc fail");
		j = -1;
		while (++j < scr->screen_width)
			scr->buf[i][j] = 0;
	}
	if (!(scr->z_buf = (double *)malloc(sizeof(double) * scr->screen_width)))
		print_error("malloc fail");
	i = -1;
	while (++i < scr->screen_width)
		scr->z_buf[i] = 0;
}

void		make_texture(t_screen *scr)
{
	int	i;
	int	j;

	if (!(scr->texture = (int **)malloc(sizeof(int *) * 5)))
		print_error("malloc fail");
	i = -1;
	while (++i < 5)
	{
		if (!(scr->texture[i] = (int *)malloc(sizeof(int) *
						(TEX_HEIGHT * TEX_WIDTH))))
			print_error("mallc fail");
		j = -1;
		while (++j < TEX_HEIGHT * TEX_WIDTH)
			scr->texture[i][j] = 0;
	}
}
