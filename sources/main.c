/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:14:19 by aalhamel          #+#    #+#             */
/*   Updated: 2022/12/16 17:24:31 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "executer.h"

t_appinfo	g_appinfo;

static void	init_fd(void)
{
	int	fd;

	fd = open("console", O_RDWR);
	while (fd >= 0)
	{
		if (fd >= 2)
			break ;
		fd = open("console", O_RDWR);
	}
}

static void	exit_fd(void)
{
	int	fd;

	fd = 0;
	while (fd <= 2)
	{
		close(fd);
		fd++;
	}
}

void	exit_app(int status)
{
	exit_fd();
	exit(status);
}

void	update_exitstatus(void)
{
	char	*temp;
	char	*keyvalue;

	temp = ft_itoa(g_appinfo.exit_status);
	keyvalue = ft_strjoin("?=", temp);
	free(temp);
	add_keymap(&g_appinfo.env->kms, keyvalue, 0);
	free(keyvalue);
}

int	main(int ac, char **av, char **env)
{
	char	*buf;

	(void)ac;
	(void)av;
	define_input_signals();
	init_fd();
	g_appinfo.exit_status = 0;
	g_appinfo.env = init_env(env);
	while (getcmd("minishell> ", &buf) >= 0)
	{
		g_appinfo.pipe_out = -1;
		g_appinfo.cmd = parser(buf, g_appinfo.env);
		runcmd(g_appinfo.cmd);
		update_exitstatus();
		free(buf);
		clear_cmd(g_appinfo.cmd);
		g_appinfo.cmd = NULL;
	}
	exit_app(g_appinfo.exit_status);
	return (g_appinfo.exit_status);
}
