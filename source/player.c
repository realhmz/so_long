/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:21 by het-taja          #+#    #+#             */
/*   Updated: 2024/05/17 23:24:06 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	put_player(t_game *game, t_assets *assets, int i)
// {
// 	static int	j = 0;

// 	if (i % 20 == 0)
// 		j++;
// 	i++;
// 	if (j == 5)
// 		j = 0;
// 	mlx_put_image_to_window(game->mlx,game->win,game->asset->player[i],0,0);
// 	idle(game);
// 	print_moves(game);
// 	if (i == 150)
// 		i = 0;
// 	// return (0);
// }

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		stop_audio();
		play_end();
		exit(free_leaks(game));
	}
	else if (keycode == 2 || keycode == 1)
	{
		if (keycode == 2)
			turn_right(game);
		if (keycode == 1)
			go_up(game);
		game->player_stat = 1;
	}
	else if (keycode == 0 || keycode == 13)
	{
		if (keycode == 13)
			go_down(game);
		if (keycode == 0)
			turn_left(game);
		game->player_stat = 2;
	}
	else
		game->player_stat = 0;
	usleep(10);
	return (0);
}
