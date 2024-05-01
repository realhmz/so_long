/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:50 by het-taja          #+#    #+#             */
/*   Updated: 2024/05/01 17:28:21 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	free_leaks(t_game *game)
{
	if (game->map[game->playerx][game->playery + 1] == 'E' && game->c == 0)
        printf("Winner Winner Chicken Dinner !!\n");
    
    ft_free_map(game);
    ft_free_assets(game);
    free(game->asset);
    mlx_clear_window(game->mlx, game->win);
    mlx_destroy_window(game->mlx, game->win);
    // mlx_destroy_display(game->mlx);
    free(game->mlx);
    free(game);
    system("leaks so_long");
    return (0);
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
	t_assets *a;

	a = game->asset;
	mlx_destroy_image(game->mlx, a->coin);
	mlx_destroy_image(game->mlx, a->door);
	mlx_destroy_image(game->mlx, a->floor);
	mlx_destroy_image(game->mlx, a->open_door);
	mlx_destroy_image(game->mlx, a->player);
	mlx_destroy_image(game->mlx, a->playerl);
	mlx_destroy_image(game->mlx, a->wall);
}