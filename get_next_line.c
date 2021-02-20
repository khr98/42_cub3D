/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:56:01 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/20 14:58:25 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_next_line_strchr(char *s, int c)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == (char)c)
		return (i);
	return (-1);
}

char			*buf_to_line(char **str, char **line, int fd, int read_size)
{
	int			i;
	char		*temp;

	i = get_next_line_strchr(str[fd], '\n');
	if ((i < (int)ft_strlen(str[fd])) && (i != -1))
	{
		temp = str[fd];
		*line = ft_substr(str[fd], 0, i);
		str[fd] = ft_substr(str[fd], i + 1, (int)ft_strlen(str[fd]));
		free(temp);
	}
	else if (read_size == 0)
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
	}
	return (str[fd]);
}

char			*make_str(char **str, char *buf, int fd)
{
	char		*temp;

	if (str[fd])
	{
		temp = str[fd];
		str[fd] = ft_strjoin(str[fd], buf);
		free(temp);
	}
	else
		str[fd] = ft_strdup(buf);
	return (str[fd]);
}

int				check_file(int read_size, char **str, char **line, int fd)
{
	if (read_size <= 0 && str[fd] == NULL)
	{
		*line = malloc(1);
		**line = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char *str[4096];
	char		*buf;
	int			read_size;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		str[fd] = make_str(str, buf, fd);
		if (get_next_line_strchr(buf, '\n') >= 0)
			break ;
	}
	free(buf);
	if (read_size == -1)
		return (-1);
	if (check_file(read_size, str, line, fd) > 0)
		return (0);
	str[fd] = buf_to_line(str, line, fd, read_size);
	if (read_size <= 0 && str[fd] == NULL)
		return (0);
	return (1);
}
