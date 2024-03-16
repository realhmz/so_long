#include <mlx.h>
#include "get_next_line.h"

// void    render(int x,int y,char *wall)
// {
  
// }

void    print_map(char  **map)
{
    int x = 0;
    int y = 0;
    while (map && map[x])
    {
        while (map[x][y])
        {
            printf("%c",map[x][y]);
            y++;
        }
        printf("\n");
        x++;
        y = 0;
    }
}
int count_y(char **s)
{
    int i , y;
    i = 0;
    y = 0;
    while(s && s[y] && s[y][i])
    {
        while(s[y][i])
        {
            i++;
        }
        i = 0;
        y++;
    }
    return (y);
}

int	key_hook(int keycode, t_vars *vars)
{
    // printf("keycode : %d\n",keycode);
        // printf("\n\nKey Code :%d\n\n\n", keycode);
        if (keycode == 0)
        {
            printf("\n\n\n%c\n\n\n",vars->map[vars->playerx][vars->playery]);
            vars->map[vars->playerx][vars->playery] = vars->map[vars->playerx][vars->playery + 1];
        }
        load_map(vars,vars->asset);
        print_map(vars->map);
    //65 68
	return (0);
}
void load_map(t_vars *vars, t_assets *assets)
{

    int w = 50;
    vars->x = 0;
    vars->y = 0;
    
    while (vars->map && vars->map[vars->x] && vars->map[vars->x][vars->y])
    {
        while (vars->map[vars->x][vars->y])
        {
            if(vars->map[vars->x][vars->y] == '1')
                mlx_put_image_to_window(vars->mlx,vars->win,assets->wall,vars->b,vars->a);
            else if(vars->map[vars->x][vars->y] == '0')
                mlx_put_image_to_window(vars->mlx,vars->win,assets->floor,vars->b,vars->a);
            else if(vars->map[vars->x][vars->y] == 'C')
            {
                mlx_put_image_to_window(vars->mlx,vars->win,assets->floor,vars->b,vars->a);
                mlx_put_image_to_window(vars->mlx,vars->win,assets->coin,vars->b,vars->a);

            }
            else if (vars->map[vars->x][vars->y] == 'E')
                mlx_put_image_to_window(vars->mlx,vars->win,assets->door,vars->b,vars->a);
            else if(vars->map[vars->x][vars->y] == 'P')
            {
                vars->playerx = vars->x;
                vars->playery = vars->y;
                mlx_put_image_to_window(vars->mlx,vars->win,assets->floor,vars->b,vars->a);
                mlx_put_image_to_window(vars->mlx,vars->win,assets->player,vars->b,vars->a);
            }
            vars->y++;
            vars->b += 50;
        }
        vars->y = 0;
        vars->b = 0;
        vars->x++;
        vars->a += 50;
    }
}


int main(int ac, char **av)
{
    t_vars  *vars;
    int w  = 50;
    vars = malloc(sizeof (t_vars));
    vars->map = full_map(ft_readmap(av[1]));
    vars->x = ft_strlen(vars->map[1]) * 50;
    vars->y = count_y(vars->map) * 50;
    vars->a = 0;
    vars->b = 0;
    vars->mlx = mlx_init();
    vars->win = mlx_new_window(vars->mlx,vars->x,vars->y,"hello!");
    t_assets *assets;
    vars->asset = (t_assets *)malloc(sizeof (t_assets));
    assets = vars->asset;
    // printf("\n\n\n||||%p||||\n\n\n",vars->mlx);
    // if (assets->wall)
        // mlx_destroy_image(vars->mlx,assets->wall);
    assets->wall = mlx_xpm_file_to_image(vars->mlx, "wall.xpm", &w, &w);
    assets->floor = mlx_xpm_file_to_image(vars->mlx,"floor.xpm",&w,&w);
    assets->coin = mlx_xpm_file_to_image(vars->mlx,"coin.xpm",&w,&w);
    assets->player = mlx_xpm_file_to_image(vars->mlx,"player.xpm",&w,&w);
    assets->door = mlx_xpm_file_to_image(vars->mlx,"exit.xpm",&w,&w);
    load_map(vars, assets);
    // assets->wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &w, &w);
    // assets->floor = mlx_xpm_file_to_image(mlx,"floor.xpm",&w,&w);
    // assets->coin = mlx_xpm_file_to_image(mlx,"coin.xpm",&w,&w);
    // assets->player = mlx_xpm_file_to_image(mlx,"player.xpm",&w,&w);
    // assets->door = mlx_xpm_file_to_image(mlx,"exit.xpm",&w,&w);
    // vars->x = 0;
    // vars->y = 0;
    // vars->map = map;
    // vars->mlx =mlx;
    // vars->win = win;
    // while (map && map[vars->x] && map[vars->x][vars->y])
    // {
    //     while (map[vars->x][vars->y])
    //     {
    //         if(map[vars->x][vars->y] == '1')
    //             mlx_put_image_to_window(mlx,win,assets->wall,vars->b,vars->a);
    //         else if(map[vars->x][vars->y] == '0')
    //             mlx_put_image_to_window(mlx,win,assets->floor,vars->b,vars->a);
    //         else if(map[vars->x][vars->y] == 'C')
    //             mlx_put_image_to_window(mlx,win,assets->coin,vars->b,vars->a);
    //         else if (map[vars->x][vars->y] == 'E')
    //             mlx_put_image_to_window(mlx,win,assets->door,vars->b,vars->a);
    //         else if(map[vars->x][vars->y] == 'P')
    //         {
    //             mlx_put_image_to_window(mlx,win,assets->player,vars->b,vars->a);
    //             load_map(vars);
    //         }
    //         vars->y++;
    //         vars->b += 50;
    //     }
    //     vars->y = 0;
    //     vars->b = 0;
    //     vars->x++;
    //     vars->a += 50;
    // }
    mlx_key_hook(vars->win,key_hook,vars);
    mlx_loop(vars->mlx);
}