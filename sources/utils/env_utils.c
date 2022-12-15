/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:32:04 by aalhamel          #+#    #+#             */
/*   Updated: 2022/12/11 13:32:05 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clear_keymap(void *content)
{
	t_kms	*km;

	km = (t_kms *)content;
	free(km->key);
	if (km->val && *km->val)
		free(km->val);
	free(km);
}

void	clear_env(t_env *env)
{
	if (!env)
		return ;
	ft_clearsplit(env->env);
	ft_lstclear(&env->kms, clear_keymap);
	free(env->kms);
	free(env);
}
