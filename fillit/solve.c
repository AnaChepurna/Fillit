#include "fillit.h"

int	solve(t_tetrimino **tetri)
{
	int	i;
	int	j;

	if (!*tetri)
		return (1);
	i = 0;
	while (i < g_mapsize - (*tetri)->y)
	{
		j = 0;
		while (j < g_mapsize - (*tetri)->x)
		{
			if (check_position(*tetri, i, j))
			{
				add_tetri(*tetri, i, j);
				if (solve(++tetri))
					return (1);
				else
					remove_tetri(*tetri, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	start(t_tetrimino **tetri)
{
	g_map = init_map(tetri);
	if (!solve(tetri))
	{
		g_mapsize++;
		ft_arrfree(g_map);
		start(tetri);
	}
}
