#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char *ft_readmap(char *map_name)
{
	int	fd;
	char *map;
	char *temp;
	char *line;
	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	temp = NULL;
	map = NULL;
	while (line && line[0])
	{
		temp = ft_strjoin(map,line);
		free(map);
		free(line);
		map = temp;
		line = get_next_line(fd);
	}
	return (map);
}
char **full_map(char *map)
{
	char **full_map;
	if (!map)
		return (NULL);
	full_map = ft_split(map, '\n');
	free(map);
	return (full_map);
}

int count_c(t_vars *v)
{
	char	**map = v->map;
	int		x;
	int		y;
	int		i;

	i = 0;
	y =0;
	x = 0;
	while (map && map[y] && map[x][y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				i++;
			x++;
		}
		x = 0;
		y++;
	}
	return (i);
}