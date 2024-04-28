/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:35 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/28 15:29:24 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	player_assets(t_game *game)
{
	int	w;

	w = 50;
	game->asset->player[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/right/p1.xpm", &w, &w);
	game->asset->player[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/right/p2.xpm", &w, &w);
	game->asset->player[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/right/p3.xpm", &w, &w);
	game->asset->player[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/right/p4.xpm", &w, &w);
	game->asset->player[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/right/p5.xpm", &w, &w);
	game->asset->player[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/right/p6.xpm", &w, &w);
	game->asset->playerl[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/p1l.xpm", &w, &w);
	game->asset->playerl[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/p2l.xpm", &w, &w);
	game->asset->playerl[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/p3l.xpm", &w, &w);
	game->asset->playerl[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/p4l.xpm", &w, &w);
	game->asset->playerl[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/p5l.xpm", &w, &w);
	game->asset->playerl[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/p6l.xpm", &w, &w);
}

void	player_assets_women(t_game *game)
{
	int	w;

	w = 50;
	game->asset->player[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/right/p1.xpm", &w, &w);
	game->asset->player[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/right/p2.xpm", &w, &w);
	game->asset->player[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/right/p3.xpm", &w, &w);
	game->asset->player[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/right/p4.xpm", &w, &w);
	game->asset->player[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/right/p5.xpm", &w, &w);
	game->asset->player[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/right/p6.xpm", &w, &w);
	game->asset->playerl[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/left/p1l.xpm", &w, &w);
	game->asset->playerl[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/left/p2l.xpm", &w, &w);
	game->asset->playerl[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/left/p3l.xpm", &w, &w);
	game->asset->playerl[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/left/p4l.xpm", &w, &w);
	game->asset->playerl[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/left/p5l.xpm", &w, &w);
	game->asset->playerl[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/women/left/p6l.xpm", &w, &w);
}
