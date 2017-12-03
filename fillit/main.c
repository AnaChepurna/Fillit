/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:59:46 by dzabrots          #+#    #+#             */
/*   Updated: 2017/12/03 18:18:23 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int c, char **v)
{
	if (c != 2)
		printf("usage: fillit input_file\n");
	else
	{
		if (input_handle(v[1]))
			printf("valide input!\n");
		else
			printf("invalid input!\n");
		int i = 0;
		while (g_tetri[i])
		{
			print_tetri(*g_tetri);
			printf("\n");
			i++;
		}
	}
}
