/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 21:27:53 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/03 21:28:37 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve(t_tetrimino **tetri)
{
	int		i;
	int		j;

	if (!*tetri)
		return (1);
	i = -1;
	while (++i <= g_mapsize - (*tetri)->y)
	{
		j = -1;
		while (++j <= g_mapsize - (*tetri)->x)
		{
			if (check_position(*tetri, i, j))
			{
				add_tetri(*tetri, i, j);
				if (solve(tetri + 1))
					return (1);
				else
					remove_tetri(*tetri, i, j);
			}
		}
	}
	return (0);
}

void		start(t_tetrimino **tetri)
{
	g_map = init_map();
	if (!solve(tetri))
	{
		g_mapsize++;
//		ft_arrfree(g_map);
		start(tetri);
	}
}
