/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:06:49 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 21:48:52 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	start_game(t_game *game)
{
	game->asset = (t_assets *)malloc(sizeof(t_assets));
	game->enemy_map = map_dup(game->map);
	game_assets(game->asset, game);
	return (0);
}

void	idle_assets(t_game *game)
{
	game->asset->idle = malloc(sizeof(t_img) * 11);
	game->asset->idle[0] = new_file_img("./textures/player/idle/i1.xpm",
			game);
	game->asset->idle[1] = new_file_img("./textures/player/idle/i1.xpm",
			game);
	game->asset->idle[2] = new_file_img("./textures/player/idle/i1.xpm",
			game);
	game->asset->idle[3] = new_file_img("./textures/player/idle/i1.xpm",
			game);
	game->asset->idle[4] = new_file_img("./textures/player/idle/i1.xpm",
			game);
	game->asset->idle[5] = new_file_img("./textures/player/idle/i1.xpm",
			game);
	game->asset->idle[6] = new_file_img("./textures/player/idle/i1.xpm",
			game);
	game->asset->idle[7] = new_file_img("./textures/player/idle/i8.xpm",
			game);
	game->asset->idle[8] = new_file_img("./textures/player/idle/i9.xpm",
			game);
	game->asset->idle[9] = new_file_img("./textures/player/idle/i10.xpm",
			game);
	game->asset->idle[10] = new_file_img("./textures/player/idle/i10.xpm",
			game);
}

int	game_assets(t_assets *assets, t_game *game)
{
	game->base = new_img(game->win_w, game->win_h, game);
	assets->floor = new_file_img("./textures/floor.xpm", game);
	assets->door = new_file_img("./textures/door.xpm", game);
	assets->enemy = new_file_img("./textures/enemy.xpm", game);
	game->last_x = game->playerx / 50;
	game->last_y = game->playery / 50;
	game->enemy = 0;
	if (put_enemy(game) == 0)
		game->enemy = 1;
	player_assets(game);
	edge_assets(game);
	idle_assets(game);
	game->coin.x = 0;
	game->coin.y = 0;
	game->coin.is_collected = 0;
	coin_assets(game);
	game->is_jump = 0;
	return (0);
}

void	ft_put(t_game *game, t_img img, int x, int y)
{
	put_img_to_img(game->base, img, x, y);
}

void	load_it(int x, int y, t_game *game, t_assets *assets)
{
	while (game->map && game->map[y])
	{
		x = 0;
		while (game->map[y] && game->map[y][x])
		{
			put_edge(game, game->asset->e, x, y);
			if (game->map[y][x] == 'X')
				ft_put(game, game->asset->enemy, x * 50, y * 50);
			if (game->map[y][x] == 'E')
			{
				ft_put(game, assets->door, x * 50, y * 50);
				if (check_door_collision(y * 50, x * 50, game->playery,
						game->playerx)
					&& game->c == 0)
					exit(win(game));
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->base.img_ptr, 0, 0);
}
