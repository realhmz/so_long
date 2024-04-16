#include "get_next_line.h"


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

void opendoor(t_vars *v)
{
    mlx_put_image_to_window(v->mlx,v->win,v->asset->open_door,v->ex * 50,v->ey * 50);
    play_open_door();

}

void load_map(t_vars *vars, t_assets *assets)
{

    int w = 50;
    vars->x = 0;
    vars->y = 0;
    // print_map(vars->map);
    assets->wall = mlx_xpm_file_to_image(vars->mlx, "./assets/floor/floor.xpm",&w, &w);
    assets->floor = mlx_xpm_file_to_image(vars->mlx,"./assets/floor1.xpm",&w,&w);
    assets->coin = mlx_xpm_file_to_image(vars->mlx,"./assets/coin.xpm",&w,&w);
    assets->player = mlx_xpm_file_to_image(vars->mlx,"./assets/player.xpm",&w,&w);
    assets->door = mlx_xpm_file_to_image(vars->mlx,"./textures/door/closed_door.xpm",&w,&w);
    assets->open_door = mlx_xpm_file_to_image(vars->mlx,"./textures/door/opendoor.xpm",&w,&w);
    assets->playerl = mlx_xpm_file_to_image(vars->mlx,"./assets/playerl.xpm",&w,&w);
    edge_assets(vars,vars->edges);

    while (vars->map && vars->map[vars->x] && vars->map[vars->x][vars->y])
    {
        
        while (vars->map[vars->x][vars->y])
        {
            // if(vars->map[vars->x][vars->y] == '1')
            //    mlx_put_image_to_window(vars->mlx,vars->win,assets->wall,vars->b,vars->a);
            if(vars->map[vars->x][vars->y] == '0')
            {
                mlx_put_image_to_window(vars->mlx,vars->win,assets->floor,vars->b,vars->a);
                put_edge(vars,vars->edges,vars->x,vars->y);
            }
             if(vars->map[vars->x][vars->y] == 'C')
                mlx_put_image_to_window(vars->mlx,vars->win,assets->coin,vars->b,vars->a);
            else if (vars->map[vars->x][vars->y] == 'E')
            {
                mlx_put_image_to_window(vars->mlx,vars->win,assets->floor,vars->b,vars->a);
                // put_edge(vars,vars->edges,vars->x,vars->y);
                mlx_put_image_to_window(vars->mlx,vars->win,assets->door,vars->b,vars->a);
                vars->ey = vars->x;
                vars->ex = vars->y;
            }
            else if(vars->map[vars->x][vars->y] == 'P')
            {   
                vars->playerx = vars->x;
                vars->playery = vars->y;
                // mlx_put_image_to_window(vars->mlx,vars->win,assets->floor,vars->b,vars->a);
                put_edge(vars,vars->edges,vars->x,vars->y);

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



