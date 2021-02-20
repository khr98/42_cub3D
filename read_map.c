/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:27:30 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/20 15:12:29 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		read_map(t_screen *scr, char *line)
{
	t_list	*lst;

	lst = ft_lstnew(ft_strdup(line));
	free(line);
	while (get_next_line(scr->fd, &line) > 0)
	{
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup(line)));
	free(line);
	close(scr->fd);
	make_map_square(scr, lst);
	fill_map(scr, lst);
	ft_lstclear(&lst, free);
	make_sprite(scr);
}

int			find_width(t_list *lst)
{
	int		result;
	int		len;

	result = 0;
	while (lst)
	{
		len = (int)ft_strlen((char *)lst->content);
		if (result < len)
			result = len;
		lst = lst->next;
	}
	return (result);
}

void		make_map_square(t_screen *scr, t_list *lst)
{
	int		i;
	int		j;

	scr->map_height = ft_lstsize(lst);
	if (!(scr->map = (char **)malloc(sizeof(char *) * (scr->map_height))))
		print_error("malloc fail");
	i = 0;
	scr->map_width = find_width(lst);
	while (lst)
	{
		if (!(scr->map[i] = (char *)malloc(sizeof(char)
						* (scr->map_width + 1))))
			print_error("malloc fail");
		j = 0;
		while (j++ < (int)ft_strlen((char *)lst->content))
			scr->map[i][j] = 0;
		while (j++ < scr->map_width)
			scr->map[i][j] = ' ';
		scr->map[i][scr->map_width] = '\0';
		i++;
		lst = lst->next;
	}
}

void		fill_map(t_screen *scr, t_list *lst)
{
	int		i;
	int		j;
	char	*line;
	int		player_num;

	i = -1;
	player_num = 0;
	while (++i < scr->map_height)
	{
		j = -1;
		line = (char *)lst->content;
		while (++j < (int)ft_strlen(line))
		{
			if (check_map(line[j]) == -1)
				print_error("map is invaild");
			scr->map[i][j] = line[j];
			if (scr->map[i][j] == '2')
				scr->sprite_num++;
			make_player(scr, i, j, &player_num);
		}
		lst = lst->next;
	}
	if (player_num == 0 || player_num > 1)
		print_error("player is invaild");
}

void		make_sprite(t_screen *scr)
{
	int		x;
	int		y;
	int		i;

	if (!(scr->sprite = (t_sprite *)malloc(sizeof(t_sprite) * scr->sprite_num)))
		print_error("sprite malloc fail");
	i = 0;
	y = 0;
	while (y < scr->map_height)
	{
		x = 0;
		while (x < scr->map_width)
		{
			if (scr->map[y][x] == '2')
			{
				scr->sprite[i].x = 0.5f + y;
				scr->sprite[i].y = 0.5f + x;
				i++;
			}
			x++;
		}
		y++;
	}
}
