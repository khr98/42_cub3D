/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:25:25 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/17 11:30:37 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		print_error(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
	exit(0);
}

int		ft_exit(int ret)
{
	exit(ret);
	return (ret);
}

void		ft_free(void *s)
{
	free(s);
	s = 0;
}

void		ft_free2(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = 0;
		i++;
	}
	free(s);
	s = 0;
}

void		all_free(t_screen *scr)
{
	if (scr->img.img)
		mlx_destroy_image(scr->mlx, scr->img.img);
	if (scr->sprite)
		ft_free(scr->sprite);
	if (scr->buf)
		ft_free2((void *)scr->buf);
	if (scr->z_buf)
		ft_free(scr->z_buf);
	if (scr->texture)
		ft_free2(scr->map);
	if (scr->mlx && scr->win)
		mlx_destroy_image(scr->mlx, scr->win);
}
