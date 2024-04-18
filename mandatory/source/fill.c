/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:45 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/18 21:21:00 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**remove_leak(char **buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		free(buff[i]);
		i++;
	}
	free(buff);
	return (NULL);
}

void	check_path(int x, int y, char **map)
{
	if (map && map[x] && map[x][y])
	{
		if (map[x][y] == '0' || map[x][y] == 'C' || map[x][y] == 'P')
		{
			map[x][y] = '1';
			check_path(x + 1, y, map);
			check_path(x - 1, y, map);
			check_path(x, y + 1, map);
			check_path(x, y - 1, map);
		}
	}
}

char	**ft_strdupdup(char **str)
{
	int		i;
	char	**new;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (count_y(str) + 1));
	while (str && str[i])
	{
		new[i] = ft_strdup(str[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
void	player_pos(t_game *game)
{
	while (game->map && game->map[game->x] && game->map[game->x][game->y])
	{
		while (game->map[game->x][game->y])
		{
			if (game->map[game->x][game->y] == 'P')
			{
				game->playerx = game->x;
				game->playery = game->y;
			}
			game->y++;
		}
		game->y = 0;
		game->x++;
	}
}
int	check_fill(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	x = 0;
	y = 0;
	map = ft_strdupdup(game->map);
	player_pos(game);
	check_path(game->playerx, game->playery, map);
	while (map && map[x])
	{
		while (map[x][y])
		{
			if (map[x][y] == 'C')
			{
				remove_leak(map);
				return (0);
			}
			y++;
		}
		y = 0;
		x++;
	}
	// remove_leak(map);
	return (1);
}

// int main(int ac,char **av)
// {
// 	t_game *game;
// 	va = malloc(sizeof(t_game));
// 	game->map = full_map(ft_readmap(av[1]));
// 	char **new = ft_strdupdup(game->map);
// 	int x,y ;
// 	x = 0;
// 	y = 0;
// 	check_fill(game);

// 	while (new && new[x])
// 	{
// 		if (new[x][y])
// 		{
// 			printf("%s\n",new[x]);
// 		}
// 		x++;
// 	}
// 	printf("check fill : %d",check_fill(game));
// }