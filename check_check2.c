/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_check2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:27:10 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/20 14:55:38 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_color_factor(char **rgb)
{
	int		i;
	int		j;

	i = 0;
	while (rgb[i])
	{
		rgb[i] = remove_space(rgb[i]);
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				print_error("color factor is wrong");
			j++;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			print_error("color number is wrong");
		i++;
	}
}

int			search_file(char *line, char *xpm)
{
	int		len;
	int		xpm_len;
	char	*file;

	file = remove_space(line);
	len = (int)ft_strlen(line);
	xpm_len = (int)ft_strlen(xpm);
	if (len <= xpm_len)
		print_error("file path is wrong");
	file = line + (len - xpm_len);
	if (!ft_strncmp(file, xpm, ft_strlen(file)))
		return (1);
	return (0);
}

void		factor_is_digit(char **s)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (!ft_isdigit(s[i][j]))
				print_error("size is not digit!");
			j++;
		}
		i++;
	}
}
