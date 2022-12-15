/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:13:56 by aalhamel          #+#    #+#             */
/*   Updated: 2022/12/11 13:13:57 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *s)
{
	ft_fprintf(2, "%s\n", s);
	exit(1);
}

void	print_export(t_list *lst)
{
	t_list	*sorted;
	t_list	*curr;
	t_kms	*km;

	sorted = sort_keymap_alpha(lst);
	curr = sorted;
	while (curr)
	{
		km = (t_kms *)curr->content;
		if (km->val != NULL)
		{
			if (!ft_strequals(km->key, "_") && !ft_strequals(km->key, "?"))
				ft_printf("declare -x %s=\"%s\"\n", km->key, km->val);
		}
		else
			ft_printf("declare -x %s\n", km->key);
		curr = curr->next;
	}
	free(sorted);
}

void	print_env(t_list *lst)
{
	t_list	*curr;
	t_kms	*km;

	curr = lst;
	while (curr)
	{
		km = (t_kms *)curr->content;
		if (km->val != NULL && !ft_strequals(km->key, "OLDPWD")
			&& !ft_strequals(km->key, "?"))
			ft_printf("%s=%s\n", km->key, km->val);
		curr = curr->next;
	}
}

void	print_keymaps(t_list *lst)
{
	t_list	*curr;
	t_kms	*km;

	curr = lst;
	while (curr)
	{
		km = (t_kms *)curr->content;
		if (km->val != NULL)
			ft_printf("%s=%s\n", km->key, km->val);
		curr = curr->next;
	}
}

void	print_strsplit(char **split)
{
	int		i;

	i = 0;
	while (split[i])
		ft_printf("%s\n", split[i++]);
}
