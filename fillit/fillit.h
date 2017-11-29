#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define BUFF_SIZE 21

char	**g_map;
int	g_mapsize;

typedef struct	s_tetrimino
{
	int	**map;
	int	y;
	int	x;
	char	c;
}		t_tetrimino;

#endif
