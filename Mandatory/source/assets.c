/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:18 by het-taja          #+#    #+#             */
/*   Updated: 2024/05/02 17:32:03 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_assets(t_game *game)
{
	int	w;

	w = 50;
	game->asset->coin = mlx_xpm_file_to_image(game->mlx, "./assets/coin.xpm", &w, &w);
	game->asset->floor = mlx_xpm_file_to_image(game->mlx, "./assets/floor1.xpm", &w, &w);
	game->asset->wall = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm", &w, &w);
	game->asset->door = mlx_xpm_file_to_image(game->mlx, "./textures/door/closed_door.xpm", &w, &w);
	game->asset->open_door = mlx_xpm_file_to_image(game->mlx, "./textures/door/opendoor.xpm", &w, &w);

}

void	player_assets(t_game *game)
{
	int	w;

	w = 50;
	game->asset->player = mlx_xpm_file_to_image(game->mlx,
			"./assets/player.xpm", &w, &w);
	game->asset->playerl = mlx_xpm_file_to_image(game->mlx,
			"./assets/playerl.xpm", &w, &w);

}

