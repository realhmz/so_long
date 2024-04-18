/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:50 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/18 21:19:49 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_leaks(t_game *game)
{
	ft_free_map(game);
	ft_free_assets(game);
	ft_free_sound(game);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free(game);
	// system("leaks so_long");
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
void	ft_free_player(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(game->mlx, game->asset->player[i]);
		mlx_destroy_image(game->mlx, game->asset->playerl[i]);
		i++;
	}
	free(game->asset->player);
	free(game->asset->playerl);
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
		i++;
	}
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->asset->enemyl[i]);
		mlx_destroy_image(game->mlx, game->asset->enemyr[i]);
		i++;
	}
	i = 0;
	while (i < 16)
	{
		mlx_destroy_image(game->mlx, game->edges[i]);
		i++;
	}
	free(game->edges);
	free(game->asset->coin);
	free(game->asset->door);
	free(game->asset->open_door);
	free(game->asset->player);
	free(game->asset->playerl);
	free(game->asset->enemyl);
	free(game->asset->enemyr);
	free(game->asset);
}
void	ft_free_sound(t_game *game)
{
	free(game->sound->start);
	free(game->sound->kill);
	free(game->sound->enemy);
	free(game->sound->end);
	free(game->sound);
}

//