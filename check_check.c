/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:25:38 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/19 01:36:13 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		command_num(int argc, char *argv, int *save)
{
	if (argc < 2)
		print_error("need more command!");
	if (argc > 3)
		print_error("too many command!");
	if (argc == 2)
		*save = 0;
	else if (ft_strncmp(argv, "--save", ft_strlen(argv)) == 0)
		*save = 1;
	else
		print_error("command is wrong!");
}

char		*remove_space(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			line[j] = line[i];
			j++;
		}
		i++;
	}
	line[j] = '\0';
	return (line);
}

int		check_direction(int c)
{
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return (1);
	return (-1);
}

int		check_map(int c)
{
	if (check_direction(c) == 1 || c == ' ' || ('0' <= c && c <= '2')
			|| c == '\n' || c == '\0')
		return (1);
	return (-1);
}

void		is_info_invaild(t_screen *scr)
{
	if (!scr->screen_height || !scr->screen_width)
		print_error("There is no screen size");
	if (!scr->east_texture || !scr->west_texture
			|| !scr->south_texture || !scr->north_texture
			|| !scr->sprite_path)
		print_error("There is no texture");
	if (!scr->floor_color || !scr->ceiling_color)
		print_error("There is no color");
}
