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

int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	t_vars  *vars;
	vars = malloc(sizeof (t_vars));
	vars->map = full_map(ft_readmap(av[1]));
	if (check_lenth(vars->map) && check_wall(vars->map,ft_readmap(av[1])) && check_map_name(av[1]) && check_fill(vars))
	{
		int w;
		w = 50;
		vars->x = ft_strlen(vars->map[1]) * 50;
		vars->y = count_y(vars->map) * 50;
		vars->a = 0;
		vars->b = 0;
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx,vars->x,vars->y,"SUS among us!");
		vars->asset = (t_assets *)malloc(sizeof (t_assets));
		t_assets *assets;
		assets = vars->asset;
		vars->c = count_c(vars);
        load_map(vars, assets);
		printf("\n\nDAAAAAYZAAA \n\n");
		printf("check lenth : %d\n\n",check_lenth(vars->map));
		printf("check WALL : %d\n\n",check_wall(vars->map,ft_readmap(av[1])));
		printf("check map_name : %d\n\n",check_map_name(av[1]));
		printf("check flood fill : %d\n\n",check_fill(vars));
		put_player(vars,vars->asset);
		mlx_key_hook(vars->win,key_hook,vars);
		mlx_loop(vars->mlx);
	}
	else
		printf("Map ERROR");
	return(0);
}