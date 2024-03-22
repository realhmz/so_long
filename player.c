#include "get_next_line.h"
#include <mlx.h>

void    turn_right(t_vars *v, t_assets *a)
{
		// print_map(vars->map);
		// printf("after \n\n");
		if(v->map[v->playerx][v->playery + 1] == 'E' && v->c == 0)
		{
			printf("Congrats you win!!\n");
			exit(0);
			mlx_destroy_window(v->mlx,v->win);
		}
		if (v->map[v->playerx][v->playery + 1] == 'C')
			v->c -= 1;
		if (v->map[v->playerx][v->playery + 1] != '1')
		{
			v->map[v->playerx][v->playery + 1]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
			if (v->map[v->playerx][v->playery] == 'E')
				mlx_put_image_to_window(v->mlx,v->win,a->door,v->playerx *50,v->playery*50);
			else
				mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50,v->playerx * 50);
			v->playery += 1;
			put_player(v,v->asset);
			load_map(v,v->asset);
		}
		// /print_map(vars->map);
}

void    turn_left(t_vars *v, t_assets *a)
{
		if(v->map[v->playerx][v->playery - 1] == 'E' && v->c == 0)
		{
			printf("You win Congrats!!\n\n");
			exit(0);
			mlx_destroy_window(v->mlx,v->win);
		}
		if (v->map[v->playerx][v->playery - 1] == 'C')
			v->c -= 1;
		if (v->map[v->playerx][v->playery - 1] != '1')
		{
			v->map[v->playerx][v->playery - 1]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
			if (v->map[v->playerx][v->playery] == 'E')
				mlx_put_image_to_window(v->mlx,v->win,a->door,v->playerx *50,v->playery*50);
			else
				mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50,v->playerx * 50);
			v->playery -= 1;
			put_player(v,v->asset);
			load_map(v,v->asset);
		}
}
void    go_up(t_vars *v, t_assets *a)
{
		if(v->map[v->playerx + 1][v->playery] == 'E' && v->c == 0)
		{
			exit(0);
			mlx_destroy_window(v->mlx,v->win);
		}
		if (v->map[v->playerx + 1][v->playery] == 'C')
			v->c -= 1;
		if (v->map[v->playerx + 1][v->playery] != '1')
		{
			v->map[v->playerx + 1][v->playery]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
			if (v->map[v->playerx][v->playery] == 'E')
				mlx_put_image_to_window(v->mlx,v->win,a->door,v->playerx *50,v->playery*50);
			else
				mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50,v->playerx * 50);
			v->playerx += 1;
			printf("\n\n%d\n\n\n",v->playerx);
			put_player(v,v->asset);
			load_map(v,v->asset);
		}
}

void    go_down(t_vars *v, t_assets *a)
{
		if(v->map[v->playerx - 1][v->playery] == 'E' && v->c == 0)
		{
			exit(0);
			mlx_destroy_window(v->mlx,v->win);
		}        
		if (v->map[v->playerx - 1][v->playery] == 'C')
			v->c -= 1; 
		if (v->map[v->playerx - 1][v->playery] != '1')
		{
			v->map[v->playerx - 1][v->playery]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
			if (v->map[v->playerx][v->playery] == 'E')
				mlx_put_image_to_window(v->mlx,v->win,a->door,v->playerx *50,v->playery*50);
			else
				mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50,v->playerx * 50);
			v->playerx -= 1;
			put_player(v,v->asset);
			load_map(v,v->asset);
		}
}

void    put_player(t_vars *vars, t_assets *assets)
{
	mlx_put_image_to_window(vars->mlx,vars->win,assets->player,vars->playery * 50,vars->playerx *50);
}

int	key_hook(int keycode, t_vars *v)
{
	printf("keycode : %d\n",keycode);
	printf("\n\ncoins left == %d \n\n",v->c);
	// 2 = right // 0 == left // 13 == up  // 1 == down//

	if (keycode == 2 || keycode == 124)
	{
		turn_right(v,v->asset);
	}
	if(keycode == 0 || keycode == 123)
		turn_left(v,v->asset);
	if (keycode == 1 || keycode == 125)
		go_up(v,v->asset);
	if (keycode == 13 || keycode == 126)
		go_down(v,v->asset);
	
		// print_map(vars->map);
	//65 68
	return (0);
}

