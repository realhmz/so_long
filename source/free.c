#include "get_next_line.h"

int	free_leaks(t_vars *v)
{
	ft_free_map(v);
	ft_free_assets(v);
	ft_free_sound(v);
	mlx_destroy_window(v->mlx, v->win);
	free(v->mlx);
	free(v);
	system("leaks so_long");
	return (0);
}
void	ft_free_enemy(t_vars *v)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(v->mlx, v->asset->enemyl[i]);
		mlx_destroy_image(v->mlx, v->asset->enemyr[i]);
		i++;
	}
	free(v->asset->enemyl);
	free(v->asset->enemyr);
}
void	ft_free_player(t_vars *v)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(v->mlx, v->asset->player[i]);
		mlx_destroy_image(v->mlx, v->asset->playerl[i]);
		i++;
	}
	free(v->asset->player);
	free(v->asset->playerl);
}
void	ft_free_edges(t_vars *v)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		mlx_destroy_image(v->mlx, v->edges[i]);
		i++;
	}
	free(v->edges);
}
void	ft_free_map(t_vars *v)
{
	int	i;

	i = 0;
	while (v->map[i])
	{
		free(v->map[i]);
		i++;
	}
	free(v->map);
}
void	ft_free_assets(t_vars *v)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(v->mlx, v->asset->player[i]);
		mlx_destroy_image(v->mlx, v->asset->playerl[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(v->mlx, v->asset->enemyl[i]);
		mlx_destroy_image(v->mlx, v->asset->enemyr[i]);
		i++;
	}
	i = 0;
	while (i < 16)
	{
		mlx_destroy_image(v->mlx, v->edges[i]);
		i++;
	}
	free(v->edges);
	free(v->asset->coin);
	free(v->asset->door);
	free(v->asset->open_door);
	free(v->asset->player);
	free(v->asset->playerl);
	free(v->asset->enemyl);
	free(v->asset->enemyr);
	free(v->asset);
}
void	ft_free_sound(t_vars *v)
{
	free(v->sound->start);
	free(v->sound->kill);
	free(v->sound->enemy);
	free(v->sound->end);
	free(v->sound);
}

//