/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:54 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/18 21:19:11 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_itoa(int n)
{
	int		len;
	int		tmp;
	char	*str;

	len = 1;
	tmp = n;
	while (tmp /= 10)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
void	print_moves(t_game *game)
{
	char	*str;
	char	*tmp;
	tmp = ft_itoa(game->moves);
	str = ft_strjoin("Moves: ", tmp);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, str);
	free(str);
	free(tmp);
}