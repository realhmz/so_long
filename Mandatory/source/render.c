/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:23 by het-taja          #+#    #+#             */
/*   Updated: 2024/05/01 17:06:01 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	put_floor(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->asset->floor, game->y
		* 50 + game->cnsty, game->x * 50 + game->cnstx);
}
void	put_wall(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->asset->wall, game->y
		* 50 + game->cnsty, game->x * 50 + game->cnstx);
}
void	put_coin(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->asset->coin, game->y
		* 50 + game->cnsty, game->x * 50 + game->cnstx);
}
void	put_door(t_game *game)
{
	if (game->c != 0)
		mlx_put_image_to_window(game->mlx, game->win, game->asset->door, game->y
			* 50 + game->cnsty, game->x * 50 + game->cnstx);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->asset->open_door,
			game->y * 50 + game->cnsty, game->x * 50 + game->cnstx);
}

void	render(t_game *game)
{
	while (game->map[game->x][game->y])
	{
		put_floor(game);
		if (game->map[game->x][game->y] == 'P')
		{
			game->playerx = game->x;
			game->playery = game->y;
		}
		if (game->map[game->x][game->y] == '1')
			put_wall(game);
		if (game->map[game->x][game->y] == 'C')
			put_coin(game);
		if (game->map[game->x][game->y] == 'E')
			put_door(game);
		game->y++;
		game->b += 50;
	}
}
void	load_map(t_game *game)
{
	int w;

	w = 50;
	game->x = 0;
	game->y = 0;
	while (game->map && game->map[game->x] && game->map[game->x][game->y])
	{
		render(game);
		game->y = 0;
		game->b = 0;
		game->x++;
		game->a += 50;
	}
}