/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:21 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/26 11:44:58 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	turn_right(t_game *game)
{
	if (game->map[game->playerx][game->playery + 1] == 'E' && game->c == 0)
	{
		printf("Congrats you win!!\n");
		exit(free_leaks(game));
	}
	if (game->map[game->playerx][game->playery + 1] == 'C')
	{
		if (game->c == 1)
			opendoor(game);
		game->c -= 1;
	}
	if (game->map[game->playerx][game->playery + 1] == '0'
		|| game->map[game->playerx][game->playery + 1] == 'C')
	{
		game->map[game->playerx][game->playery + 1] = 'P';
		game->map[game->playerx][game->playery] = '0';
		render_sky(game, game->asset);
		game->playery += 1;
		load_map(game, game->asset);
		put_player(game, game->asset, 1);
		game->moves++;
	}
}

void	turn_left(t_game *game)
{
	if (game->map[game->playerx][game->playery - 1] == 'E' && game->c == 0)
	{
		printf("You win Congrats!!\n\n");
		exit(free_leaks(game));
	}
	if (game->map[game->playerx][game->playery - 1] == 'C')
	{
		if (game->c == 1)
			opendoor(game);
		game->c -= 1;
	}
	if (game->map[game->playerx][game->playery - 1] == '0'
		|| game->map[game->playerx][game->playery - 1] == 'C')
	{
		game->map[game->playerx][game->playery - 1] = 'P';
		game->map[game->playerx][game->playery] = '0';
		game->playery -= 1;
		game->moves++;
		render_sky(game, game->asset);
		load_map(game, game->asset);
		put_player(game, game->asset, 0);
		print_moves(game);
	}
}
void	go_up(t_game *game)
{
	if (game->map[game->playerx + 1][game->playery] == 'E' && game->c == 0)
	{
		exit(free_leaks(game));
	}
	if (game->map[game->playerx + 1][game->playery] == 'C')
	{
		if (game->c == 1)
			opendoor(game);
		game->c -= 1;
	}
	if (game->map[game->playerx + 1][game->playery] == '0' || game->map[game->playerx
		+ 1][game->playery] == 'C')
	{
		game->map[game->playerx + 1][game->playery] = 'P';
		game->map[game->playerx][game->playery] = '0';
		render_sky(game, game->asset);
		game->playerx += 1;
		load_map(game, game->asset);
		put_player(game, game->asset, 1);
		print_moves(game);
		game->moves++;
	}
}

void	go_down(t_game *game)
{
	if (game->map[game->playerx - 1][game->playery] == 'E' && game->c == 0)
	{
		exit(free_leaks(game));
	}
	if (game->map[game->playerx - 1][game->playery] == 'C')
	{
		if (game->c == 1)
			opendoor(game);
		game->c -= 1;
	}
	if (game->map[game->playerx - 1][game->playery] == '0' || game->map[game->playerx
		- 1][game->playery] == 'C')
	{
		render_sky(game, game->asset);
		game->map[game->playerx - 1][game->playery] = 'P';
		game->map[game->playerx][game->playery] = '0';
		game->playerx -= 1;
		load_map(game, game->asset);
		put_player(game, game->asset, 1);
		print_moves(game);
		game->moves++;
	}
}

void	put_player(t_game *game, t_assets *assets, int i)
{
	static int	j = 0;
	static int	x = 0;

	player_assets(game);
	if (game->player_moved_left >= 6)
		game->player_moved_left = 0;
	if (game->player_moved >= 6)
		game->player_moved = 0;
	if (i == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			assets->player[game->player_moved], game->playery * 50
			+ game->cnsty, game->playerx * 50 + game->cnstx);
		j = 1;
		x = 0;
	}
	else if (i == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			assets->playerl[game->player_moved_left], game->playery * 50
			+ game->cnsty, game->playerx * 50 + game->cnstx);
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
	}
}

int	key_hook(int keycode, t_game *game)
{
	// printf("keycode : %d\n",keycode);
	// printf("\n\ncoins left == %d \n\n",game->c);
	if (keycode == 53)
	{
		stop_audio();
		play_end(game->sound);
		exit(free_leaks(game));
	}
	if (keycode == 2 || keycode == 1 || keycode == 13)
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
	if (keycode == 126 || keycode == 125 || keycode == 124)
	{
		if (keycode == 126)
			enemy_go_up(game);
		if (keycode == 125)
			enemy_go_down(game);
		if (keycode == 124)
			enemy_go_right(game);
		game->enemy_moved++;
	}
	if (keycode == 123)
	{
		enemy_go_left(game);
		game->enemy_moved_left++;
	}
	if (keycode == 49)
		enemy_attack(game);
	return (0);
}


// ADD ESC to exit game; DONE
// fix leaks;
// flod fill;
// add new assets;
// sky effect dark to light;
// render player foq l map khawya -> hitach l edges kaybqaw khasrin;
// add sound effects;
// add animation to player; (optional)
// max map size 40 x 22;
// make a struct to fill with allocated variables and free all the struct at the end