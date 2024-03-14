#include <mlx.h>

#include <stdio.h>
#include <unistd.h>

int	ft_fibonacci(int nb)
{
	if(nb < 0)
		return(-1);
	if(nb <=2)
		return(nb);
	return ft_fibonacci(nb - 1) + ft_fibonacci(nb - 2);
}

// int main(void)
// {
// 	void *mlx;
// 	void *win;
// 	int x = 0;
// 	int y = 250;
// 	//create a new window

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 600, 600, "salam!");
// 	//draw a circle
// 	while (x < 600)
// 	{
// 		while (y >= 250 && y <= 350)
// 		{
// 			if (x >= 250 && x <= 350)
// 				mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
// 			y++;			
// 		}
		
// 		y = 250;
// 		x++;
// 	}
// 	//display the window

// 	mlx_loop(mlx);

	
// }