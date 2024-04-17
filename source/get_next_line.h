/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 15:46:34 by het-taja          #+#    #+#             */
/*   Updated: 2024/04/17 22:43:42 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
#include <time.h>
// # include "../minilibx-linux/mlx.h"
#include <mlx.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 100
#endif // BUFFER_SIZEπ


typedef struct	s_assets {
    void    **player;
    void    **playerl;
    void    *coin;
    void    *wall;
    void    *floor;
    void    *door;
    void    *open_door;
    void    **sky;
    void    **enemyl;
    void    **enemyr;

}				t_assets;



typedef struct	a_xpm {
    void    **a;

}				t_xpm;
typedef struct	s_sound
{
    char            **start;
    char            *walk;
    char            **kill;
    char            *open_door;
    char            **enemy;
    char            **end;

}				t_sound;
typedef struct	s_vars {
    t_sound *sound;
    char    **map;
    void    *mlx;
    void    *win;
    int     winh;
    int     winw;
    int     x;
    int     y;
    int     a;
    int     b;
    int     playerx;
    int     playery;
    int     enemyx;
    int     enemyy;
    int     c;
    int     ex;
    int     ey;
    t_xpm   *xpm;
    t_assets    *asset;
    int     moves;
    void     **edges;
    int     cnsty;
    int     cnstx;
    int     player_moved;
    int     player_moved_left;
    int    enemy_moved;
    int    enemy_moved_left;
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
char	*ft_strchr(char *s, int c);
int	check_map_name(char *str);
void load_map(t_vars *vars, t_assets *assets);
int	key_hook(int keycode, t_vars *vars);
int count_y(char **s);
void    put_player(t_vars *vars, t_assets *assets,int i);
void    print_map(char  **map);
int count_c(t_vars *v);
int check_lenth(char **map);
int check_wall(char **map, char *full_map);
int	check_fill(t_vars *va);
char **ft_strdupdup(char **str);
void	player_pos(t_vars *va);
int    wich_edge(t_vars *v,int x, int y);
void    put_edge(t_vars *v,void **e,int x,int y);
void    edge_assets(t_vars *v,void **e);
int free_leaks(t_vars *v);
void opendoor(t_vars *v);
void turn_right(t_vars *v);
void turn_left(t_vars *v);
void go_up(t_vars *v);
void go_down(t_vars *v);
void    put_player(t_vars *vars, t_assets *assets,int i);
void render_sky(t_vars *v, t_assets *a);
void sky(t_vars *v, t_assets *a);
void stop_audio();
void print_moves(t_vars *v);
char *ft_itoa(int n);
void player_assets(t_vars *v);
void enemy_assets(t_vars *v, t_assets *a);
void enemy_go_down(t_vars *v);
void    enemy_go_up(t_vars *v);
void    enemy_go_left(t_vars *v);
void    enemy_go_right(t_vars *v);
void    put_enemy(t_vars *v, t_assets *a, int i);
void enemy_attack(t_vars *v);
void play_enemy(t_sound *s);
void play_kill(t_sound *s);
void play_walk(t_sound *s);
void play_open_door(t_sound *s);
void play_song(t_sound *s);
void play_end(t_sound *s);
void sound_assets(t_sound *s);





#endif //GET_NEXT_LINE_H
