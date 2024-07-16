/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:55:55 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 22:24:55 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	idle(t_game *game)
{
	static int	i;
	static int	j;

	if (i % 1 == 0)
		j--;
	i++;
	if (j == -1)
		j = 9;
	if (!collition(game, game->playery + 3, game->playerx)
		&& game->player_stat == 3)
		put_img_to_img(game->base, game->asset->playerl[j],
			game->playerx, game->playery);
	if (game->player_stat == 0)
		put_img_to_img(game->base, game->asset->idle[j],
			game->playerx, game->playery);
	if (game->player_stat == 1)
		put_img_to_img(game->base, game->asset->player[j],
			game->playerx, game->playery);
	if (game->player_stat == 2)
		put_img_to_img(game->base, game->asset->playerl[j],
			game->playerx, game->playery);
	if (i == 10)
		i = 0;
	return (0);
}

int	playerstat(int keycode, t_game *game)
{
	if (keycode == 0 || keycode)
		game->player_stat = 0;
	return (0);
}

static void	put(t_game *game, int x, int y, int j)
{
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->coin.x != 0 && game->coin.x == x
				&& game->coin.y == y && j <= 9)
			{
				if (j == 9)
					game->coin.x = 0;
				ft_put(game, game->asset->coin[j],
					x * 50, y * 50);
			}
			if (game->map[y][x] == 'C')
				ft_put(game, game->asset->coin_idle[j],
					x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	put_coin(t_game *game)
{
	int			x;
	int			y;
	static int	i;
	static int	j;

	y = 0;
	x = 0;
	put(game, x, y, j);
	if (i % 10 == 0)
		j++;
	i++;
	if (j == 10)
		j = 1;
	y = 0;
	if (i == 100)
		i = 0;
}

int	backimg(t_game *game)
{
	static int	i;

	if (game->enemy == 1)
	{
		if (i % 30 == 0)
			patrol(game);
	}
	i++;
	if (i == 300)
		i = 0;
	render(game, game->asset);
	gravity(game);
	put_coin(game);
	idle(game);
	print_moves(game);
	usleep(2000000 / 60);
	return (-100);
}
