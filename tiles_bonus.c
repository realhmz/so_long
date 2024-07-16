/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:17:08 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 21:22:46 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	wich_edge(t_game *game, int x, int y)
{
	int	up;
	int	down;
	int	right;
	int	left;
	int	i;

	up = 0;
	down = 0;
	right = 0;
	left = 0;
	if (game->map[x] && (game->map[x][y] == '1' ))
	{
		i = 0;
		if (y < (game->win_w -1) / 50 && game->map[x][y + 1] != '1')
			right = 1;
		if (x > 0 / 50 && game->map[x - 1][y] != '1')
			up = 2;
		if (y > 0 && game->map[x][y - 1] != '1')
			left = 4;
		if (x < (game->win_h - 1) / 50 && game->map[x + 1][y] != '1')
			down = 8;
		i = left + right + down + up;
		return (i);
	}
	return (-1);
}

static void	more(t_game *game)
{
	game->asset->e[0] = new_file_img("./textures/tiles/0.xpm",
			game);
	game->asset->e[1] = new_file_img("./textures/tiles/1.xpm",
			game);
	game->asset->e[2] = new_file_img("./textures/tiles/2.xpm",
			game);
	game->asset->e[12] = new_file_img("./textures/tiles/12.xpm",
			game);
	game->asset->e[13] = new_file_img("./textures/tiles/13.xpm",
			game);
	game->asset->e[14] = new_file_img("./textures/tiles/14.xpm",
			game);
	game->asset->e[15] = new_file_img("./textures/tiles/15.xpm",
			game);
}

void	edge_assets(t_game *game)
{
	game->asset->e = malloc(sizeof(t_img) * 16);
	more(game);
	game->asset->e[3] = new_file_img("./textures/tiles/3.xpm",
			game);
	game->asset->e[4] = new_file_img("./textures/tiles/4.xpm",
			game);
	game->asset->e[5] = new_file_img("./textures/tiles/5.xpm",
			game);
	game->asset->e[6] = new_file_img("./textures/tiles/6.xpm",
			game);
	game->asset->e[7] = new_file_img("./textures/tiles/7.xpm",
			game);
	game->asset->e[8] = new_file_img("./textures/tiles/8.xpm",
			game);
	game->asset->e[9] = new_file_img("./textures/tiles/9.xpm",
			game);
	game->asset->e[10] = new_file_img("./textures/tiles/10.xpm",
			game);
	game->asset->e[11] = new_file_img("./textures/tiles/11.xpm",
			game);
}

void	put_edge(t_game *game, t_img *e, int x, int y)
{
	int	i;

	i = wich_edge(game, y, x);
	ft_put(game, game->asset->floor, x * 50, y * 50);
	if (i == -1)
		return ;
	if (game->map[y][x] == '1' && i != -1)
		ft_put(game, e[i], x * 50, y * 50);
}
