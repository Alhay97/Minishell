/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalhamel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:24:34 by aalhamel          #+#    #+#             */
/*   Updated: 2021/10/26 13:24:38 by aalhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	a;
	int				p;

	a = 0;
	p = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p = -p;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i])
	{
		a = a * 10;
		a = a + (str[i++] - '0');
	}
	if (a > 2147483648 && p == -1)
		return (0);
	else if (a > 2147483647 && p == 1)
		return (-1);
	return ((int) a * p);
}
