#include "get_next_line.h"


void    edge_assets(t_vars *v,void **e)
{
    int w;
    w = 50;
    e[0] = mlx_xpm_file_to_image(v->mlx,"floor.xpm",&w,&w);
    e[1] = mlx_xpm_file_to_image(v->mlx,"e1.xpm",&w,&w);
    e[2] = mlx_xpm_file_to_image(v->mlx,"e2.xpm",&w,&w);
    e[3] = mlx_xpm_file_to_image(v->mlx,"e3.xpm",&w,&w);
    e[4] = mlx_xpm_file_to_image(v->mlx,"e4.xpm",&w,&w);
    e[5] = mlx_xpm_file_to_image(v->mlx,"e5.xpm",&w,&w);
    e[6] = mlx_xpm_file_to_image(v->mlx,"e6.xpm",&w,&w);
    e[7] = mlx_xpm_file_to_image(v->mlx,"e7.xpm",&w,&w);
    e[8] = mlx_xpm_file_to_image(v->mlx,"e8.xpm",&w,&w);
    e[9] = mlx_xpm_file_to_image(v->mlx,"e9.xpm",&w,&w);
    e[10] = mlx_xpm_file_to_image(v->mlx,"e10.xpm",&w,&w);
    e[11] = mlx_xpm_file_to_image(v->mlx,"e11.xpm",&w,&w);
    e[12] = mlx_xpm_file_to_image(v->mlx,"e12.xpm",&w,&w);
    e[13] = mlx_xpm_file_to_image(v->mlx,"e13.xpm",&w,&w);
    e[14] = mlx_xpm_file_to_image(v->mlx,"e14.xpm",&w,&w);
    e[15] = mlx_xpm_file_to_image(v->mlx,"e15.xpm",&w,&w);

}

void    put_edge(t_vars *v,void **e,int x,int y)
{
    int i ;
    i = wich_edge(v,x,y);
    if (i == -1)
        return;
    
    printf("\n\ni :: %d\n\n",i);
    mlx_put_image_to_window(v->mlx,v->win,e[i],y * 50, x *50);
    
}
