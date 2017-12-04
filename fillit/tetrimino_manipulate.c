/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_manipulate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 21:12:52 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/04 12:13:06 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_position(t_tetrimino *tetri, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetri->y)
	{
		j = 0;
		while (j < tetri->x)
		{
			if (i + y >= g_mapsize && x + j >= g_mapsize)
				return (0);
			if (g_map[i + y][j + x] && tetri->map[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		add_tetri(t_tetrimino *tetri, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetri->y)
	{
		j = 0;
		while (j < tetri->x)
		{
			if (tetri->map[i][j])
				g_map[y + i][x + j] = tetri->c;
			j++;
		}
		i++;
	}
}

void		remove_tetri(t_tetrimino *tetri, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetri->y)
	{
		j = 0;
		while (j < tetri->x)
		{
			if (g_map[y + i][x + j] == tetri->c)
				g_map[y + i][x + j] = '\0';
			j++;
		}
		i++;
	}
}

void		print_tetri(t_tetrimino *tetri)
{
	int		i;
	int		j;

	i = 0;
	while (i < tetri->y)
	{
		j = 0;
		while (j < tetri->x)
		{
			if (tetri->map[i][j])
				ft_putchar(tetri->c);
			else
				ft_putchar('.');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
