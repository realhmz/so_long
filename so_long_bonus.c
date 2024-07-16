/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:30:04 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 22:23:27 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	game = malloc(sizeof(t_game));
	if (ac != 2)
		exit(error(game));
	game->moves = 0;
	if (parcing(game, av[1]) == -1 || flood_fill(game) == -1)
		exit(error(game));
	calc_win(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_w, game->win_h, "SO_LONG");
	player_pos_real(game);
	game->gravity = 1.5;
	start_game(game);
	mlx_hook(game->win, 17, 0, win, game);
	mlx_hook(game->win, 2, 1, move, game);
	game->player_stat = 0;
	mlx_hook(game->win, 3, (1L << 1), playerstat, game);
	mlx_loop_hook(game->mlx, backimg, game);
	mlx_loop(game->mlx);
	return (0);
}

void	clear_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	error(t_game *game)
{
	free(game);
	write(1, "Error\n", 6);
	exit(0);
}

void	calc_win(t_game *game)
{
	int	i;

	i = 0;
	game->win_w = ft_strlen(game->map[0]) * 50;
	game->win_h = 0;
	while (game->map && game->map[i])
		i++;
	game->win_h = i * 50;
}

int	gravity(t_game *game)
{
	if (!collition(game, game->playery + 4, game->playerx))
	{
		idle(game);
		game->player_stat = 0;
		game->playery += game->gravity;
	}
	return (0);
}
