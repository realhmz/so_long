/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:43 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/18 14:52:44 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	enemy_go_down(t_vars *v)
{
	if (v->map[v->enemyx + 1][v->enemyy] == '0' || v->map[v->enemyx
		+ 1][v->enemyy] == 'C')
	{
		v->map[v->enemyx][v->enemyy] = '0';
		v->enemyx++;
		render_sky(v, v->asset);
		load_map(v, v->asset);
		put_player(v, v->asset, -1);
		put_enemy(v, v->asset, 1);
		print_moves(v);
	}
	// play_walk();
}
void	enemy_go_up(t_vars *v)
{
	if (v->map[v->enemyx - 1][v->enemyy] == '0' || v->map[v->enemyx
		- 1][v->enemyy] == 'C')
	{
		v->map[v->enemyx][v->enemyy] = '0';
		v->enemyx--;
		render_sky(v, v->asset);
		load_map(v, v->asset);
		put_player(v, v->asset, -1);
		put_enemy(v, v->asset, 0);
		print_moves(v);
	}
	// play_walk();
}

void	enemy_go_left(t_vars *v)
{
	if (v->map[v->enemyx][v->enemyy - 1] == '0' || v->map[v->enemyx][v->enemyy
		- 1] == 'C')
	{
		v->map[v->enemyx][v->enemyy] = '0';
		v->enemyy--;
		render_sky(v, v->asset);
		load_map(v, v->asset);
		put_player(v, v->asset, -1);
		put_enemy(v, v->asset, 0);
		print_moves(v);
	}
	// play_walk(v->sound);
}
void	enemy_go_right(t_vars *v)
{
	if (v->map[v->enemyx][v->enemyy + 1] == '0' || v->map[v->enemyx][v->enemyy
		+ 1] == 'P')
	{
		v->map[v->enemyx][v->enemyy] = '0';
		v->enemyy++;
		render_sky(v, v->asset);
		load_map(v, v->asset);
		put_player(v, v->asset, -1);
		put_enemy(v, v->asset, 1);
		print_moves(v);
	}
	// play_walk(v->sound);
}
void	put_enemy(t_vars *v, t_assets *a, int i)
{
	static int	j = 0;
	static int	x = 0;

	if (i == 1)
	{
		mlx_put_image_to_window(v->mlx, v->win, a->enemyr[v->enemy_moved],
			v->enemyy * 50 + v->cnsty, v->enemyx * 50 + v->cnstx);
		j = 1;
		x = 0;
	}
	if (i == 0)
	{
		mlx_put_image_to_window(v->mlx, v->win, a->enemyl[v->enemy_moved_left],
			v->enemyy * 50 + v->cnsty, v->enemyx * 50 + v->cnstx);
		x = 1;
		j = 0;
	}
	if (i == -1 && j == 1)
	{
		if (v->enemy_moved == 0)
			mlx_put_image_to_window(v->mlx, v->win, a->enemyr[0], v->enemyy * 50
				+ v->cnsty, v->enemyx * 50 + v->cnstx);
		else
			mlx_put_image_to_window(v->mlx, v->win, a->enemyr[v->enemy_moved
				- 1], v->enemyy * 50 + v->cnsty, v->enemyx * 50 + v->cnstx);
	}
	if (i == -1 && x == 1)
	{
		if (v->enemy_moved_left == 0)
			mlx_put_image_to_window(v->mlx, v->win, a->enemyl[0], v->enemyy * 50
				+ v->cnsty, v->enemyx * 50 + v->cnstx);
		else
			mlx_put_image_to_window(v->mlx, v->win,
				a->enemyl[v->enemy_moved_left - 1], v->enemyy * 50 + v->cnsty,
				v->enemyx * 50 + v->cnstx);
	}
	if (v->enemy_moved == 4)
		v->enemy_moved = 0;
	if (v->enemy_moved_left == 4)
		v->enemy_moved_left = 0;
}

void	enemy_attack(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win, "./textures/enemy/attack.xpm",
		v->enemyy * 50 + v->cnsty, v->enemyy * 50 + v->cnstx);
	if (v->playerx == v->enemyx && v->playery == v->enemyy)
	{
		// stop_audio();
		// play_enemy(v->sound);
		mlx_clear_window(v->mlx, v->win);
		exit(free_leaks(v));
		mlx_destroy_window(v->mlx, v->win);
	}
}