/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:50:21 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 22:23:16 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_collision(int y, int x, int py, int px)
{
	int	h;

	h = 30;
	if (x < px + h && x + h > px && y < py + h && y + h > py)
		return (1);
	return (0);
}

int	check_door_collision(int y, int x, int py, int px)
{
	int	h;

	h = 20;
	if (x < px + h && x + h > px && y < py + h && y + h > py)
		return (1);
	return (0);
}

static int	more_utils(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		if (check_collision(y * 50, x * 50, game->playery, game->playerx))
		{
			game->map[y][x] = '0';
			render(game, game->asset);
			game->coin.is_collected = 1;
			game->coin.x = x ;
			game->coin.y = y;
			game->c--;
			return (0);
		}
	}
	else if (game->map[y][x] == '0')
	{
		if (check_collision(y * 50, x * 50, game->playery, game->playerx))
		{
			game->map[y][x] = 'P';
			game->map[game->last_y][game->last_x] = '0';
			game->last_x = x;
			game->last_y = y;
			return (0);
		}
	}
	return (1);
}

static int	more(t_game *game, int py, int px, int y)
{
	int	x;

	x = 0;
	while (game->map[y][x])
	{
		if (more_utils(game, x, y) == 0)
			return (0);
		if (game->map[y][x] == 'X')
		{
			if (check_collision(y * 50, x * 50, py, px))
			{
				write(1, "You Lost\n", 9);
				exit(win(game));
			}
		}
		else if (game->map[y][x] == '1')
		{
			if (check_collision(y * 50, x * 50, py, px))
				return (1);
		}
		x++;
	}
	return (0);
}

int	collition(t_game *game, int py, int px)
{
	int	y;

	y = 0;
	while (game->map[y])
	{
		if (more(game, py, px, y))
			return (1);
		y++;
	}
	return (0);
}
