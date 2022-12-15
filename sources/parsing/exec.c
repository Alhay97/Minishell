/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:15:37 by aalhamel          #+#    #+#             */
/*   Updated: 2022/12/15 18:04:09 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmd	*parse_execmd(char **cursor, t_env *env)
{
	t_execmd	*execmd;
	t_cmd		*cmd;
	int			argc;

	argc = get_argc(*cursor);
	if (argc == 0)
		exit(1); // TODO: change later
	cmd = new_execmd(argc, env);
	execmd = (t_execmd *)cmd;
	if (set_argv(*cursor, execmd->argv, env))
		return (0);
	cmd = parse_redircmd(cmd, cursor, env);
	return (cmd);
}

t_cmd	*new_execmd(int argc, t_env *env)
{
	t_execmd	*execmd;

	execmd = malloc(sizeof(t_execmd));
	if (execmd == NULL)
		exit(1);
	execmd->type = EXEC;
	execmd->argv = (char **)malloc(sizeof(char *) * (argc + 1));
	if (execmd->argv == NULL)
		exit(1);
	execmd->env = env;
	return ((t_cmd *)execmd);
}
