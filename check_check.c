/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:25:38 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/17 14:52:06 by hyerkim          ###   ########.fr       */
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

/*int		check_map2(char *line, int j)
{
	int	i;
	int	len;

	i = 0;
	len = (int)ft_strlen(line);
	if (j == 0 || j == map_height - 1)
	{
		while (line[i] == ' ')
			i++;
		while (line[i] == '1')
			i++;
		while (line[i] == ' ')
			i++;
		if (i != len)
			print_error("map is invaild");
	}
	else
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != '1')
			print_error("map is invaild");
		if (line[i - 1] != '1')
			print_error("map is invaild");
*/
