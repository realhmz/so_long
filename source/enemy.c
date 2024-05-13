/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:43 by het-taja          #+#    #+#             */
/*   Updated: 2024/05/02 17:32:03 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	enemy_go_down(t_game *game)
// {
// 	if (game->map[game->enemyx + 1][game->enemyy] == '0'
// 		|| game->map[game->enemyx + 1][game->enemyy] == 'C')
// 	{
// 		game->map[game->enemyx][game->enemyy] = '0';
// 		game->enemyx++;
// 		render_sky(game, game->asset);
// 		load_map(game);
// 		put_player(game, game->asset, -1);
// 		put_enemy(game, game->asset, 1);
// 		print_moves(game);
// 	}
// }

// void	enemy_go_up(t_game *game)
// {
// 	if (game->map[game->enemyx - 1][game->enemyy] == '0'
// 		|| game->map[game->enemyx - 1][game->enemyy] == 'C')
// 	{
// 		game->map[game->enemyx][game->enemyy] = '0';
// 		game->enemyx--;
// 		render_sky(game, game->asset);
// 		load_map(game);
// 		put_player(game, game->asset, -1);
// 		put_enemy(game, game->asset, 0);
// 		print_moves(game);
// 	}
// }

// void	enemy_go_left(t_game *game)
// {
// 	if (game->map[game->enemyx][game->enemyy - 1] == '0'
// 		|| game->map[game->enemyx][game->enemyy - 1] == 'C')
// 	{
// 		game->map[game->enemyx][game->enemyy] = '0';
// 		game->enemyy--;
// 		render_sky(game, game->asset);
// 		load_map(game);
// 		put_player(game, game->asset, -1);
// 		put_enemy(game, game->asset, 0);
// 		print_moves(game);
// 	}
// }

// void	enemy_go_right(t_game *game)
// {
// 	if (game->map[game->enemyx][game->enemyy + 1] == '0'
// 		|| game->map[game->enemyx][game->enemyy + 1] == 'P')
// 	{
// 		game->map[game->enemyx][game->enemyy] = '0';
// 		game->enemyy++;
// 		render_sky(game, game->asset);
// 		load_map(game);
// 		put_player(game, game->asset, -1);
// 		put_enemy(game, game->asset, 1);
// 		print_moves(game);
// 	}
// }

// void	player_moved(t_game *game, int i, int j, int x)
// {
// 	if (i == -1 && j == 1)
// 	{
// 		if (game->enemy_moved == 0)
// 			mlx_put_image_to_window(game->mlx, game->win,
// 				game->asset->enemyr[0], game->enemyy * 50 + game->cnsty,
// 				game->enemyx * 50 + game->cnstx);
// 		else
// 			mlx_put_image_to_window(game->mlx, game->win,
// 				game->asset->enemyr[game->enemy_moved - 1], game->enemyy * 50
// 				+ game->cnsty, game->enemyx * 50 + game->cnstx);
// 	}
// 	if (i == -1 && x == 1)
// 	{
// 		if (game->enemy_moved_left == 0)
// 			mlx_put_image_to_window(game->mlx, game->win,
// 				game->asset->enemyl[0], game->enemyy * 50 + game->cnsty,
// 				game->enemyx * 50 + game->cnstx);
// 		else
// 			mlx_put_image_to_window(game->mlx, game->win,
// 				game->asset->enemyl[game->enemy_moved_left - 1], game->enemyy
// 				* 50 + game->cnsty, game->enemyx * 50 + game->cnstx);
// 	}
// }

// void	put_enemy(t_game *game, t_assets *a, int i)
// {
// 	static int	j = 0;
// 	static int	x = 0;

// 	if (i == 1)
// 	{
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			a->enemyr[game->enemy_moved], game->enemyy * 50 + game->cnsty,
// 			game->enemyx * 50 + game->cnstx);
// 		j = 1;
// 		x = 0;
// 	}
// 	if (i == 0)
// 	{
// 		mlx_put_image_to_window(game->mlx, game->win,
// 			a->enemyl[game->enemy_moved_left], game->enemyy * 50 + game->cnsty,
// 			game->enemyx * 50 + game->cnstx);
// 		x = 1;
// 		j = 0;
// 	}
// 	player_moved(game, i, j, x);
// 	if (game->enemy_moved == 4)
// 		game->enemy_moved = 0;
// 	if (game->enemy_moved_left == 4)
// 		game->enemy_moved_left = 0;
// }

// void	enemy_attack(t_game *game)
// {
// 	mlx_put_image_to_window(game->mlx, game->win, "./textures/enemy/attack.xpm",
// 		game->enemyy * 50 + game->cnsty, game->enemyy * 50 + game->cnstx);
// 	if (game->playerx == game->enemyx && game->playery == game->enemyy)
// 	{
// 		// stop_audio();
// 		// play_enemy(game->sound);
// 		mlx_clear_window(game->mlx, game->win);
// 		exit(free_leaks(game));
// 		mlx_destroy_window(game->mlx, game->win);
// 	}
// }