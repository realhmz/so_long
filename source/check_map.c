/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:41 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/18 21:02:02 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int	check_lenth(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (map == NULL)
		return (0);
	j = ft_strlen(map[i]);
	while (map && map[i])
	{
		if (j != ft_strlen(map[i]))
			return (0);
		i++;
	}
	i = 0;
	while (map && map[i])
	{
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (0);
		i++;
	}
	i--;
	j = 0;
	while (map[0][j] && map[i][j])
	{
		if (map[0][j] != '1' || map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
int	check_wall(char **map, char *full_map)
{
	int		i;
	int		y;
	char	check[256] = {0};

	i = 0;
	y = 0;
	if (!map)
		return (0);
	while (full_map && full_map[i])
		check[(int)full_map[i++]] = 1;
	i = 0;
	if (!check['1'] || !check['E'] || !check['C'] || !check['P'])
		return (0);
	while (i <= 256)
	{
		if (i == '0' || i == 'E' || i == 'P' || i == 'C' || i == '\n' || i == 'N')
			i++;
		if (i == '1')
			i++;
		if (check[i] == 1)
			return (0);
		i++;
	}
	return (1);
}
int	check_map_name(char *str)
{
	int	i;
	int	fd;

	fd = open(str, O_RDONLY);
	i = ft_strlen(str);
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b' || str[i
		- 3] != '.' || !fd || fd == -1)
		return (0);
	return (1);
}

// int main(int ac, char **av)
// {
//     char *map = ft_readmap(av[1]);
//     char **fmap = full_map(map);
// 	if (ac == 2)
// 		printf("jnb :%d\n dakhl : %d ",check_lenth(fmap), check_wall(fmap,map));
// }