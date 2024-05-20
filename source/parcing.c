/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:32:02 by het-taja          #+#    #+#             */
/*   Updated: 2024/05/20 14:42:02 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	parcing(t_game *game, char *map)
{
	if (read_map(game, map) == -1 || 	parce_map(game->map) == -1 || map_walls(game) == -1)
		return (-1);
	player_pos(game);
	exit_pos(game);
    game->c = count_c(game);
    game->total_coin = game->c;
	return (0);
}
int read_map(t_game *game, char *map)
{
    int		fd;
    char	*buff;
	int		readed;

    fd = open(map, O_RDONLY);
	if (fd == -1)
		return -1;
	buff = malloc(220);
    readed = read(fd, buff, 219);
	buff[readed] = '\0';
	if (read(fd, buff, 10))
	{
		free(buff);
		return (-1);
	}
	close (fd);
    game->map = ft_split(buff, '\n');
	if (count_newline(buff, game->map) == -1)
	{
		free(buff);
		free(game->map);
		return(-1);
	}
	free(buff);
	return (0);
}

int	map_walls(t_game *game)
{
	int	x;
	int	y;
	int	hight;
	int	len;

	y = 0;
	len = ft_strlen(game->map[y]);
	hight = -1;
	while (game->map && game->map[y])
	{
		if (game->map[y][0] != '1' || game->map[y][len - 1] != '1')
			return (-1);
		y++;
		hight++;
	}
	x = 0;
	while (game->map[hight][x] && game->map[0][x])
	{
		if (game->map[hight][x] != '1' || game->map[0][x] != '1')
			return (-1);
		x++;
	}
	return (0);
}
int parce_map(char **str)
{
	int	x;
	int	y;
	int	len;
	
	x = 0;
	y = 0;
	if (!str)
	{
		printf("no map\n");
		return (-1);
	}
	if (ft_count_char(str, 'P') != 1 || ft_count_char(str, 'E') != 1)
		return (-1);
	len = ft_strlen(str[0]);
	while (str && str[y])
	{
		if (ft_strlen(str[y]) != len)
		{
			printf("map len \n");
			return (-1);
		}
		y++;
	}
	return (0);
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

void	exit_pos(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map && game->map[y])
	{
		x = 0;
		while (game->map[y] && game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				game->ex = x;
				game->ey = y;
			}
			x++;
		}
		y++;
	}
}
int	ft_count_char(char **str, char c)
{
	int	i;
	int x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	if (!str)
	{
		return (-1);
	}
	
	while(str && str[y])
	{
		x = 0;
		while(str[y] && str[y][x])
		{
			if (str[y][x] == c)
				i++;
			x++;
		}
		y++;
	}
	return i;
}

int	count_newline(char *str, char **map)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			x++;
		i++;
	}
	i = 0;
	while (map && map[i])
		i++;
	printf("i : %d, x %d \n",i,x);
	if (i != x + 1)
		return (-1);
	return (x);
}

void    clear_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	// free(map);
}
int check_file_name(char *str)
{
	int	i;
	int	fd;

	fd = open(str, O_RDONLY);
	if (!fd || fd == -1)
		return -1;
	i = ft_strlen(str);
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' || str[i
		- 3] != '.' || !fd || fd == -1)
		return (0);
	close(fd);
	return (1);
}