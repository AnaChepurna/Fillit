/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:34:26 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/04 12:43:05 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					check_symbol(char c)
{
	if (c == '#')
		return (0);
	if (c == '.')
		return (1);
	else
		return (2);
}

static int			check_bridge(char *buf, int i)
{
	if (i > 21 || check_symbol(buf[i]))
		return (0);
	return (1);
}

static int			symbol_validate(char *buf, int i, int *hash, int *bridge)
{
	int				symbol;

	symbol = check_symbol(buf[i]);
	if (symbol == 2)
		return (0);
	if (symbol == 0)
	{
		(*hash)++;
		if (*hash <= 4)
			*bridge += check_bridge(buf, i + 1) + check_bridge(buf, i + 5);
		else
			return (0);
	}
	return (1);
}

int					buf_validate(char *buf)
{
	int		i;
	int		hash;
	int		bridge;

	hash = 0;
	bridge = 0;
	i = -1;
	while (buf[++i])
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			if (buf[i] != '\n')
				return (0);
		}
		else
		{
			if (!symbol_validate(buf, i, &hash, &bridge))
				return (0);
		}
	}
	return (hash == 4 && bridge >= 3 && i == BUFF_SIZE);
}
