/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:49:06 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/18 14:53:14 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_new_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
static char	*ft_rest(char *rest)
{
	char	*temp;
	int		i;

	if (!rest)
		return (NULL);
	i = find_new_line(rest);
	if (i != -1)
	{
		temp = ft_strdup(rest + i + 1);
		free(rest);
		rest = temp;
		return (rest);
	}
	free(rest);
	return (NULL);
}
static char	*ft_line(char *rest)
{
	char	*line;
	int		i;
	int		ind;

	i = 0;
	if (ft_strlen(rest) <= 0)
		return (NULL);
	ind = find_new_line(rest);
	if (ind == -1)
	{
		line = ft_strdup(rest);
		return (line);
	}
	line = malloc(sizeof(char) * ind + 2);
	if (!line)
		return (NULL);
	while (rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}
static char	*ft_read(int fd, char *buff, char *rest)
{
	char	*temp;
	int		i;

	i = 1;
	while (i > 0 && find_new_line(rest) == -1)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i > 0)
		{
			buff[i] = '\0';
			temp = ft_strjoin(rest, buff);
			free(rest);
			rest = temp;
		}
	}
	free(buff);
	buff = NULL;
	if (i == -1)
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}
char	*get_next_line(int fd)
{
	static char	*rest[OPEN_MAX];
	char		*line;
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rest[fd] = ft_read(fd, buff, rest[fd]);
	line = ft_line(rest[fd]);
	rest[fd] = ft_rest(rest[fd]);
	return (line);
}
// int main(int ac , char **av)
// {
// 	int fd = open(av[1], O_RDONLY);
// 	char *str = get_next_line(fd);
// 	printf("%s",str);
// }
