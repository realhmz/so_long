/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 21:17:27 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 21:22:46 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static	char	*ft_isnegative(long n, int lenth)
{
	char	*str;

	if (n == 0)
	{
		str = malloc(sizeof(char) * 2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	n *= -1;
	str = (char *)malloc(sizeof(char) * lenth + 1);
	if (!str)
		return (NULL);
	str[0] = '-';
	str[lenth] = '\0';
	lenth--;
	while (n)
	{
		str[lenth] = n % 10 + 48;
		n = n / 10;
		lenth--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		lenth;
	char	*str;

	lenth = ft_count(n);
	if (n <= 0)
		return (ft_isnegative((long)n, lenth));
	str = malloc((sizeof(char) * lenth) + 1);
	if (!str)
		return (NULL);
	str[lenth] = '\0';
	lenth--;
	while (n)
	{
		str[lenth] = n % 10 + 48;
		n = n / 10;
		lenth--;
	}
	return (str);
}
