#include "get_next_line.h"

char	**remove_leak(char **buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		free(buff[i]);
		i++;
	}
	free(buff);
	return (NULL);
}

void	check_path(int x, int y,char **map)
{
	if(map && map[x] && map[x][y])
	{
		if(map[x][y] == '0' || map[x][y] == 'C' || map[x][y] == 'P')
		{
			map[x][y] = '1';
			check_path(x + 1,y,map);
			check_path(x - 1,y,map);
			check_path(x,y + 1,map);
			check_path(x,y - 1,map);
		}
	}
}

char **ft_strdupdup(char **str)
{
	int i = 0;
	char **new;
	new = (char  **)malloc(sizeof (char *) * (count_y(str) + 1));
	while(str && str[i])
	{
		new[i] = ft_strdup(str[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
void	player_pos(t_vars *va)
{
	    while (va->map && va->map[va->x] && va->map[va->x][va->y])
    {
        while (va->map[va->x][va->y])
        {
            if(va->map[va->x][va->y] == 'P')
            {   
                va->playerx = va->x;
                va->playery = va->y;
            }
            va->y++;
        }
        va->y = 0;
        va->x++;
    }
}
int	check_fill(t_vars *va)
{
	char **map;
	int x;
	int y;
	x = 0;
	y = 0;
	map = ft_strdupdup(va->map);
	player_pos(va);
	check_path(va->playerx,va->playery,map);
	while(map && map[x])
	{
		while (map[x][y])
		{
			if(map[x][y] == 'C')
			{
				remove_leak(map);
				return (0);
			}
			y++;
		}
		y = 0;
		x++;
	}
	// remove_leak(map);
	return (1);
}

// int main(int ac,char **av)
// {
// 	t_vars *va;
// 	va = malloc(sizeof(t_vars));
// 	va->map = full_map(ft_readmap(av[1]));
// 	char **new = ft_strdupdup(va->map);
// 	int x,y ;
// 	x = 0;
// 	y = 0;
// 	check_fill(va);
	
// 	while (new && new[x])
// 	{
// 		if (new[x][y])
// 		{
// 			printf("%s\n",new[x]);
// 		}
// 		x++;
// 	}
// 	printf("check fill : %d",check_fill(va));
// }