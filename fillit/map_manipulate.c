#include "fillit.h"

int     get_mapsize(t_tetrimino **tetri)
{
        int     tetri_count;
        int     mapsize;

        tetri_count = 0;
        while (tetri[tetri_count])
                tetri_count++;
        mapsize = 2;
        while (mapsize * mapsize < tetri_count * 4)
                mapsize++;
        return (mapsize);
}

char    **init_map(void)
{
    char    **res;
	int	i;

	if ((res = (char **)malloc(sizeof(char *) * g_mapsize)))
	{
		i = 0;
		while (i < g_mapsize)
		{
			res[i] = ft_strnew(g_mapsize);
			i++;
		}	
	}
	return (res);
}

void	print_map(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_mapsize)
	{
		j = 0;
		while (j < g_mapsize)
		{
			if (g_map[i][j])
				printf("%c", g_map[i][j]);
			else
				printf(".");
			j++;
		}
		printf("\n");
		i++;
	}
}

