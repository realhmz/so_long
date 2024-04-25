/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:21 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/25 16:59:04 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	put_player(t_game *game, t_assets *assets, int i)
{
	static int	j = 0;
	static int	x = 0;

	if (game->player_moved_left >= 6)
		game->player_moved_left = 0;
	if (game->player_moved >= 6)
		game->player_moved = 0;
	if (i == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			assets->player[game->player_moved], game->playery * 50
			+ game->cnsty, game->playerx * 50 + game->cnstx);
		game->last_view = 1;
		j = 1;
		x = 0;
	}
	else if (i == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			assets->playerl[game->player_moved_left], game->playery * 50
			+ game->cnsty, game->playerx * 50 + game->cnstx);
		game->last_view = 0;
		x = 1;
		j = 0;
	}
	if (i == -1 && j == 1)
	{
		if (game->player_moved == 0)
			mlx_put_image_to_window(game->mlx, game->win, assets->player[0],
				game->playery * 50 + game->cnsty, game->playerx * 50
				+ game->cnstx);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				assets->player[game->player_moved - 1], game->playery * 50
				+ game->cnsty, game->playerx * 50 + game->cnstx);
		game->last_view = -1;
	}
	if (i == -1 && x == 1)
	{
		if (game->player_moved_left == 0)
			mlx_put_image_to_window(game->mlx, game->win, assets->playerl[0],
				game->playery * 50 + game->cnsty, game->playerx * 50
				+ game->cnstx);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				assets->playerl[game->player_moved_left - 1], game->playery * 50
				+ game->cnsty, game->playerx * 50 + game->cnstx);
		game->last_view = -1;
	}
}

int	key_hook(int keycode, t_game *game)
{
	// printf("keycode : %d\n",keycode);
	if (keycode == 53)
	{
		stop_audio();
		play_end(game->sound);
		exit(free_leaks(game));
	}
	if (keycode == 2 || keycode == 13 || keycode == 1)
	{
		if (keycode == 2)
			turn_right(game);
		if (keycode == 1)
			go_up(game);
		if (keycode == 13)
			go_down(game);
		game->player_moved++;
	}
	if (keycode == 0)
	{
		turn_left(game);
		game->player_moved_left++;
	}
	return (0);
}
