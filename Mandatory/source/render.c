/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:23 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/26 11:46:36 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	print_map(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map && map[x])
	{
		while (map[x][y])
		{
			printf("%c", map[x][y]);
			y++;
		}
		printf("\n");
		x++;
		y = 0;
	}
}
int	count_y(char **s)
{
	int i, y;
	i = 0;
	y = 0;
	while (s && s[y] && s[y][i])
	{
		while (s[y][i])
		{
			i++;
		}
		i = 0;
		y++;
	}
	return (y);
}

void	opendoor(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->asset->open_door, game->ex * 50
		+ game->cnsty, game->ey * 50 + game->cnstx);
}

void	load_map(t_game *game, t_assets *assets)
{
	int	w;

	w = 50;
	game->x = 0;
	game->y = 0;
	while (game->map && game->map[game->x] && game->map[game->x][game->y])
	{
		while (game->map[game->x][game->y])
		{
			if (game->map[game->x][game->y] == 'P')
			{
				game->playerx = game->x;
				game->playery = game->y;
			}
			put_edge(game, game->edges, game->x, game->y);
			game->y++;
			game->b += 50;
		}
		game->y = 0;
		game->b = 0;
		game->x++;
		game->a += 50;
	}
}
