/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:51:35 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 22:13:57 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	more(t_game *game)
{
	game->asset->player = malloc(sizeof(t_img) * 11);
	game->asset->playerl = malloc(sizeof(t_img) * 11);
	game->asset->player[0] = new_file_img("./textures/player/right/p1.xpm",
			game);
	game->asset->player[1] = new_file_img("./textures/player/right/p2.xpm",
			game);
	game->asset->player[2] = new_file_img("./textures/player/right/p3.xpm",
			game);
	game->asset->player[3] = new_file_img("./textures/player/right/p4.xpm",
			game);
	game->asset->player[4] = new_file_img("./textures/player/right/p5.xpm",
			game);
	game->asset->player[5] = new_file_img("./textures/player/right/p6.xpm",
			game);
	game->asset->player[6] = new_file_img("./textures/player/right/p7.xpm",
			game);
	game->asset->player[7] = new_file_img("./textures/player/right/p8.xpm",
			game);
	game->asset->player[8] = new_file_img("./textures/player/right/p9.xpm",
			game);
	game->asset->player[9] = new_file_img("./textures/player/right/p10.xpm",
			game);
	game->asset->player[10] = new_file_img("./textures/player/right/p11.xpm",
			game);
}

void	player_assets(t_game *game)
{
	more(game);
	game->asset->playerl[0] = new_file_img("./textures/player/left/p1l.xpm",
			game);
	game->asset->playerl[1] = new_file_img("./textures/player/left/p2l.xpm",
			game);
	game->asset->playerl[2] = new_file_img("./textures/player/left/p3l.xpm",
			game);
	game->asset->playerl[3] = new_file_img("./textures/player/left/p4l.xpm",
			game);
	game->asset->playerl[4] = new_file_img("./textures/player/left/p5l.xpm",
			game);
	game->asset->playerl[5] = new_file_img("./textures/player/left/p6l.xpm",
			game);
	game->asset->playerl[6] = new_file_img("./textures/player/left/p7l.xpm",
			game);
	game->asset->playerl[7] = new_file_img("./textures/player/left/p8l.xpm",
			game);
	game->asset->playerl[8] = new_file_img("./textures/player/left/p9l.xpm",
			game);
	game->asset->playerl[9] = new_file_img("./textures/player/left/p10l.xpm",
			game);
	game->asset->playerl[10] = new_file_img("./textures/player/left/p11l.xpm",
			game);
}

void	render(t_game *game, t_assets *assets)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	load_it(x, y, game, assets);
}

void	jump(t_game *game)
{
	int	i;

	i = 0;
	if (!collition(game, game->playery + 4, game->playerx))
		return ;
	game->moves++;
	game->player_stat = 0;
	while (!collition(game, game->playery, game->playerx)
		&& i <= 132)
	{
		i++;
		game->playery -= 1;
	}
}

int	map_name(char *map)
{
	int	j;

	j = ft_strlen(map) - 1;
	if (j >= 4 && map && map[0] && map[j - 4] != '/')
	{
		if (map[j] == 'r' && map[j - 1] == 'e' && map[j - 2] == 'b'
			&& map[j - 3] == '.' && map[j - 4])
			return (1);
	}
	return (-1);
}
