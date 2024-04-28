// #include "get_next_line.h"

// #include <stdio.h>
// #include <math.h>
// #include <stdlib.h> // for malloc

// typedef struct {
//     double x, y, z;
// } t_dot;

// void isometric(t_dot *dot, double angle) {
//     double tempX = dot->x;
//     double tempY = dot->y;

//     dot->x = (tempX - tempY) * cos(angle);
//     dot->y = ((tempX + tempY) * sin(angle)) - dot->z;
// }

// int main() {
//     void *mlx;
//     void *win;
//     t_dot *dot;
//     int size = 250;
//     double angle = 25 * M_PI / 180;
//     double offsetX = 250;
//     double offsetY = 250; 

//     dot = malloc(sizeof(t_dot));
//     dot->x = 0;
//     dot->y = 0;
//     dot->z = 0;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 500, 500, "3D Square");

//     for (int x = 0; x < size; x++) {
//         for (int y = 0; y < size; y++) {
//             dot->x = x;
//             dot->y = y;
//             dot->z = 0;
//             if( dot->x == 0 || dot->y == 0)
//                 dot->z = 250;
//             isometric(dot, angle);
//             mlx_pixel_put(mlx, win, dot->x + offsetX, dot->y + offsetY, 0X0000FF);
//         }
//     }
//     mlx_loop(mlx);

//     free(dot);

//     return 0;
// }