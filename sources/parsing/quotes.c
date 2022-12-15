/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <aalhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:01:15 by aalhamel          #+#    #+#             */
/*   Updated: 2022/12/15 17:54:10 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	checkquote(char **cursor, char *quote, int *in_quote)
{
	if (!*in_quote && ft_strchr(QUOTES, **cursor))
		*quote = **cursor;
	if (**cursor == *quote)
	{
		*in_quote = !(*in_quote);
		(*cursor)++;
		return (1);
	}
	if (!*in_quote && (ft_strchr(SPACES, **cursor)
			|| ft_strchr(SYMBOLS, **cursor)))
		return (-1);
	return (0);
}

int	readpureword_size(char *cursor)
{
	int	len;

	len = 0;
	while (*cursor && !ft_strchr(SPACES, *cursor)
			&& !ft_strchr(SYMBOLS, *cursor))
	{
		len++;
		cursor++;
	}
	return (len);
}

int	readword_size(char *cursor, char *quote, t_env *env)
{
	int	len;
	int	inquote;
	int	status;

	len = 0;
	inquote = 0;
	status = 0;
	while (*cursor)
	{
		status = checkquote(&cursor, quote, &inquote);
		if (status == 1)
			continue ;
		if (status == -1)
			break;
		if ((inquote && *quote != '\'' && *cursor == '$')
			|| (!inquote && *cursor == '$'))
		{
			len += expandsize(&cursor, inquote, env);
			continue ;
		}
		len++;
		cursor++;
	}
	if (inquote)
		return (-1);
	return (len);
}

int	write_argv(char **cursor, char **argv, t_env *env)
{
	int		len;
	char	*str;
	int		inquote;
	int		status;
	char 	quote;

	inquote = 0;
	status = 0;
	quote = '\0';
	len = readword_size(*cursor, &quote, env);
	if (len < 0)
	{
		ft_fprintf(2, "syntax - missing %c\n", quote);
		return (1);
	}
	*argv = malloc(sizeof(char) * (len + 1));
	if (*argv == NULL)
		return (0);
	str = *argv;
	while (**cursor)
	{
		status = checkquote(cursor, &quote, &inquote);
		if (status == 1)
			continue ;
		if (status == -1)
			break;
		if ((inquote && quote != '\'' && **cursor == '$') || (!inquote && **cursor == '$'))
		{
			if (!expandline(cursor, &str, env) || !inquote)
				continue ;
			(*cursor)--;
		}
		*str = **cursor;
		str++;
		(*cursor)++;
	}
	*str = '\0';
	return (0);
}
