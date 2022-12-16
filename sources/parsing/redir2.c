/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:15:55 by aalhamel          #+#    #+#             */
/*   Updated: 2022/12/16 17:43:05 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	checkheredoc_status(int stat, int fd)
{
	if (WEXITSTATUS(stat))
	{
		g_appinfo.exit_status = WEXITSTATUS(stat);
		close(fd);
		g_appinfo.pipe_out = -1;
	}
}
