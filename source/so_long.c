/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 21:22:30 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/29 22:09:58 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	game_init(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->a = 0;
	game->player_stat = 0;
	game->b = 0;
	game->playerx = 0;
	game->playery = 0;
	game->enemyx = 0;
	game->enemyy = 0;
	game->player_moved = 0;
	game->player_moved_left = 0;
	game->enemy_moved = 0;
	game->enemy_moved_left = 0;
	game->winw = 0;
	game->winh = 0;
	game->cnsty = 0;
	game->cnstx = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->asset = NULL;
	game->sound = NULL;
	game->c = 0;
	game->moves = 0;
	game->map = NULL;
	game->edges = NULL;
	game->game_stat = 0;
	game->coin_taken = 0;
}

void	load_assets(t_game *game, t_assets *assets)
{
	game->last_view = 1;
	// play_song();
	edge_assets(game, game->edges);
	sky(game, game->asset);
	render_sky(game);
	// enemy_assets(game, assets);
	load_map(game);
	bar_asset(game);
	render_bar(game);
	// put_enemy(game, assets, 1);
	// put_player(game, game->asset, game->last_view);
}

void	lanch_game(t_game *game)
{
	game->x = ft_strlen(game->map[1]) * 50;
	game->y = count_y(game->map) * 50;
	game->cnsty = (game->winw / 2) - (game->x / 2);
	game->cnstx = (game->winh / 2) - (game->y / 2);
	game->edges = malloc(sizeof(void *) * 16);
	game->c = count_c(game);
	game->total_coin = count_c(game);
	load_assets(game, game->asset);
	if (game->game_stat == 1)
	{
		mlx_hook(game->win, 2, (1L << 0), key_hook, game);
		mlx_hook(game->win, 3, (1L << 1), playerstat, game);
		// mlx_key_hook(game->mlx,playerstat,game);
		// mlx_hook(game->win, 2, (1L << 1), playerstat, game);
	}
	else if (game->game_stat == 0)
		mlx_mouse_hook(game->win, mouse_hook, game);
}

int	main(int ac, char **av)
{
	t_game	*game;
	char	*tmp;

	tmp = ft_readmap(av[1]);
	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_game));
	game_init(game);
	load_menu(game);
	if (game->game_stat == 0)
		mlx_mouse_hook(game->win, mouse_hook, game);
	game->map = full_map(tmp);
	if (check_lenth(game->map) && check_wall(game->map, tmp)
		&& check_map_name(av[1]) && check_fill(game))
	{
		if (game->game_stat == 1)
			lanch_game(game);
		mlx_loop(game->mlx);
	}
	else
		printf("Map ERROR");
	free(tmp);
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