#include "get_next_line.h"

void    turn_right(t_vars *v, t_assets *a)
{

		if(v->map[v->playerx][v->playery + 1] == 'E' && v->c == 0)
		{
			printf("Congrats you win!!\n");
			stop_audio();
			exit(free_leaks(v));
			mlx_destroy_window(v->mlx,v->win);
		}
		if (v->map[v->playerx][v->playery + 1] == 'C')
			{
				play_kill(1);
				v->c -= 1;
				if (v->c == 0)
					opendoor(v);
			}

		if (v->map[v->playerx][v->playery + 1] == '0' || v->map[v->playerx][v->playery + 1] == 'C')
		{
			v->map[v->playerx][v->playery + 1]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
			mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50,v->playerx * 50);
			v->playery += 1;
			put_player(v,v->asset,1);
			load_map(v,v->asset);
		}
}

void    turn_left(t_vars *v, t_assets *a)
{
		if(v->map[v->playerx][v->playery - 1] == 'E' && v->c == 0)
		{
			printf("You win Congrats!!\n\n");
			stop_audio();
			exit(free_leaks(v));
			mlx_destroy_window(v->mlx,v->win);
		}
		if (v->map[v->playerx][v->playery - 1] == 'C')
			{
				play_kill(1);
				v->c -= 1;
				if (v->c == 0)
				{
					opendoor(v);
				}
				
			}
		if (v->map[v->playerx][v->playery - 1] == '0' || v->map[v->playerx][v->playery - 1] == 'C' )
		{
			v->map[v->playerx][v->playery - 1]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
			mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50,v->playerx * 50);
			v->playery -= 1;
			put_player(v,v->asset,0);
			load_map(v,v->asset);
		}
}
void    go_up(t_vars *v, t_assets *a)
{
		if(v->map[v->playerx + 1][v->playery] == 'E' && v->c == 0)
		{
			stop_audio();
			exit(free_leaks(v));
			mlx_destroy_window(v->mlx,v->win);
		}
		if (v->map[v->playerx + 1][v->playery] == 'C')
			{
				play_kill(1);
				v->c -= 1;
				if (v->c == 0)
					opendoor(v);
			}
		if (v->map[v->playerx + 1][v->playery] == '0' || v->map[v->playerx + 1][v->playery] == 'C')
		{
			v->map[v->playerx + 1][v->playery]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
				mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50,v->playerx * 50);
			v->playerx += 1;
			put_player(v,v->asset,1);
			load_map(v,v->asset);
		}
}

void    go_down(t_vars *v, t_assets *a)
{
		if(v->map[v->playerx - 1][v->playery] == 'E' && v->c == 0)
		{
			stop_audio();
			exit(free_leaks(v));
			mlx_destroy_window(v->mlx,v->win);
		}
		if (v->map[v->playerx - 1][v->playery] == 'C')
			{
				play_kill(1);
				v->c -= 1;
				if (v->c == 0)
					opendoor(v);	
			}
		if (v->map[v->playerx - 1][v->playery] == '0' || v->map[v->playerx - 1][v->playery] == 'C')
		{
			v->map[v->playerx - 1][v->playery]  = 'P';
			v->map[v->playerx][v->playery]  = '0';
			mlx_put_image_to_window(v->mlx,v->win,a->floor,v->playery * 50,v->playerx * 50);
			v->playerx -= 1;
			put_player(v,v->asset,1);
			load_map(v,v->asset);
		}
}

void    put_player(t_vars *vars, t_assets *assets,int i)
{
	// player_animation(vars,assets);
	
	if (i == 1)
		mlx_put_image_to_window(vars->mlx,vars->win,assets->player,vars->playery * 50,vars->playerx *50);
	else
		mlx_put_image_to_window(vars->mlx,vars->win,assets->playerl,vars->playery * 50,vars->playerx *50);	
}

int	key_hook(int keycode, t_vars *v)
{
	// printf("keycode : %d\n",keycode);
	// printf("\n\ncoins left == %d \n\n",v->c);
	// 2 = right // 0 == left // 13 == up  // 1 == down//
	// printf("|||||%d||||\n\n",i);
	if (v->c == 0 )
		load_map(v,v->asset);
	if (keycode == 53)
	{
		stop_audio();
		exit(free_leaks(v));		
	}
	if (keycode == 2 || keycode == 100)
		turn_right(v,v->asset);
	if(keycode == 0 || keycode == 97)
		turn_left(v,v->asset);
	if (keycode == 1 || keycode == 115)
		go_up(v,v->asset);
	if (keycode == 13 || keycode == 119)
		go_down(v,v->asset);

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
		vars->mlx = mlx_init();
		vars->win = mlx_new_window(vars->mlx,vars->x,vars->y,"SUS among us!");
		vars->asset = (t_assets *)malloc(sizeof (t_assets));
		t_assets *assets;
		assets = vars->asset;
		play_song(1);
		assets->sky = malloc(sizeof(void *) * 2);
		// assets->player_frames = malloc(sizeof(void *) * 8);
		vars->c = count_c(vars);
		execve("afplay", (char *[]){"afplay", "./sounds/start.wav", 0}, 0);
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
