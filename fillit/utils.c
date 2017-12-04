/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:25:45 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/04 16:46:39 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_arrfree()
{
	int		i;

	i = 0;
	while (i < g_mapsize)
	{
		free(g_map[i]);
		i++;
	}
	free(g_map);
	g_map = NULL;
}

char	*ft_strnew(int size)
{
	char	*str;
	int		i;

	str = (char *)malloc(size + 1);
	if (str)
	{
		i = 0;
		while (i <= size)
			str[i++] = '\0';
	}
	return (str);
}
