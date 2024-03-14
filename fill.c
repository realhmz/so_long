#include "get_next_line.h"

// char    *fill_map(char **map)
// {
//     int i;
// 	int	j;
// 	j = 0;
//     i = 0;


// 	while (map && map[i] && map[i][j])
// 	{
// 		while (map[i][j])
// 		{
// 			map[i][j] = '1';
// 			j++;
// 		}
		
// 		i++
// 	}
	
// }
void	check_path(int x, int y,char **map)
{
	if(map && map[x] && map[x][y])
	{
		if(map[x][y] == '0' || map[x][y] == 'C' || map[x][y] == 'P')
		{
			map[x][y] = '1';
			check_path(x + 1,y,map);
			check_path(x,y + 1,map);
			check_path(x,y - 1,map);
		}
	}
}

int main(int ac ,char **av)
{
	int x;
	int y;
	x = 0;
	y = 0;
	char **map = full_map(ft_readmap(av[1]));
	if (ac == 2)
	{
		while (map && map[x] &&map[x][y])
		{
			while (map[x][y])
			{
				if(map[x][y] == 'P')
					break;
				y++;
			}
			if (map[x][y] == 'P')
				break;
			y = 0;
			x++;
		}
		// printf("x:%d  y:%d",x,y);
		check_path(x,y,map);
	}
		printf("%s\n",map[0]);
		printf("%s\n",map[1]);
		printf("%s\n",map[2]);
		printf("%s\n",map[3]);
		printf("%s\n",map[4]);
		printf("%s\n",map[5]);
		printf("%s\n",map[6]);
		printf("%s\n",map[7]);
		printf("%s\n",map[8]);

	
}