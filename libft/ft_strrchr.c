/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:31:39 by hyerkim           #+#    #+#             */
/*   Updated: 2020/10/05 16:38:23 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char *result;

	result = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			result = (char *)s;
		s++;
	}
	if (*s == (unsigned char)c)
		result = (char *)s;
	return (result);
}
