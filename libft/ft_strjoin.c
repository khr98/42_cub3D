/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:52:30 by hyerkim           #+#    #+#             */
/*   Updated: 2020/10/05 21:28:35 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(arr = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	ft_memcpy(arr, s1, len1);
	ft_memcpy(arr + len1, s2, len2);
	arr[len1 + len2] = '\0';
	return (arr);
}
