/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:07:32 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 22:24:08 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	print_moves(t_game *game)
{
	char	*tmp;

	tmp = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 80, 15, 0xA7EA2D, tmp);
	mlx_string_put(game->mlx, game->win, 15, 15, 0xA7EA2D, "Moves : ");
	free(tmp);
}

static void	destroy(t_game *game)
{
	mlx_destroy_image(game->mlx, game->base.img_ptr);
	mlx_destroy_image(game->mlx, game->asset->floor.img_ptr);
	mlx_destroy_image(game->mlx, game->asset->door.img_ptr);
	mlx_destroy_image(game->mlx, game->asset->enemy.img_ptr);
	free(game->asset->player);
	free(game->asset->playerl);
	free(game->asset->coin);
	free(game->asset->coin_idle);
	free(game->asset->e);
	free(game->asset->idle);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->asset);
	game->asset = NULL;
}

int	win(t_game *game)
{
	int	i;

	i = 0;
	clear_map(game->map);
	clear_map(game->enemy_map);
	game->map = NULL;
	while (i <= 10)
	{
		mlx_destroy_image(game->mlx, game->asset->player[i].img_ptr);
		mlx_destroy_image(game->mlx, game->asset->playerl[i].img_ptr);
		mlx_destroy_image(game->mlx, game->asset->idle[i].img_ptr);
		mlx_destroy_image(game->mlx, game->asset->coin_idle[i].img_ptr);
		mlx_destroy_image(game->mlx, game->asset->coin[i].img_ptr);
		i++;
	}
	i = -1;
	while (++i <= 15)
		mlx_destroy_image(game->mlx, game->asset->e[i].img_ptr);
	destroy(game);
	free(game->mlx);
	free(game);
	game = NULL;
	exit(0);
}
