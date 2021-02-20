/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_invaild.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:09:12 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/20 14:24:07 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_middle_in_wall(t_screen *scr, int i, int j)
{	
	if (i > 0 && i < scr->map_height - 1)
	{
		if (scr->map[i - 1][j] == ' ' || scr->map[i + 1][j] == ' ')
		{
			if (scr->map[i][j] != ' ' && scr->map[i][j] != '1')
				print_error("wrong hole is in the map");
		}
	}
	if (j > 0 && j < scr->map_width)
	{
		if (scr->map[i][j - 1] == ' ' || scr->map[i][j + 1] == ' ')
		{
			if (scr->map[i][j] != ' ' && scr->map[i][j] != '1')
				print_error("wrong hole is in the map");
		}
	}
}

int		map_middle(t_screen *scr)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < scr->map_height - 1)
	{
		j = 0;
		while (scr->map[i][j] == ' ')
			j++;
		if (scr->map[i][j] != '1')
			print_error("left wall is invaild");
		while (j < (int)ft_strlen(scr->map[i]) - 1)
		{
			map_middle_in_wall(scr, i, j);
			j++;
		}
		if (scr->map[i][j] != '1')
			print_error("right wall is invaild");
		i++;
	}
	return (i);
}

void		is_map_invaild(t_screen *scr)
{
	int	i;
	int	j;

	if (!scr->map_height || !scr->map_width)
		print_error("There is no map size");
	i = 0;
	while (i < (int)ft_strlen(scr->map[0]))
	{
		while (!(scr->map[0][i] == ' ' || scr->map[0][i] == '1'))
			print_error("map's top is invaild");
		i++;
	}
	i = map_middle(scr);
	j = 0;
	while (j < (int)ft_strlen(scr->map[i]))
	{
		if (!(scr->map[i][j] == ' ' || scr->map[i][j] == '1'))
			print_error("map's bottom is invaild");
		j++;
	}
}
