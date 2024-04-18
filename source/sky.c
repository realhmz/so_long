/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:26 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/18 22:03:03 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>

void	sky(t_game *game, t_assets *a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	a = game->asset;
	a->sky[0] = mlx_xpm_file_to_image(game->mlx, "./textures/sky/sky_full.xpm",
			&i, &j);
	a->sky[1] = mlx_xpm_file_to_image(game->mlx, "./textures/sky/sky_full.xpm",
			&i, &j);
	a->sky[2] = mlx_xpm_file_to_image(game->mlx, "./textures/sky/kolchi.xpm",
			&i, &j);
}

void	render_sky(t_game *game, t_assets *a)
{
	int	i;

	i = 0;
	srand(time(NULL));
	i = rand();
	i = i % 2;
	mlx_put_image_to_window(game->mlx, game->win, a->sky[i], 0, 0);
	// mlx_put_image_to_window(game->mlx, game->win, a->sky[2], 0, 0);
}
