/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:46:34 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/25 18:13:10 by het-taja         ###   ########.fr       */
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
	void		**player;
	void		**playerl;
	void		*coin;
	void		*wall;
	void		*floor;
	void		*door;
	void		*open_door;
	void		**sky;
	void		**enemyl;
	void		**enemyr;
	void		*button;
	void		*button1;

}				t_assets;

typedef struct s_sound
{
	char		*menu;
	char		*start;
	char		*walk;
	char		**kill;
	char		*open_door;
	char		**enemy;
	char		*end;

}				t_sound;

typedef struct s_game
{
	t_sound		*sound;
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
	int			enemyx;
	int			enemyy;
	int			c;
	int			ex;
	int			ey;
	t_assets	*asset;
	int			moves;
	void		**edges;
	int			cnsty;
	int			cnstx;
	int			player_moved;
	int			player_moved_left;
	int			enemy_moved;
	int			enemy_moved_left;
	int			game_stat;
	int			last_view;
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
int				wich_edge(t_game *game, int x, int y);
void			put_edge(t_game *game, void **e, int x, int y);
void			edge_assets(t_game *game, void **e);
int				free_leaks(t_game *game);
void			opendoor(t_game *game);
void			turn_right(t_game *game);
void			turn_left(t_game *game);
void			go_up(t_game *game);
void			go_down(t_game *game);
void			put_player(t_game *game, t_assets *assets, int i);
void			render_sky(t_game *game, t_assets *a);
void			sky(t_game *game, t_assets *a);
void			stop_audio(void);
void			print_moves(t_game *game);
char			*ft_itoa(int n);
void			player_assets(t_game *game);
void			enemy_assets(t_game *game, t_assets *a);
void			enemy_go_down(t_game *game);
void			enemy_go_up(t_game *game);
void			enemy_go_left(t_game *game);
void			enemy_go_right(t_game *game);
void			put_enemy(t_game *game, t_assets *a, int i);
void			enemy_attack(t_game *game);
void			play_enemy(t_sound *s);
void			play_kill(t_sound *s);
void			play_walk(void);
void			play_open_door(void);
void			play_song(void);
void			play_end(t_sound *s);
void			sound_assets(t_sound *s);
void			ft_free_edges(t_game *game);
void			ft_free_map(t_game *game);
void			ft_free_sound(t_game *game);
void			ft_free_enemy(t_game *game);
void			ft_free_sound(t_game *game);
void			ft_free_player(t_game *game);
int				mouse_hook(int hook, int x,int y,t_game *game);
void			ft_free_assets(t_game *game);
void			load_menu(t_game *game);
int				backimg(t_game *game);
void			lanch_game(t_game *game);
void			play_menu(void);
void			play_sus(void);
// void	ft_free(t_free **lst);
// void    remove_leaks(t_game *game);

#endif // GET_NEXT_LINE_H
