/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:26:55 by hyerkim           #+#    #+#             */
/*   Updated: 2021/02/20 15:06:22 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				int_to_byte(unsigned char *arr, int num)
{
	arr[0] = (unsigned char)(num);
	arr[1] = (unsigned char)(num >> 8);
	arr[2] = (unsigned char)(num >> 16);
	arr[3] = (unsigned char)(num >> 24);
}

void				make_bmp_header(t_screen *scr, int fd, int bytepadding)
{
	unsigned char	bmp_header[54];
	int				size;

	size = 54 + ((scr->screen_width * 3 + bytepadding) * scr->screen_height);
	ft_memset(bmp_header, 0, 54);
	bmp_header[0] = (unsigned char)'B';
	bmp_header[1] = (unsigned char)'M';
	int_to_byte(bmp_header + 2, size);
	bmp_header[10] = (unsigned char)54;
	bmp_header[14] = (unsigned char)40;
	int_to_byte(bmp_header + 18, scr->screen_width);
	int_to_byte(bmp_header + 22, scr->screen_height);
	bmp_header[26] = (unsigned char)1;
	bmp_header[28] = (unsigned char)24;
	write(fd, bmp_header, 54);
}

void				draw_buf(t_screen *scr, int fd, int bytepadding)
{
	int				i;
	int				j;
	unsigned char	zero[3];

	i = -1;
	while (++i < 3)
		zero[i] = (unsigned char)0;
	i = scr->screen_height - 1;
	while (i >= 0)
	{
		j = -1;
		while (++j < scr->screen_width)
			write(fd, &(scr->buf[i][j]), 3);
		write(fd, zero, bytepadding);
		i--;
	}
}

void				start_bmp(t_screen *scr)
{
	int				fd;
	int				bytepadding;

	exec_raycasting(scr);
	start_sprite(scr);
	bytepadding = (4 - (scr->screen_width * 3) % 4) % 4;
	if ((fd = open("bmp_file.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0700)) < 0)
		print_error("fail to make bmp");
	make_bmp_header(scr, fd, bytepadding);
	draw_buf(scr, fd, bytepadding);
	close(fd);
	exit(0);
}

int					main(int argc, char *argv[])
{
	t_screen		scr;
	t_count			count;
	int				save;

	command_num(argc, argv[2], &save);
	scr.fd = open(argv[1], O_RDONLY);
	if (scr.fd == -1)
		print_error("failed to open file");
	map_info(&scr, &count);
	is_info_invaild(&scr);
	read_map(&scr, scr.line);
	is_map_invaild(&scr);
	make_buffer(&scr);
	make_texture(&scr);
	fill_texture(&scr);
	if (save == 1)
		start_bmp(&scr);
	else
		start_raycasting(&scr);
	all_free(&scr);
	return (0);
}
