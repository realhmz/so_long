#include "so_long.h"

void	load_menu(t_game *game)
{
	t_assets	*asset;
	int			i;

	i = 0;
	asset = NULL;
	game->winw = 1920;
	game->winh = 1080;
	game->mlx = mlx_init();
	game->sound = malloc(sizeof(t_sound));
	game->asset = (t_assets *)malloc(sizeof(t_assets));
	sound_assets(game->sound);
	play_menu();
	asset = game->asset;
	asset->sky = malloc(sizeof(void *) * 5);
	asset->player = malloc(sizeof(void *) * 6);
	asset->playerl = malloc(sizeof(void *) * 6);
	asset->enemyl = malloc(sizeof(void *) * 4);
	asset->enemyr = malloc(sizeof(void *) * 4);
	game->win = mlx_new_window(game->mlx, game->winw, game->winh, "SO_LONG");
	game->asset->button = mlx_xpm_file_to_image(game->mlx,
			"./textures/sky/menu.xpm", &i, &i);
	game->asset->button1 = mlx_xpm_file_to_image(game->mlx,
			"./textures/sky/button1.xpm", &i, &i);
	mlx_put_image_to_window(game->mlx, game->win, game->asset->button, 0, 0);
	mlx_mouse_hook(game->win, mouse_hook, game);
}
int	close_menu(t_game *game)
{
	stop_audio();
	ft_free_map(game);
	mlx_destroy_image(game->mlx, game->asset->button1);
	mlx_destroy_image(game->mlx, game->asset->button);
	free(game->asset->sky);
	free(game->asset->player);
	free(game->asset->playerl);
	free(game->asset->enemyl);
	free(game->asset->enemyr);
	free(game->asset);
	ft_free_sound(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	game->mlx = NULL;
	free(game->mlx);
	system("leaks so_long");
	free(game);
	return (0);
}

int	mlx_close(int keycode, t_game *game)
{
	if (keycode == 53)
		exit(close_menu(game));
	return (0);
}

int	mouse_hook(int hook, int x, int y, t_game *game)
{
	mlx_key_hook(game->win, mlx_close,game);
	if (x >= 325 && x <= 584 && y >= 805 && y <= 895 && hook == 1
		&& game->game_stat == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		player_assets(game);
		idle_assets(game);
		game->game_stat = 1;
		stop_audio();
		play_sus();
		lanch_game(game);
		game->player_gender = 1;
	}
	if (x >= 1316 && x <= 1570 && y >= 805 && y <= 895 && hook == 1
		&& game->game_stat == 0)
	{
		game->player_gender = 0;
		mlx_clear_window(game->mlx, game->win);
		player_assets_women(game);
		idle_assets_women(game);
		game->game_stat = 1;
		stop_audio();
		play_sus();
		lanch_game(game);
	}
	return (1);
}