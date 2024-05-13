#include "so_long.h"

void	bar_asset(t_game *game)
{
	int	i;

	i = 0;
	game->asset->bar = mlx_xpm_file_to_image(game->mlx,
			"./textures/bar/bar.xpm", &i, &i);
}
void	render_bar(t_game *game)
{
	int x = 612;
	int y = 0;
	int to_draw;

	to_draw = game->coin_taken * 528 / game->total_coin + 600;
	mlx_put_image_to_window(game->mlx, game->win, game->asset->bar, 600, 250);
	while (x >= 600 && x <= to_draw)
	{
		y = 284;
		while (y >= 250 && y <= 316)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, 0x00FD0A);
			y++;
		}
		x++;
	}
}