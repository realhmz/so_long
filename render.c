#include "get_next_line.h"
#include <mlx.h>

// void    render(int x,int y,char *wall)
// {
  
// }
int main(int ac, char **av)
{
    char **map = full_map(ft_readmap(av[1]));
    int x = ft_strlen(map[1]) * 50;
    int y = x;
    void *mlx;
    void *win;
    void * floor;
    int w = 50;
    void *img;
    mlx = mlx_init();
    win = mlx_new_window(mlx,x,y,"hello!");
    img = mlx_xpm_file_to_image(mlx, av[2], &w, &w);
    floor = mlx_xpm_file_to_image(mlx,av[3],&w,&w);
    x = 0;
    y = 0;
    while (map && map[x] && map[x][y])
    {
        while (map[x][y])
        {
            if(map[x][y] == '1')
                mlx_put_image_to_window(mlx,win,img,x * 50,y * 50);
                // printf("#");
            // else if(map[x][y] == 'C')
                // printf("&");
            else if(map[x][y] == '0')
                mlx_put_image_to_window(mlx,win,floor,x * 50, y * 50);
                // printf(".");
            y++;       
        }
        y = 0;
        // printf("\n");
        x++;
    }
    
    mlx_loop(mlx);
}