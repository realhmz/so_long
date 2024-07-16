/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:50:12 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 21:22:46 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_file_name(char *str)
{
	int	i;
	int	fd;

	fd = open(str, O_RDONLY);
	if (!fd || fd == -1)
		return (-1);
	i = ft_strlen(str);
	i--;
	if (str[i] != 'r' || str[i - 1] != 'e' || str[i - 2] != 'b'
		|| str[i - 3] != '.' || !fd || fd == -1)
		return (0);
	close(fd);
	return (1);
}
