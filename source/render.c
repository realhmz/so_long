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
    mlx_put_image_to_window(v->mlx,v->win,v->asset->open_door,v->ex * 50 + v->cnsty,v->ey * 50 + v->cnstx);
    play_open_door(v->sound);

}
void    enemy_assets(t_vars *v, t_assets *a)
{
    int w = 50;
    a->enemyl[0] = mlx_xpm_file_to_image(v->mlx,"./textures/enemy/l/1.xpm",&w,&w);
    a->enemyl[1] = mlx_xpm_file_to_image(v->mlx,"./textures/enemy/l/2.xpm",&w,&w);
    a->enemyl[2] = mlx_xpm_file_to_image(v->mlx,"./textures/enemy/l/3.xpm",&w,&w);
    a->enemyl[3] = mlx_xpm_file_to_image(v->mlx,"./textures/enemy/l/4.xpm",&w,&w);
    a->enemyr[0] = mlx_xpm_file_to_image(v->mlx,"./textures/enemy/r/1.xpm",&w,&w);
    a->enemyr[1] = mlx_xpm_file_to_image(v->mlx,"./textures/enemy/r/2.xpm",&w,&w);
    a->enemyr[2] = mlx_xpm_file_to_image(v->mlx,"./textures/enemy/r/3.xpm",&w,&w);
    a->enemyr[3] = mlx_xpm_file_to_image(v->mlx,"./textures/enemy/r/4.xpm",&w,&w);
}
void load_map(t_vars *vars, t_assets *assets)
{

    int w = 50;
    vars->x = 0;
    vars->y = 0;
    // print_map(vars->map);
    assets->wall = mlx_xpm_file_to_image(vars->mlx, "./assets/floor/floor.xpm",&w, &w);
    assets->floor = mlx_xpm_file_to_image(vars->mlx,"./assets/floor1.xpm",&w,&w);
    assets->coin = mlx_xpm_file_to_image(vars->mlx,"./textures/player/1.xpm",&w,&w);
    assets->player = mlx_xpm_file_to_image(vars->mlx,"./assets/player.xpm",&w,&w);
    assets->door = mlx_xpm_file_to_image(vars->mlx,"./textures/door/closed_door.xpm",&w,&w);
    assets->open_door = mlx_xpm_file_to_image(vars->mlx,"./textures/door/opendoor.xpm",&w,&w);
    assets->playerl = mlx_xpm_file_to_image(vars->mlx,"./assets/playerl.xpm",&w,&w);
    edge_assets(vars,vars->edges);
    enemy_assets(vars,assets);

    while (vars->map && vars->map[vars->x] && vars->map[vars->x][vars->y])
    {
        
        while (vars->map[vars->x][vars->y])
        {
            // if(vars->map[vars->x][vars->y] == '1')
            //    mlx_put_image_to_window(vars->mlx,vars->win,assets->wall,vars->b,vars->a);
            if(vars->map[vars->x][vars->y] == 'N')
            {
                vars->enemyx = vars->x;
                vars->enemyy = vars->y;
                put_edge(vars,vars->edges,vars->x,vars->y);
                put_enemy(vars,assets,1);
            }
            if(vars->map[vars->x][vars->y] == '0')
            {
                // mlx_put_image_to_window(vars->mlx,vars->win,assets->floor,vars->b,vars->a);
                put_edge(vars,vars->edges,vars->x,vars->y);
            }
             if(vars->map[vars->x][vars->y] == 'C')
                put_edge(vars,vars->edges,vars->x,vars->y);
            else if (vars->map[vars->x][vars->y] == 'E')
            {
                put_edge(vars,vars->edges,vars->x,vars->y);
            }
            else if(vars->map[vars->x][vars->y] == 'P')
            {   
                vars->playerx = vars->x;
                vars->playery = vars->y;
                // mlx_put_image_to_window(vars->mlx,vars->win,assets->floor,vars->b,vars->a);
                put_edge(vars,vars->edges,vars->x,vars->y);
                // put_player(vars,assets,1);

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



