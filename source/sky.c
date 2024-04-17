#include "get_next_line.h"
#include <time.h>
void sky(t_vars *v, t_assets *a)
{
    int i = 0;
    int j = 0;
    a = v->asset;
    a->sky[0] = mlx_xpm_file_to_image(v->mlx, "./textures/sky/sky_full.xpm", &i, &j);
    a->sky[1] = mlx_xpm_file_to_image(v->mlx, "./textures/sky/sky_full.xpm", &i, &j);
    a->sky[2] = mlx_xpm_file_to_image(v->mlx, "./textures/sky/kolchi.xpm", &i, &j);
}

void render_sky(t_vars *v, t_assets *a)
{
    int i = 0;
    sky(v, a);
    srand(time(NULL));
    i = rand();
    i = i % 2;
//    mlx_put_image_to_window(v->mlx, v->win, "./textures/sky/among.xpm", 0, 0);
	mlx_put_image_to_window(v->mlx, v->win, a->sky[i], 0, 0);
   mlx_put_image_to_window(v->mlx, v->win, a->sky[2], 0, 0);
//    mlx_put_image_to_window(v->mlx, v->win,"./textures/sky/brahim.xpm", 0, 0);
}
