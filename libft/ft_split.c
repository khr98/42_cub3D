/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:18:59 by hyerkim           #+#    #+#             */
/*   Updated: 2020/10/07 19:40:48 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void		put_word(char **result, char *start, size_t size, size_t i)
{
	if (!(result[i] = (char*)malloc(size)))
		return ;
	ft_strlcpy(result[i], start, size);
}

char			**ft_split(char const *s, char c)
{
	char		**result;
	char		*start;
	size_t		i;
	size_t		size;

	i = 0;
	if (s == 0)
		return (0);
	if (!(result = (char**)malloc(sizeof(char*) * count_word(s, c) + 1)))
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			start = (char*)s;
			while (*s && *s != c)
				++s;
			size = s - start + 1;
			put_word(result, start, size, i++);
		}
		else
			++s;
	}
	result[i] = 0;
	return (result);
}
