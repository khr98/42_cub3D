/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:49:46 by hyerkim           #+#    #+#             */
/*   Updated: 2020/10/05 21:55:01 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t		count;
	long long	temp;

	count = 0;
	temp = (long long)n;
	if (temp < 0)
	{
		count++;
		temp *= -1;
	}
	while (temp >= 10)
	{
		count++;
		temp = temp / 10;
	}
	return (count + 1);
}

char			*ft_itoa(int n)
{
	char		*result;
	size_t		len;
	size_t		i;
	long long	temp;

	len = get_len(n);
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len] = 0;
	temp = (long long)n;
	if (temp < 0)
		temp *= (-1);
	i = 0;
	while (i < len || temp != 0)
	{
		if (n < 0)
		{
			result[0] = '-';
			i++;
		}
		result[--len] = (temp % 10) + '0';
		temp = temp / 10;
		i++;
	}
	return (result);
}
