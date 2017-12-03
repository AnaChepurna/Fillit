/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 16:59:46 by dzabrots          #+#    #+#             */
/*   Updated: 2017/12/03 15:24:22 by achepurn         ###   ########.fr       */
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
	}
}
