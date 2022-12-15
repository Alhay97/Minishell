/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:15:52 by aalhamel          #+#    #+#             */
/*   Updated: 2022/12/11 13:24:08 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*parse_pipe(char **cursor, t_env *env)
{
	t_cmd	*cmd;

	cmd = parse_execmd(cursor, env);
	if (peek(cursor, "|"))
	{
		get_token(cursor);
		cmd = new_pipecmd(cmd, parse_pipe(cursor, env));
	}
	return (cmd);
}

t_cmd	*new_pipecmd(t_cmd *left, t_cmd *right)
{
	t_pipecmd	*pipecmd;

	pipecmd = malloc(sizeof(t_pipecmd));
	if (pipecmd == NULL)
		exit(1);
	pipecmd->type = PIPE;
	pipecmd->left = left;
	pipecmd->right = right;
	return ((t_cmd *)pipecmd);
}
