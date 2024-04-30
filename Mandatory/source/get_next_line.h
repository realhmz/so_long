/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:46:34 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/26 13:31:13 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>
// # include "../minilibx-linux/mlx.h"
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif // BUFFER_SIZEπ

typedef struct s_assets
{
	void		*player;
	void		*playerl;
	void		*coin;
	void		*wall;
	void		*floor;
	void		*door;
	void		*open_door;
}				t_assets;

typedef struct s_game
{
		char		**map;
	void		*mlx;
	void		*win;
	int			winh;
	int			winw;
	int			x;
	int			y;
	int			a;
	int			b;
	int			playerx;
	int			playery;
	int			c;
	int			ex;
	int			ey;
	t_assets	*asset;
	int			moves;
	int			cnsty;
	int			cnstx;
}				t_game;

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

char			*get_next_line(int fd);
int				ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			**ft_split(char const *s, char c);
char			*ft_readmap(char *map_name);
char			**full_map(char *map);
char			*ft_strchr(char *s, int c);
int				check_map_name(char *str);
void			load_map(t_game *game);
int				key_hook(int keycode, t_game *game);
int				count_y(char **s);
void			put_player(t_game *game, t_assets *assets, int i);
void			print_map(char **map);
int				count_c(t_game *game);
int				check_lenth(char **map);
int				check_wall(char **map, char *full_map);
int				check_fill(t_game *game);
char			**ft_strdupdup(char **str);
void			player_pos(t_game *game);
int				free_leaks(t_game *game);
void			opendoor(t_game *game);
void			turn_right(t_game *game);
void			turn_left(t_game *game);
void			go_up(t_game *game);
void			go_down(t_game *game);
void			put_player(t_game *game, t_assets *assets, int i);
void			print_moves(t_game *game);
char			*ft_itoa(int n);
void			player_assets(t_game *game);
void			ft_free_map(t_game *game);
void			ft_free_assets(t_game *game);
void			lanch_game(t_game *game);
void			map_assets(t_game *game);
void			load_assets(t_game *game);
// void	ft_free(t_free **lst);
// void    remove_leaks(t_game *game);

#endif // GET_NEXT_LINE_H
