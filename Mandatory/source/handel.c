/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:28 by het-taja          #+#    #+#             */
/*   Updated: 2024/05/01 17:45:49 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_readmap(char *map_name)
{
	int		fd;
	char	*map;
	char	*temp;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		{
			write(1, "ERROR While Opening Map file\n", 29);
			exit (1);
		}
	line = get_next_line(fd);
	temp = NULL;
	map = NULL;
	while (line && line[0])
	{
		temp = ft_strjoin(map, line);
		free(map);
		free(line);
		map = temp;
		line = get_next_line(fd);
	}
	return (map);
}

char	**full_map(char *map)
{
	char	**full_map;

	if (!map)
		return (NULL);
	full_map = ft_split(map, '\n');
	free(map);
	return (full_map);
}

int	count_c(t_game *game)
{
	char	**map;
	int		x;
	int		y;
	int		i;

	map = game->map;
	i = 0;
	y = 0;
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
