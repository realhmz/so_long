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

void load_map(t_vars *vars, t_assets *assets)
{

    int w = 50;
    vars->x = 0;
    vars->y = 0;
    // print_map(vars->map);
    assets->wall = mlx_xpm_file_to_image(vars->mlx, "wall.xpm", &w, &w);
    assets->floor = mlx_xpm_file_to_image(vars->mlx,"floor.xpm",&w,&w);
    assets->coin = mlx_xpm_file_to_image(vars->mlx,"coin.xpm",&w,&w);
    assets->player = mlx_xpm_file_to_image(vars->mlx,"player.xpm",&w,&w);
    assets->door = mlx_xpm_file_to_image(vars->mlx,"exit.xpm",&w,&w);

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



