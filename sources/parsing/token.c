/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:15:58 by aalhamel          #+#    #+#             */
/*   Updated: 2022/12/15 18:00:13 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"parser.h"

int	get_token(char **cursor)
{
	int	token;

	while (**cursor && ft_strchr(SPACES, **cursor))
		(*cursor)++;
	token = **cursor;
	if (**cursor == '|')
		(*cursor)++;
	else if (**cursor == '>')
	{
		(*cursor)++;
		if (**cursor == '>')
		{
			(*cursor)++;
			token = '+';
		}
	}
	else if (**cursor == '<')
	{
		(*cursor)++;
		if (**cursor == '<')
		{
			(*cursor)++;
			token = '-';
		}
	}
	else if (**cursor)
		token = 'a';
	while (**cursor && ft_strchr(SPACES, **cursor))
		(*cursor)++;
	return (token);
}
