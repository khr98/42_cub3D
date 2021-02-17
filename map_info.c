/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:27:21 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/17 11:27:22 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_info(t_screen *scr)
{
	char	*line;
	int	result;

	init_screen(scr);
	scr->mlx = mlx_init();
	while (get_next_line(scr->fd, &line) > 0)
	{
		if ((result = get_info(scr, line)) == 0)
			free(line);
		else if (result == -1)
			break ;
	}
	scr->line = line;
}

int		get_info(t_screen *scr, char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		screen_size(scr, line + 2);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		get_texture(line + 3, &scr->north_texture);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		get_texture(line + 3, &scr->south_texture);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		get_texture(line + 3, &scr->west_texture);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		get_texture(line + 3, &scr->east_texture);
	else if (ft_strncmp(line, "S ", 2) == 0)
		get_texture(line + 2, &scr->sprite_path);
	else if (ft_strncmp(line, "F ", 2) == 0)
		get_color(scr, line + 2, 'F');
	else if (ft_strncmp(line, "C ", 2) == 0)
		get_color(scr, line + 2, 'C');
	else if (line[0] == '\0')
		return (0);
	else
		return (-1);
	return (0);
}


void		screen_size(t_screen *scr, char *line)
{
	char	**result;

	result = ft_split(line, ' ');
	scr->screen_width = ft_atoi(result[0]);
	scr->screen_height = ft_atoi(result[1]);
	ft_free2(result);
	if (scr->screen_width > 1920)
		scr->screen_width = 1920;
	if (scr->screen_height > 1080)
		scr->screen_height = 1080;
	if (!scr->screen_width || !scr->screen_height)
		print_error("size is invaild!");
}

void		get_texture(char *line, char **s)
{
	int	fd;

	line = remove_space(line);
	if ((fd = open(line, O_RDONLY)) == -1)
		print_error("texture path is invaild");
	close(fd);
	*s = ft_strdup(line);
}

void		get_color(t_screen *scr, char *line, char c)
{
	char	**rgb;
	int	color;

	rgb = ft_split(line, ',');
	color = ((ft_atoi(rgb[0]) * 256 * 256) + (ft_atoi(rgb[1]) * 256) + ft_atoi(rgb[2]));
	ft_free2(rgb);
	if (c == 'F')
		scr->floor_color = color;
	else if (c == 'C')
		scr->ceiling_color = color;
}
