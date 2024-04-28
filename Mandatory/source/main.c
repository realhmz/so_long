/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:45:02 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/26 11:45:45 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	t_game		*game;
	int			w;
	t_assets	*assets;

	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_game));
	game->map = full_map(ft_readmap(av[1]));
	if (check_lenth(game->map) && check_wall(game->map, ft_readmap(av[1]))
		&& check_map_name(av[1]) && check_fill(game))
	{
		w = 50;
		game->x = ft_strlen(game->map[1]) * 50;
		game->y = count_y(game->map) * 50;
		game->a = 0;
		game->b = 0;
		game->playerx = 1;
		game->playery = 1;
		game->winw = 1920;
		game->winh = 1080;
		game->cnsty = (game->winw / 2) - (game->x / 2);
		game->cnstx = (game->winh / 2) - (game->y / 2);
		game->mlx = mlx_init();
		game->edges = malloc(sizeof(void *) * 16);
		game->win = mlx_new_window(game->mlx, game->winw, game->winh,
				"SO_LONG");
		game->asset = (t_assets *)malloc(sizeof(t_assets));
		assets = game->asset;
		game->c = count_c(game);
		game->moves = 0;
		load_map(game, assets);
		put_player(game, game->asset, 1);
		mlx_hook(game->win, 2, (1L << 0), key_hook, game);
		mlx_loop(game->mlx);
	}
	else
		printf("Map ERROR");
	exit(1);
	return (0);
}