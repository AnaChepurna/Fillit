/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 16:59:19 by dzabrots          #+#    #+#             */
/*   Updated: 2017/12/03 19:39:53 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		find_corners(char *buf, int *x, int *y)
{
	int i;
	int j;
	
	x[0] = 5;
	x[1] = 0;
	y[0] = 5;
	y[1] = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 5)
		{
			if (!check_symbol(buf[j + i * 5]))
			{
				x[0] = j < x[0] ? j : x[0];
				x[1] = j > x[1] ? j : x[1];
				y[0] = i < y[0] ? i : y[0];
				y[1] = i > y[1] ? i : y[1];
			}
		}
	}
}

void		create_str(char *buf, int *res, int *x, int y)
{
	int i;

	i = x[0];
	while (i <= x[1])
	{
		if (check_symbol(buf[i + y * 5]))
		{
			*res = 0;
		}
		else
			*res = 1;
		res++;
		i++;
	}
}

int			**create_arr(char *buf, int *x, int *y)
{
	int **res;
	int i;
	int height;
	int width;

	height = y[1] - y[0] + 1;
	width = x[1] - x[0] + 1;
	if (!(res = (int **)malloc(sizeof(int *) * height)))
		exit(0);
	i = 0;
	while (i < height)
	{
		if (!(res[i] = (int *)malloc(sizeof(int) * width)))
			exit(0);
		create_str(buf, res[i], x, y[0] + i);
		i++;
	}
	return (res);
}

void		create_tetri(char *buf, int i)
{
	t_tetrimino *tetri;
	int x[2];
	int y[2];

	if (!(tetri = (t_tetrimino *)malloc(sizeof(t_tetrimino))))
		exit(0);
	tetri->c = 'A' + i;
	find_corners(buf, x, y);
	tetri->x = x[1] - x[0] + 1;
	tetri->y = y[1] - y[0] + 1;
	tetri->map = create_arr(buf, x, y);
	g_tetri[i] = tetri;
}
