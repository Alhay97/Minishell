/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:16:09 by aalhamel          #+#    #+#             */
/*   Updated: 2022/12/11 13:16:10 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(char **argv, t_env *env)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		remove_keymap(&env->kms, argv[i]);
		i++;
	}
}
