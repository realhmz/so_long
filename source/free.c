/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:50 by het-taja          #+#    #+#             */
/*   Updated: 2024/05/20 14:23:10 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	free_leaks(t_game *game)
{
	if (game->map[game->playerx][game->playery + 1] == 'E' && game->c == 0)
		printf("Winner Winner Chicken Dinner !!\n");
	stop_audio();
	play_end();
	ft_free_map(game);
	ft_free_assets(game);
	stop_audio();
	ft_free_sound(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	// mlx_destroy_display(game->mlx);
	game->mlx = NULL;
	free(game->mlx);
	free(game);
	system("leaks so_long");
	return (0);
}

void	ft_free_enemy(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->asset->enemyl[i]);
		mlx_destroy_image(game->mlx, game->asset->enemyr[i]);
		i++;
	}
	free(game->asset->enemyl);
	free(game->asset->enemyr);
}

void	ft_free_edges(t_game *game)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		mlx_destroy_image(game->mlx, game->edges[i]);
		i++;
	}
	free(game->edges);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	ft_free_assets(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(game->mlx, game->asset->player[i]);
		mlx_destroy_image(game->mlx, game->asset->playerl[i]);
		mlx_destroy_image(game->mlx, game->asset->idle[i]);
		i++;
	}
	i = 0;
	while (i < 16)
	{
		mlx_destroy_image(game->mlx, game->edges[i]);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(game->mlx, game->asset->sky[i]);
		i++;
	}
	free(game->edges);
	free(game->asset->sky);
	mlx_destroy_image(game->mlx, game->asset->button1);
	mlx_destroy_image(game->mlx, game->asset->button);
	mlx_destroy_image(game->mlx, game->asset->coin);
	mlx_destroy_image(game->mlx, game->asset->door);
	mlx_destroy_image(game->mlx, game->asset->open_door);
	mlx_destroy_image(game->mlx, game->asset->bar);
	free(game->asset->player);
	free(game->asset->playerl);
	free(game->asset->enemyl);
	free(game->asset->enemyr);
	free(game->asset->idle);
	free(game->asset);
	// game->asset->bar
	
}

void	ft_free_sound(t_game *game)
{
	free(game->sound->kill);
	free(game->sound->enemy);
	free(game->sound);
}
