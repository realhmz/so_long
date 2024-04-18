/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:35 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/18 21:19:11 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	player_assets(t_game *game)
{
	int	w;

	w = 50;
	game->asset->player[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/1.xpm", &w, &w);
	game->asset->player[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/2.xpm", &w, &w);
	game->asset->player[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/3.xpm", &w, &w);
	game->asset->player[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/4.xpm", &w, &w);
	game->asset->player[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/5.xpm", &w, &w);
	game->asset->player[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/6.xpm", &w, &w);
	game->asset->playerl[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/1.xpm", &w, &w);
	game->asset->playerl[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/2.xpm", &w, &w);
	game->asset->playerl[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/3.xpm", &w, &w);
	game->asset->playerl[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/4.xpm", &w, &w);
	game->asset->playerl[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/5.xpm", &w, &w);
	game->asset->playerl[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/left/6.xpm", &w, &w);
}
