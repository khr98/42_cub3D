/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:24:42 by hyerkim           #+#    #+#             */
/*   Updated: 2020/10/07 17:54:54 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	i = 0;
	if (dst < src)
	{
		while (i < n)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	else
		while (i < n)
		{
			dst2[n - i - 1] = src2[n - i - 1];
			i++;
		}
	return (dst);
}
