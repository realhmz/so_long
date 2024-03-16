/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:46:34 by het-taja          #+#    #+#             */
/*   Updated: 2024/03/16 21:57:32 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif // BUFFER_SIZE


typedef struct	s_assets {
    void    *player;
    void    *coin;
    void    *wall;
    void    *floor;
    void    *door;
}				t_assets;

typedef struct	s_vars {
	char    **map;
    void    *mlx;
    void    *win;
	int     x;
    int     y;
    int     a;
    int     b;
    int     playerx;
    int     playery;
    t_assets    *asset;
}				t_vars;

#ifndef OPEN_MAX
#define OPEN_MAX 1024
#endif

char *get_next_line(int fd);
int	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char *ft_readmap(char *map_name);
char **full_map(char *map);
int check_wall(char **map, char *full_map);
char	*ft_strchr(char *s, int c);
int	check_map_name(char *str);
void load_map(t_vars *vars, t_assets *assets);
int	key_hook(int keycode, t_vars *vars);