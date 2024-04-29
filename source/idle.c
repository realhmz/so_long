#include "get_next_line.h"

void	idle_assets(t_game *game)
{
	int	i;

	i = 0;
	game->asset->idle = malloc(sizeof(void *) * 6);
	game->asset->idle[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/i1.xpm", &i, &i);
	game->asset->idle[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/i2.xpm", &i, &i);
	game->asset->idle[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/i3.xpm", &i, &i);
	game->asset->idle[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/i4.xpm", &i, &i);
	game->asset->idle[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/i5.xpm", &i, &i);
	game->asset->idle[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/i6.xpm", &i, &i);
}

void	idle_assets_women(t_game *game)
{
	int	i;

	i = 0;
	game->asset->idle = malloc(sizeof(void *) * 6);
	game->asset->idle[0] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/women/iw1.xpm", &i, &i);
	game->asset->idle[1] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/women/iw2.xpm", &i, &i);
	game->asset->idle[2] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/women/iw3.xpm", &i, &i);
	game->asset->idle[3] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/women/iw4.xpm", &i, &i);
	game->asset->idle[4] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/women/iw5.xpm", &i, &i);
	game->asset->idle[5] = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/idle/women/iw6.xpm", &i, &i);
}

int	playerstat(int keycode, t_game *game)
{
    if (keycode == 0 || keycode)
    {
    	game->player_stat = 0;    
    }
    
	return (0);
}
int	idle(t_game *game)
{
	static int i = 0;
	static int j = 0;
	if (i % 20 == 0)
		j++;
	i++;
	if (j == 6)
		j = 0;
	load_map(game);
	render_bar(game);
	if (game->player_stat == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->asset->idle[j],
			game->playery * 50 + game->cnsty, game->playerx * 50 + game->cnstx);
	if (game->player_stat == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->asset->player[j],
			game->playery * 50 + game->cnsty, game->playerx * 50 + game->cnstx);
	if (game->player_stat == 2)
		mlx_put_image_to_window(game->mlx, game->win, game->asset->playerl[j],
			game->playery * 50 + game->cnsty, game->playerx * 50 + game->cnstx);
	if (i == 10)
		i = 0;
	return (0);
}