void	animate(t_vars *va, t_xpm *a)
{
	int	i = 800;
	int j = 600;
	a->a = malloc(sizeof(void *) * 19);
	a->a[0] = mlx_xpm_file_to_image(va->mlx,"./a/01.xpm",&i,&j);
	a->a[1] = mlx_xpm_file_to_image(va->mlx,"./a/02.xpm",&i,&j);
	a->a[2] = mlx_xpm_file_to_image(va->mlx,"./a/03.xpm",&i,&j);
	a->a[3] = mlx_xpm_file_to_image(va->mlx,"./a/04.xpm",&i,&j);
	a->a[4] = mlx_xpm_file_to_image(va->mlx,"./a/05.xpm",&i,&j);
	a->a[5] = mlx_xpm_file_to_image(va->mlx,"./a/06.xpm",&i,&j);
	a->a[6] = mlx_xpm_file_to_image(va->mlx,"./a/07.xpm",&i,&j);
	a->a[7] = mlx_xpm_file_to_image(va->mlx,"./a/08.xpm",&i,&j);
	a->a[8] = mlx_xpm_file_to_image(va->mlx,"./a/09.xpm",&i,&j);
	a->a[9] = mlx_xpm_file_to_image(va->mlx,"./a/10.xpm",&i,&j);
	a->a[10] = mlx_xpm_file_to_image(va->mlx,"./a/11.xpm",&i,&j);
	a->a[11] = mlx_xpm_file_to_image(va->mlx,"./a/12.xpm",&i,&j);
	a->a[12] = mlx_xpm_file_to_image(va->mlx,"./a/13.xpm",&i,&j);
	a->a[13] = mlx_xpm_file_to_image(va->mlx,"./a/14.xpm",&i,&j);
	a->a[14] = mlx_xpm_file_to_image(va->mlx,"./a/15.xpm",&i,&j);
	a->a[15] = mlx_xpm_file_to_image(va->mlx,"./a/16.xpm",&i,&j);
	a->a[16] = mlx_xpm_file_to_image(va->mlx,"./a/17.xpm",&i,&j);
	a->a[17] = mlx_xpm_file_to_image(va->mlx,"./a/18.xpm",&i,&j);
	a->a[18] = mlx_xpm_file_to_image(va->mlx,"./a/19.xpm",&i,&j);


	
	// mlx_put_image_to_window(va->mlx,va->win,a->b,0,0);


}
int mlxhook(t_vars *va)
{
	static int i = 0;
	int j = 0;

	if (i == 16)
	{	
		printf("dkhl \n\n");
		i = 0;
	}
	while (j < 18000000)
	{
		if (j == 0)
			mlx_put_image_to_window(va->mlx,va->win,va->xpm->a[i],0,0);
		j++;
	}
	i++;
	printf("%d\n\n",i);
	
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	t_vars  *vars;
	vars = malloc(sizeof (t_vars));
	vars->map = full_map(ft_readmap(av[1]));
	// if (check_lenth(vars->map) && check_wall(vars->map,ft_readmap(av[1])) && check_map_name(av[1]) && check_fill(vars))
	// {
		int w;
		w = 50;
		vars->xpm = malloc(sizeof(t_xpm));
		vars->x = ft_strlen(vars->map[1]) * 50;
		vars->y = count_y(vars->map) * 50;
		vars->a = 0;
		vars->b = 0;
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx,1920,1080,"SUS among us!");
		vars->asset = (t_assets *)malloc(sizeof (t_assets));
		t_assets *assets;
		assets = vars->asset;
		vars->c = count_c(vars);
        load_map(vars, assets);
		// printf("\n\nDAAAAAYZAAA \n\n");
		// printf("check lenth : %d\n\n",check_lenth(vars->map));
		// printf("check WALL : %d\n\n",check_wall(vars->map,ft_readmap(av[1])));
		// printf("check map_name : %d\n\n",check_map_name(av[1]));
		// printf("check flood fill : %d\n\n",check_fill(vars));
		put_player(vars,vars->asset);
		mlx_key_hook(vars->win,key_hook,vars);
		animate(vars,vars->xpm);
		
		mlx_loop_hook(vars->mlx,mlxhook,vars);
		mlx_loop(vars->mlx);
	// }
	// else
	// 	printf("Map ERROR");
	return(0);
}