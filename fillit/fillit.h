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

/*solve.c*/
int		solve(t_tetrimino **tetri);
void		start(t_tetrimino **tetri);

/*tetrimino_manipulate.c*/
int		check_position(t_tetrimino *tetri, int y, int x);
void		add_tetri(t_tetrimino *tetri,int y, int x);
void		remove_tetri(t_tetrimino *tetri, int y, int x);
void		print_tetri(t_tetrimino *tetri);

/*map_manipulate.c*/
int		get_mapsize(t_tetrimino **tetri);
char		**init_map(void);
void		print_map(void);

#endif
