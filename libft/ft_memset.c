/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:26:44 by hyerkim           #+#    #+#             */
/*   Updated: 2020/10/09 17:27:36 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t n)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char*)b;
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	return (b);
}
