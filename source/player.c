#include "get_next_line.h"

void    turn_right(t_vars *v, t_assets *a)
{
		if(v->map[v->playerx][v->playery + 1] == 'E' && v->c == 0)
		{
			printf("Congrats you win!!\n");
			stop_audio();
			play_end();
			exit(free_leaks(v));
			mlx_destroy_window(v->mlx,v->win);
		}
		if (v->map[v->playerx][v->playery + 1] == 'C')
			{
				play_kill();
				if (v->c == 1)
				{
					v->c -= 1;
					opendoor(v);
				}
				else
					v->c -= 1;
			}

		if (v->map[v->playerx][v->playery + 1] == '0' || v->map[v->playerx][v->playery + 1] == 'C')
		{
			v->map[v->playerx][v->playery + 1]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
			render_sky(v,v->asset);
			// play_walk();
			mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50 + v->cnsty,v->playerx * 50 + v->cnstx);
			v->playery += 1;
			load_map(v,v->asset);
			put_player(v,v->asset,1);
			put_enemy(v,v->asset,1);

			v->moves++;
			print_moves(v);
		}
}

void    turn_left(t_vars *v, t_assets *a)
{
		if(v->map[v->playerx][v->playery - 1] == 'E' && v->c == 0)
		{
			printf("You win Congrats!!\n\n");
			stop_audio();
			play_end();
			exit(free_leaks(v));
			mlx_destroy_window(v->mlx,v->win);
		}
		if (v->map[v->playerx][v->playery - 1] == 'C')
			{
				play_kill();
				if (v->c == 1)
				{
					v->c -= 1;
					opendoor(v);
				}
				else
					v->c -= 1;
			}
		if (v->map[v->playerx][v->playery - 1] == '0' || v->map[v->playerx][v->playery - 1] == 'C' )
		{
			v->map[v->playerx][v->playery - 1]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
			render_sky(v,v->asset);
			// play_walk();
			mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50 + v->cnsty,v->playerx * 50 + v->cnstx);
			v->playery -= 1;
			load_map(v,v->asset);
			put_player(v,v->asset,0);
			put_enemy(v,v->asset,0);
			v->moves++;
			print_moves(v);
		}
}
void    go_up(t_vars *v, t_assets *a)
{
		if(v->map[v->playerx + 1][v->playery] == 'E' && v->c == 0)
		{
			stop_audio();
			play_end();
			exit(free_leaks(v));
			mlx_destroy_window(v->mlx,v->win);
		}
		if (v->map[v->playerx + 1][v->playery] == 'C')
			{
				play_kill();
				if (v->c == 1)
				{
					v->c -= 1;
					opendoor(v);
				}
				else
					v->c -= 1;
			}
		if (v->map[v->playerx + 1][v->playery] == '0' || v->map[v->playerx + 1][v->playery] == 'C')
		{
			v->map[v->playerx + 1][v->playery]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
			render_sky(v,v->asset);
			// play_walk();
			mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50 + v->cnsty,v->playerx * 50 + v->cnstx);
			v->playerx += 1;
			load_map(v,v->asset);
			put_player(v,v->asset,1);
			put_enemy(v,v->asset,1);
			print_moves(v);
			v->moves++;
		}
}

void    go_down(t_vars *v, t_assets *a)
{
		if(v->map[v->playerx - 1][v->playery] == 'E' && v->c == 0)
		{
			stop_audio();
			play_end();
			exit(free_leaks(v));
			mlx_destroy_window(v->mlx,v->win);
		}
		if (v->map[v->playerx - 1][v->playery] == 'C')
			{
				play_kill();
				if (v->c == 1)
				{
					v->c -= 1;
					opendoor(v);
				}
				else
					v->c -= 1;	
			}
		if (v->map[v->playerx - 1][v->playery] == '0' || v->map[v->playerx - 1][v->playery] == 'C')
		{
			render_sky(v,v->asset);
			// play_walk();
			v->map[v->playerx - 1][v->playery]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
			mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50 + v->cnsty,v->playerx * 50 + v->cnstx);
			v->playerx -= 1;
			load_map(v,v->asset);
			put_player(v,v->asset,1);
			put_enemy(v,v->asset,1);
			print_moves(v);
			v->moves++;
		}
}

void    put_player(t_vars *vars, t_assets *assets,int i)
{
	player_assets(vars);
	static int j = 0;
	static int x = 0;
	if (i == 1)
	{
		mlx_put_image_to_window(vars->mlx,vars->win,assets->player[j],vars->playery * 50 + vars->cnsty,vars->playerx *50 + vars->cnstx);
		j++;
	}
	else
	{
		mlx_put_image_to_window(vars->mlx,vars->win,assets->playerl[x],vars->playery * 50 + vars->cnsty,vars->playerx *50 + vars->cnstx);
		x++;
	}
	if (j == 6)
		j = 0;
	if (x == 6)
		x = 0;
}

int	key_hook(int keycode, t_vars *v)
{
	// printf("keycode : %d\n",keycode);
	// printf("\n\ncoins left == %d \n\n",v->c);
	if (keycode == 53)
	{
		stop_audio();
		play_end();
		exit(free_leaks(v));		
	}
	if (keycode == 2)
		turn_right(v,v->asset);
	if(keycode == 0)
		turn_left(v,v->asset);
	if (keycode == 1)
		go_up(v,v->asset);
	if (keycode == 13)
		go_down(v,v->asset);
	if (keycode == 126)
		enemy_go_up(v);
	if (keycode == 125)
		enemy_go_down(v);
	if (keycode == 123)
		enemy_go_left(v);
	if (keycode == 124)
		enemy_go_right(v);
	if (keycode == 49)
		enemy_attack(v);
	
	return (0);
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
		vars->edges = malloc(sizeof(void *) * 16);
		vars->x = ft_strlen(vars->map[1]) * 50;
		vars->y = count_y(vars->map) * 50;
		vars->a = 0;
		vars->b = 0;
		vars->winw = 1920;
		vars->winh = 1080;
		vars->cnsty = (vars->winw / 2) - (vars->x / 2);
		vars->cnstx = (vars->winh / 2) - (vars->y / 2);
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx,vars->winw,vars->winh,"SUS among us!");
		vars->asset = (t_assets *)malloc(sizeof (t_assets));
		t_assets *assets;
		assets = vars->asset;
		play_song();
		assets->sky = malloc(sizeof(void *) * 3);
		assets->player = malloc(sizeof(void *) * 6);
		assets->playerl = malloc(sizeof(void *) * 6);
		assets->enemyl = malloc(sizeof(void *) * 4);
		assets->enemyr = malloc(sizeof(void *) * 4);
		vars->c = count_c(vars);
		vars->moves = 0;
		render_sky(vars,assets);
        load_map(vars, assets);
		put_player(vars,vars->asset,1);
		mlx_hook(vars->win,2,(1L<<0),key_hook,vars);
		// mlx_loop_hook(vars->win,key_hook,vars);
		mlx_loop(vars->mlx);
	}
	// else
		// printf("Map ERROR");
	// exit(free_leaks(vars));
	// return(0);
// }
// ADD ESC to exit game; DONE
// fix leaks; 
// flod fill; 
// add new assets; 
// sky effect dark to light;
// render player foq l map khawya -> hitach l edges kaybqaw khasrin;
// add sound effects;
// add animation to player; (optional)
