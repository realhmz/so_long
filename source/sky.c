/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:53:26 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/27 20:49:34 by het-taja         ###   ########.fr       */
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
	a->sky[0] = mlx_xpm_file_to_image(game->mlx, "./textures/space/1.xpm",
			&i, &j);
	a->sky[1] = mlx_xpm_file_to_image(game->mlx, "./textures/space/2.xpm",
			&i, &j);
	a->sky[2] = mlx_xpm_file_to_image(game->mlx, "./textures/space/3.xpm",
			&i, &j);
	a->sky[3] = mlx_xpm_file_to_image(game->mlx, "./textures/space/4.xpm",
			&i, &j);
	a->sky[4] = mlx_xpm_file_to_image(game->mlx, "./textures/space/5.xpm",
			&i, &j);
	
}
int	backimg(t_game *game)
{
	static int i = 0;
	static int j = 0;
	if (i % 20 == 0)
		j++;
	i++;
	if (j == 5)
		j = 0;
	mlx_put_image_to_window(game->mlx,game->win,game->asset->sky[j],0,0);
	load_map(game);
	idle(game);
	print_moves(game);
	if (i == 150)
		i = 0;
	return 0;
}
void	render_sky(t_game *game, t_assets *a)
{
	int	i;

	i = 0;
	srand(time(NULL));
	i = rand();
	i = i % 2;
	mlx_loop_hook(game->mlx,backimg,game);
}
