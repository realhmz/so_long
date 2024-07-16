/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 21:10:04 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 21:22:46 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	more(t_game *game)
{
	game->asset->coin_idle = malloc(sizeof(t_img) * 11);
	game->asset->coin_idle[0] = new_file_img("./textures/coin/idle/i1.xpm",
			game);
	game->asset->coin_idle[1] = new_file_img("./textures/coin/idle/i1.xpm",
			game);
	game->asset->coin_idle[2] = new_file_img("./textures/coin/idle/i2.xpm",
			game);
	game->asset->coin_idle[3] = new_file_img("./textures/coin/idle/i3.xpm",
			game);
	game->asset->coin_idle[4] = new_file_img("./textures/coin/idle/i4.xpm",
			game);
	game->asset->coin_idle[5] = new_file_img("./textures/coin/idle/i5.xpm",
			game);
	game->asset->coin_idle[6] = new_file_img("./textures/coin/idle/i6.xpm",
			game);
	game->asset->coin_idle[7] = new_file_img("./textures/coin/idle/i7.xpm",
			game);
	game->asset->coin_idle[8] = new_file_img("./textures/coin/idle/i8.xpm",
			game);
	game->asset->coin_idle[9] = new_file_img("./textures/coin/idle/i9.xpm",
			game);
	game->asset->coin_idle[10] = new_file_img("./textures/coin/idle/i10.xpm",
			game);
}

void	coin_assets(t_game *game)
{
	more(game);
	game->asset->coin = malloc(sizeof(t_img) * 11);
	game->asset->coin[0] = new_file_img("./textures/coin/coin2.xpm",
			game);
	game->asset->coin[1] = new_file_img("./textures/coin/coin2.xpm",
			game);
	game->asset->coin[2] = new_file_img("./textures/coin/coin2.xpm",
			game);
	game->asset->coin[3] = new_file_img("./textures/coin/coin3.xpm",
			game);
	game->asset->coin[4] = new_file_img("./textures/coin/coin4.xpm",
			game);
	game->asset->coin[5] = new_file_img("./textures/coin/coin5.xpm",
			game);
	game->asset->coin[6] = new_file_img("./textures/coin/coin6.xpm",
			game);
	game->asset->coin[7] = new_file_img("./textures/coin/coin7.xpm",
			game);
	game->asset->coin[8] = new_file_img("./textures/coin/coin8.xpm",
			game);
	game->asset->coin[9] = new_file_img("./textures/coin/coin9.xpm",
			game);
	game->asset->coin[10] = new_file_img("./textures/coin/coin10.xpm",
			game);
}
