/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:15:03 by dzabrots          #+#    #+#             */
/*   Updated: 2017/12/03 15:36:27 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			check_symbol(char c)
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
	int 			symbol;
	
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

static int			buff_validate(char *buf)
{
	int 			i;
	int 			hash;
	int 			bridge;

	//
	printf("%s\n", buf);
	//
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

int				input_handle(char *file)
{
	int 		fd;
	int 		ret;
	char 		buf[BUFF_SIZE + 1];
	int			i;

	if((fd = open(file, O_RDONLY)) == -1)
		return (0);
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) && i < 26)
	{
		buf[ret] = '\0';
		if (!buff_validate(buf))
			return (0);
		//create_tetri(buf);
		if (!read(fd, buf, 1))
			return (1);
		else if (buf[0] != '\n')
			return (0);
		i++;
	}
	return (0);
}
