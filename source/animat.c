// #include "get_next_line.h"

void player_assets(t_vars
// int mlxhook(t_vars *v)
// {
//     static int i = 0;
//     int j = 0;
//     edge_assets(v,v->edges);
//     printf("innnnnn: %d\n\n",i);
//     if (i >= 10)
//         i = 0;
//     while (j <= 90000000)
//     {
//         if (j == 0)
//             mlx_put_image_to_window(v->mlx,v->win,v->edges[i],v->b,v->a);        
//         j++;
//     }
//     i++;
//     j = 0;
//     return(0);
// }
// void animat(t_vars *v)
// {
//     // mlx_hook(v->win,02,0,mlxhook,v);
//     mlx_loop_hook(v->mlx,mlxhook,v);
// }
// void load_animation(t_vars *v,t_assets *a)
// {
//     a = v->asset;
//     a->player_width = 50;
//     a->player_height = 50;
//     a->player_frames[0] = mlx_xpm_file_to_image(v->mlx,"./textures/player/player1.xpm",&a->player_width,&a->player_height);
//     a->player_frames[1] = mlx_xpm_file_to_image(v->mlx,"./textures/player/player2.xpm",&a->player_width,&a->player_height);
//     a->player_frames[2] = mlx_xpm_file_to_image(v->mlx,"./textures/player/player3.xpm",&a->player_width,&a->player_height);
//     a->player_frames[3] = mlx_xpm_file_to_image(v->mlx,"./textures/player/player4.xpm",&a->player_width,&a->player_height);
//     a->player_frames[4] = mlx_xpm_file_to_image(v->mlx,"./textures/player/player5.xpm",&a->player_width,&a->player_height);
//     a->player_frames[5] = mlx_xpm_file_to_image(v->mlx,"./textures/player/player6.xpm",&a->player_width,&a->player_height);
//     // a->player_frames[6] = mlx_xpm_file_to_image(v->mlx,"./textures/player/player7.xpm",&a->player_width,&a->player_height);
//     // a->player_frames[7] = mlx_xpm_file_to_image(v->mlx,"./textures/player/player8.xpm",&a->player_width,&a->player_height);

// }
// void player_animation(t_vars *v, t_assets *a)
// {
//     a = v->asset;
//     static int frame = 0;
//     static int counter = 0;
//     int animation_speed = 2; // Adjust the animation speed as needed
//     load_animation(v,a);

//     printf("player_frames: %p\n", a->player_frames);
//     printf("v->b: %d, v->a: %d\n", v->b, v->a);

//     if (counter % animation_speed == 0)
//     {
//         int result = mlx_put_image_to_window(v->mlx, v->win, a->player_frames[frame], v->b, v->a);
//         printf("mlx_put_image_to_window result: %d\n", result);
//         frame++;
//         if (frame >= 6)
//             frame = 0;
//     }
//     printf("frame : %d\n",frame);
//     printf("counter : %d\n",counter);
//     counter++;
// }

    