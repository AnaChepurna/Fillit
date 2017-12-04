/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:59:46 by dzabrots          #+#    #+#             */
/*   Updated: 2017/12/04 12:29:36 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int c, char **v)
{
	if (c != 2)
		ft_putstr("usage: fillit input_file\n");
	else
	{
		if (input_handle(v[1]))
		{
			g_mapsize = get_mapsize();
			start(g_tetri);
			print_map();
		}
		else
			ft_putstr("error\n");
	}
}
