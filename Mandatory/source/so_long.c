/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:22:30 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/26 13:50:09 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	game_init(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->a = 0;
	game->b = 0;
	game->playerx = 0;
	game->playery = 0;
	game->winw = 0;
	game->winh = 0;
	game->cnsty = 0;
	game->cnstx = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->asset = NULL;
	game->c = 0;
	game->moves = 0;
	game->map = NULL;
	game->mlx = mlx_init();

}
void	start_game(t_game *game)
{
    t_assets	*asset;
    int         i;

    i = 0;
	asset = NULL;
    game->winw = 1920;
	game->winh = 1080;
	game->cnsty = (game->winw / 2) - (game->x / 2);
	game->cnstx = (game->winh / 2) - (game->y / 2);
    game->mlx = mlx_init();
    game->asset = (t_assets *)malloc(sizeof(t_assets));
    asset = game->asset;
    game->win = mlx_new_window(game->mlx, game->winw, game->winh, "SO_LONG");
}
void	load_assets(t_game *game)
{
	player_assets(game);
	map_assets(game);
	load_map(game);
	put_player(game, game->asset, 1);
}

void	lanch_game(t_game *game)
{
	game->x = ft_strlen(game->map[1]) * 50;
	game->y = count_y(game->map) * 50;
	game->c = count_c(game);
	start_game(game);
	load_assets(game);
	mlx_hook(game->win, 2, (1L << 0), key_hook, game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_game));
	game_init(game);
	game->map = full_map(ft_readmap(av[1]));
	if (check_lenth(game->map) && check_wall(game->map, ft_readmap(av[1]))
		&& check_map_name(av[1]) && check_fill(game))
	{
		lanch_game(game);
		mlx_loop(game->mlx);
	}
	else
		printf("Map ERROR");
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