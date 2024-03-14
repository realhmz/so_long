#include <mlx.h>
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
	if (!map)
		return (NULL);
	return (ft_split(map, '\n'));
}