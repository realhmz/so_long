/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:18 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/18 22:02:53 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	edge_assets(t_game *game, void **e)
{
	int	w;

	w = 50;
	e[0] = mlx_xpm_file_to_image(game->mlx, "./assets/floor1.xpm", &w, &w);
	e[1] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e1.xpm", &w, &w);
	e[2] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e2.xpm", &w, &w);
	e[3] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e3.xpm", &w, &w);
	e[4] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e4.xpm", &w, &w);
	e[5] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e5.xpm", &w, &w);
	e[6] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e6.xpm", &w, &w);
	e[7] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e7.xpm", &w, &w);
	e[8] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e8.xpm", &w, &w);
	e[9] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e9.xpm", &w, &w);
	e[10] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e10.xpm", &w, &w);
	e[11] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e11.xpm", &w, &w);
	e[12] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e12.xpm", &w, &w);
	e[13] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e13.xpm", &w, &w);
	e[14] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e14.xpm", &w, &w);
	e[15] = mlx_xpm_file_to_image(game->mlx, "./assets/floor/e15.xpm", &w, &w);
}

void	put_edge(t_game *game, void **e, int x, int y)
{
	int	i;

	i = wich_edge(game, x, y);
	if (i == -1)
		return ;
	// printf("\n\ni :: %d\n\n",i);
	if (game->map[x][y] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win, e[i], y * 50
			+ game->cnsty, x * 50 + game->cnstx);
		if (game->c != 0)
			mlx_put_image_to_window(game->mlx, game->win, game->asset->door, y
				* 50 + game->cnsty, x * 50 + game->cnstx);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->asset->open_door, y * 50 + game->cnsty, x * 50
				+ game->cnstx);
	}
	else if (game->map[x][y] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, e[i], y * 50
			+ game->cnsty, x * 50 + game->cnstx);
		mlx_put_image_to_window(game->mlx, game->win, game->asset->coin, y * 50
			+ game->cnsty, x * 50 + game->cnstx);
	}
	else
		mlx_put_image_to_window(game->mlx, game->win, e[i], y * 50
			+ game->cnsty, x * 50 + game->cnstx);
}
