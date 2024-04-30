/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:52:54 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/26 13:49:38 by het-taja         ###   ########.fr       */
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
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
void	print_moves(t_game *game)
{
	char	*tmp;

	tmp = ft_itoa(game->moves);
	ft_putstr("Moves : ");
	ft_putstr(tmp);
	write(1 , "\n", 1);
	free(tmp);
}