/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:10:26 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/21 22:33:19 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int				get_next_line_strchr(char *s, int c);
char			*buf_to_line(char **str, char **line, int fd, int read_size);
char			*make_str(char **str, char *buf, int fd);
int				check_file(int read_size, char **str, char **line, int fd);
int				get_next_line(int fd, char **line);

#endif
