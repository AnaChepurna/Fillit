/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achepurn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:25:45 by achepurn          #+#    #+#             */
/*   Updated: 2017/12/04 13:38:06 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_arrfree(char ***res)
{
	int		i;

	i = 0;
	while ((*res)[i])
		free((*res)[i++]);
	free(*res);
	*res = NULL;
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
