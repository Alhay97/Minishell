/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:16:06 by aalhamel          #+#    #+#             */
/*   Updated: 2022/12/11 13:16:21 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_pwd(void)
{
	char	*buff;

	buff = NULL;
	return (getcwd(buff, 0));
}

void	ft_pwd(void)
{
	char	*pwd;
	t_list	*curr;

	pwd = ft_get_pwd();
	if (pwd)
	{
		ft_printf("%s\n", pwd);
		free(pwd);
	}
	else
	{
		curr = find_keymap_key(g_appinfo.env->kms, "PWD");
		if (curr)
			ft_printf("%s\n", ((t_kms *)curr->content)->val);
		else
			ft_printf("error: can't find PWD\n");
	}
}

void	ft_update_pwd(char *key, t_env *env)
{
	t_list	*curr;
	char	*keyvalue;
	char	*keytemp;
	char	*pwdtemp;

	keyvalue = NULL;
	curr = find_keymap_key(env->kms, key);
	if (curr)
	{
		keytemp = ft_strjoin(key, "=");
		pwdtemp = ft_get_pwd();
		if (!pwdtemp)
		{
			free(keytemp);
			free(pwdtemp);
			return ;
		}
		keyvalue = ft_strjoin(keytemp, pwdtemp);
		free(keytemp);
		free(pwdtemp);
		free(((t_kms *)curr->content)->key);
		free(((t_kms *)curr->content)->val);
		update_keymap((t_kms *)curr->content, keyvalue);
		free(keyvalue);
	}
}
