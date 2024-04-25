#include "get_next_line.h"


void    load_menu(t_game *game)
{
    t_assets	*asset;
    int         i;

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
    game->asset->button = mlx_xpm_file_to_image(game->mlx, "./textures/sky/button.xpm",
			&i, &i);
    game->asset->button1 = mlx_xpm_file_to_image(game->mlx, "./textures/sky/button1.xpm",
			&i, &i);
    mlx_put_image_to_window(game->mlx,game->win,game->asset->button,0,0);
    mlx_mouse_hook(game->win,mouse_hook,game);
}

int mouse_hook(int hook, int x,int y,t_game *game)
{
        printf("%d ,"" %d\n\n",x,y);
    if (x >= 800 && x <= 1150  && y >= 750 && y <= 950 && hook == 1)
    {
        mlx_clear_window(game->mlx,game->win);
        game->game_stat = 1;
        stop_audio();
        play_sus();
        lanch_game(game);
    }
    return 1;
}