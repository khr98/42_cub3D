/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerkim <hyerkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:56:34 by hyerkim           #+#    #+#             */
/*   Updated: 2020/10/07 21:46:30 by hyerkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newnode)
{
	t_list *curr;

	if (lst == 0 || newnode == 0)
		return ;
	if (*lst == 0)
	{
		*lst = newnode;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	curr->next = newnode;
}
