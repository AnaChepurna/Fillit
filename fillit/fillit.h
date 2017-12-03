/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:07:37 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/02 20:43:08 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

//# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 20

char	**g_map;
int		g_mapsize;

typedef struct	s_tetrimino
{
	int			**map;
	int			y;
	int			x;
	char		c;
}				t_tetrimino;

/*input_handle.c*/

int			input_handle(char *file);

/*solve.c*/

int			solve(t_tetrimino **tetri);
void		start(t_tetrimino **tetri);

/*tetrimino_manipulate.c*/

int			check_position(t_tetrimino *tetri, int y, int x);
void		add_tetri(t_tetrimino *tetri, int y, int x);
void		remove_tetri(t_tetrimino *tetri, int y, int x);
void		print_tetri(t_tetrimino *tetri);

/*map_manipulate.c*/

int			get_mapsize(t_tetrimino **tetri);
char		**init_map(void);
void		print_map(void);

#endif
