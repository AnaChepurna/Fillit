/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:15:03 by dzabrots          #+#    #+#             */
/*   Updated: 2017/12/04 12:43:19 by achepurn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			input_read(int fd)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	int				i;

	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) && i < 26)
	{
		buf[ret] = '\0';
		if (!buf_validate(buf))
			return (0);
		create_tetri(buf, i++);
		if (!read(fd, buf, 1))
		{
			g_tetri[i] = NULL;
			return (1);
		}
		else if (buf[0] != '\n')
			return (0);
	}
	return (0);
}

int					input_handle(char *file)
{
	int				fd;
	int				status;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	status = input_read(fd);
	close(fd);
	return (status);
}

