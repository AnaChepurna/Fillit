/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:07:37 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/04 16:25:32 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 20
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char			**g_map;
int				g_mapsize;

typedef struct	s_tetrimino
{
	int			**map;
	int			y;
	int			x;
	char		c;
}				t_tetrimino;

t_tetrimino		*g_tetri[27];

/*
 ** input_handle.c
*/
int				input_handle(char *file);

/*
 ** input_validate.c
*/
int				check_symbol(char c);
int				buf_validate(char *buf);

/*
 ** tetrimino_create.c
*/
void			create_tetri(char *buf, int i);

/*
 ** solve.c
*/
void			start(t_tetrimino **tetri);

/*
 ** tetrimino_manipulate.c
*/
int				check_position(t_tetrimino *tetri, int y, int x);
void			add_tetri(t_tetrimino *tetri, int y, int x);
void			remove_tetri(t_tetrimino *tetri, int y, int x);
void			print_tetri(t_tetrimino *tetri);

/*
 ** map_manipulate.c
*/
int				get_mapsize(void);
char			**init_map(void);
void			print_map(void);

/*
 ** utils.c
*/
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_arrfree(void);
char			*ft_strnew(int size);

#endif
