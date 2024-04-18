/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:31 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/18 21:19:11 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	wich_edge(t_game *game, int x, int y)
{
	int up = 0;
	int down = 0;
	int right = 0;
	int left = 0;
	if (game->map[x] && (game->map[x][y] == '0' || game->map[x][y] == 'P'
			|| game->map[x][y] == 'C' || game->map[x][y] == 'E'
			|| game->map[x][y] == 'C'))
	{
		int i = 0;
		if (game->map[x][y + 1] && game->map[x][y + 1] == '1')
			right = 1;
		if (game->map[x - 1][y] && game->map[x - 1][y] == '1')
			up = 2;
		if (game->map[x][y - 1] && game->map[x][y - 1] == '1')
			left = 4;
		if (game->map[x + 1][y] && game->map[x + 1][y] == '1')
			down = 8;
		i = left + right + down + up;
		return (i);
	}
	return (-1);
}