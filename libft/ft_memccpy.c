/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:10:06 by hyerkim           #+#    #+#             */
/*   Updated: 2020/10/07 17:50:55 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned char	c2;

	i = 0;
	if ((char*)dst == NULL && (unsigned char*)src == NULL)
		return (NULL);
	dst2 = (unsigned char*)dst;
	src2 = (unsigned char*)src;
	c2 = (unsigned char)c;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == c2)
			return ((char*)dst + i + 1);
		i++;
	}
	return (NULL);
}
