/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:23 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/18 21:19:11 by het-taja         ###   ########.fr       */
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
	// play_open_door(game->sound);
}
void	enemy_assets(t_game *game, t_assets *a)
{
	int	w;

	w = 50;
	a->enemyl[0] = mlx_xpm_file_to_image(game->mlx, "./textures/enemy/l/1.xpm", &w,
			&w);
	a->enemyl[1] = mlx_xpm_file_to_image(game->mlx, "./textures/enemy/l/2.xpm", &w,
			&w);
	a->enemyl[2] = mlx_xpm_file_to_image(game->mlx, "./textures/enemy/l/3.xpm", &w,
			&w);
	a->enemyl[3] = mlx_xpm_file_to_image(game->mlx, "./textures/enemy/l/4.xpm", &w,
			&w);
	a->enemyr[0] = mlx_xpm_file_to_image(game->mlx, "./textures/enemy/r/1.xpm", &w,
			&w);
	a->enemyr[1] = mlx_xpm_file_to_image(game->mlx, "./textures/enemy/r/2.xpm", &w,
			&w);
	a->enemyr[2] = mlx_xpm_file_to_image(game->mlx, "./textures/enemy/r/3.xpm", &w,
			&w);
	a->enemyr[3] = mlx_xpm_file_to_image(game->mlx, "./textures/enemy/r/4.xpm", &w,
			&w);
	a->coin = mlx_xpm_file_to_image(game->mlx, "./textures/player/1.xpm",
			&w, &w);
	a->door = mlx_xpm_file_to_image(game->mlx,
			"./textures/door/closed_door.xpm", &w, &w);
	a->open_door = mlx_xpm_file_to_image(game->mlx,
			"./textures/door/opendoor.xpm", &w, &w);
}
void	load_map(t_game *game)
{
	int	w;

	w = 50;
	game->x = 0;
	game->y = 0;
	// print_map(game->map);

	
	while (game->map && game->map[game->x] && game->map[game->x][game->y])
	{
		while (game->map[game->x][game->y])
		{
			if (game->map[game->x][game->y] == 'N')
			{
				game->enemyx = game->x;
				game->enemyy = game->y;
			}
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
