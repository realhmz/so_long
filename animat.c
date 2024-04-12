#include "get_next_line.h"


int mlxhook(t_vars *v)
{
    static int i = 0;
    int j = 0;
    edge_assets(v,v->edges);
    printf("innnnnn: %d\n\n",i);
    if (i >= 10)
        i = 0;
    while (j <= 90000000)
    {
        if (j == 0)
            mlx_put_image_to_window(v->mlx,v->win,v->edges[i],v->b,v->a);        
        j++;
    }
    i++;
    j = 0;
    return(0);
}
void animat(t_vars *v)
{
    // mlx_hook(v->win,02,0,mlxhook,v);
    mlx_loop_hook(v->mlx,mlxhook,v);
}