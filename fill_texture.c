/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:14 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/20 14:56:41 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		make_image(t_screen *scr, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(scr->mlx, path, &img->img_width,
			&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp,
			&img->size_l, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(scr->mlx, img->img);
}

void		fill_texture(t_screen *scr)
{
	t_img	img;

	make_image(scr, scr->texture[0], scr->east_texture, &img);
	free(scr->east_texture);
	make_image(scr, scr->texture[1], scr->west_texture, &img);
	free(scr->west_texture);
	make_image(scr, scr->texture[2], scr->south_texture, &img);
	free(scr->south_texture);
	make_image(scr, scr->texture[3], scr->north_texture, &img);
	free(scr->north_texture);
	make_image(scr, scr->texture[4], scr->sprite_path, &img);
	free(scr->sprite_path);
}
