/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:29:33 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 21:22:46 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit(win(game));
	if (keycode == 119)
		up(game);
	if (keycode == 115)
		down(game);
	if (keycode == 100)
		right(game);
	if (keycode == 97)
		left(game);
	if (!collition(game, game->playery, game->playerx)
		&& keycode == 32)
		jump(game);
	return (0);
}

void	right(t_game *game)
{
	game->player_stat = 1;
	game->playerx += 5;
	game->moves++;
	if (collition(game, game->playery, game->playerx))
	{
		game->moves--;
		game->playerx -= 6;
	}
}

void	up(t_game *game)
{
	game->playery -= 5;
	game->moves++;
	if (collition(game, game->playery, game->playerx))
	{
		game->playery += 6;
		game->moves--;
	}
}

void	down(t_game *game)
{
	game->playery += 5;
	game->moves++;
	if (collition(game, game->playery, game->playerx))
	{
		game->moves--;
		game->playery -= 6;
	}
}

void	left(t_game *game)
{
	game->player_stat = 2;
	game->playerx -= 5;
	game->moves++;
	if (collition(game, game->playery, game->playerx))
	{
		game->moves--;
		game->playerx += 6;
	}
}
