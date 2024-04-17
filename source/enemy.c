#include "get_next_line.h"

void enemy_go_down(t_vars *v)
{
	if(v->map[v->enemyx + 1][v->enemyy] == '0' || v->map[v->enemyx + 1][v->enemyy] == 'C')
	{
		v->map[v->enemyx][v->enemyy] = '0';
		v->enemyx++;
		render_sky(v,v->asset);
		load_map(v,v->asset);
		put_player(v,v->asset,1);
		put_enemy(v, v->asset, 1);
		print_moves(v);
	}

	// play_walk();
}
void    enemy_go_up(t_vars *v)
{
	if (v->map[v->enemyx - 1][v->enemyy] == '0' || v->map[v->enemyx - 1][v->enemyy] == 'C')
	{
		v->map[v->enemyx][v->enemyy] = '0';
		v->enemyx--;
		render_sky(v,v->asset);
		load_map(v,v->asset);
		put_player(v,v->asset,1);
		put_enemy(v, v->asset, 0);
		print_moves(v);
	}
	// play_walk();
} 

void    enemy_go_left(t_vars *v)
{
	if (v->map[v->enemyx][v->enemyy - 1] == '0' || v->map[v->enemyx][v->enemyy - 1] == 'C')
	{
		v->map[v->enemyx][v->enemyy] = '0';
		v->enemyy--;
		render_sky(v,v->asset);
		load_map(v,v->asset);
		put_player(v,v->asset,1);
		put_enemy(v, v->asset, 0);
		print_moves(v);
	}
	// play_walk();
}
void    enemy_go_right(t_vars *v)
{
	if (v->map[v->enemyx][v->enemyy + 1] == '0' || v->map[v->enemyx][v->enemyy + 1] == 'C')
	{
		v->map[v->enemyx][v->enemyy] = '0';
		v->enemyy++;
		render_sky(v,v->asset);
		load_map(v,v->asset);
		put_player(v,v->asset,1);
		put_enemy(v, v->asset, 1);
		print_moves(v);
	}
	// play_walk();
}
void    put_enemy(t_vars *v, t_assets *a, int i)
{
	enemy_assets(v, a);
	static int j = 0;
	static int x = 0;

	if(i == -1)
	{
		mlx_put_image_to_window(v->mlx,v->win,a->enemyl[j - 1],v->enemyy * 50 + v->cnsty,v->enemyx *50 + v->cnstx);
		j++;
	}
	if (i == -2)
	{
		mlx_put_image_to_window(v->mlx,v->win,a->enemyr[x - 1],v->enemyy * 50 + v->cnsty,v->enemyx *50 + v->cnstx);
		x++;
	}
	
	if (i == 1)
	{
		mlx_put_image_to_window(v->mlx,v->win,a->enemyr[j],v->enemyy* 50 + v->cnsty,v->enemyx *50 + v->cnstx);
		j++;
	}
	if (i == 0)
	{
		mlx_put_image_to_window(v->mlx,v->win,a->enemyl[x],v->enemyy * 50 + v->cnsty,v->enemyx *50 + v->cnstx);
		x++;
	}
	if (j == 4)
		j = 0;
	if (x == 4)
		x = 0;
}

void enemy_attack(t_vars *v)
{
	mlx_put_image_to_window(v->mlx,v->win,"./textures/enemy/attack.xpm",v->enemyy * 50 + v->cnsty,v->enemyy * 50 + v->cnstx);
	if (v->playerx == v->enemyx && v->playery == v->enemyy)
	{
		mlx_clear_window(v->mlx,v->win);
		stop_audio();
		play_kill();
		exit(free_leaks(v));
		mlx_destroy_window(v->mlx,v->win);
	}
}