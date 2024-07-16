/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 10:44:30 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 22:01:41 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	flood_fill_enemy(t_game *game)
{
	char	**tmp;

	tmp = map_dup(game->enemy_map);
	check_path(game->playerx / 50, game->playery / 50, tmp, 'C');
	if (check_fill(tmp, 'C') == -1)
	{
		clear_map(tmp);
		tmp = NULL;
		return (-1);
	}
	check_path_exit(game->playerx / 50, game->playery / 50, tmp, 'E');
	if (check_fill(tmp, 'E') == -1)
	{
		clear_map(tmp);
		tmp = NULL;
		return (-1);
	}
	clear_map(tmp);
	tmp = NULL;
	return (0);
}

static int	enemy_util(t_game *game, int x, int y)
{
	if (game->enemy_map[y][x] == '0')
	{
		game->enemy_map[y][x] = 'X';
		if (flood_fill_enemy(game) != -1)
		{
			game->map[y][x] = 'X';
			game->en_x = x;
			game->en_y = y;
			return (0);
		}
		else
			game->enemy_map[y][x] = '0';
	}
	return (1);
}

int	put_enemy(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->enemy_map[y])
	{
		x = 0;
		while (game->enemy_map[y][x])
		{
			if (enemy_util(game, x, y) == 0)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	patrol_util(t_game *game)
{
	if (game->map[game->en_y][game->en_x + 1] == '0'
			|| game->map[game->en_y][game->en_x + 1] == 'P')
	{
		game->map[game->en_y][game->en_x + 1] = 'X';
		game->map[game->en_y][game->en_x] = '0';
		game->en_x++;
		return (1);
	}
	else if (game->map[game->en_y - 1][game->en_x] == '0'
			|| game->map[game->en_y - 1][game->en_x] == 'P')
	{
		game->map[game->en_y - 1][game->en_x] = 'X';
		game->map[game->en_y][game->en_x] = '0';
		game->en_y--;
		return (1);
	}
	return (0);
}

void	patrol(t_game *game)
{
	if (patrol_util(game))
		return ;
	else if (game->map[game->en_y + 1][game->en_x] == '0'
			|| game->map[game->en_y + 1][game->en_x] == 'P')
	{
		game->map[game->en_y + 1][game->en_x] = 'X';
		game->map[game->en_y][game->en_x] = '0';
		game->en_y++;
	}
	else if (game->map[game->en_y][game->en_x - 1] == '0'
			|| game->map[game->en_y][game->en_x - 1] == 'P')
	{
		game->map[game->en_y][game->en_x - 1] = 'X';
		game->map[game->en_y][game->en_x] = '0';
		game->en_x--;
	}
}
