/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:28:34 by aalhamel          #+#    #+#             */
/*   Updated: 2021/10/26 13:28:38 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	elem = 0;
	if (!lst)
		return ;
	while (*lst)
	{
		elem = *lst;
		*lst = (*lst)->next;
		del((elem)->content);
		free(elem);
	}
}
