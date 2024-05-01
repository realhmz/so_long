/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:21 by het-taja          #+#    #+#             */
/*   Updated: 2024/05/01 17:10:10 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	put_player(t_game *game, t_assets *assets, int i)
{
	if (i == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, assets->player,
			game->playery * 50 + game->cnsty, game->playerx * 50 + game->cnstx);
	}
	else if (i == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, assets->playerl,
			game->playery * 50 + game->cnsty, game->playerx * 50 + game->cnstx);
	}
}

int	key_hook(int keycode, t_game *game)
{
	// printf("keycode : %d\n",keycode);
	if (keycode == 53)
	{
		exit(free_leaks(game));
		exit(1);
	}
	if (keycode == 2)
		turn_right(game);
	if (keycode == 1)
		go_down(game);
	if (keycode == 13)
		go_up(game);
	if (keycode == 0)
		turn_left(game);
	return (0);
}
