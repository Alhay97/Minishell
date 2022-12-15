/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:15:46 by aalhamel          #+#    #+#             */
/*   Updated: 2022/12/15 17:56:33 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*move_cursor(t_cmd *cmd, char **cursor, t_env *env)
{
	int	token;

	token = get_token(cursor);
	if (token == 0)
		return (0);
	if (token == 'a')
		(*cursor) += readpureword_size(*cursor);
	return (parse_redircmd(cmd, cursor, env));
}

t_cmd	*parser(char *cursor, t_env *env)
{
	t_cmd	*cmd;

	if (!*cursor)
		return (0);
	cmd = parse_pipe(&cursor, env);
	return (cmd);
}

int	peek(char **cursor, char *toks)
{
	while (**cursor && ft_strchr(SPACES, **cursor))
		(*cursor)++;
	return (**cursor && ft_strchr(toks, **cursor));
}
