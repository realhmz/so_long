/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: het-taja <het-taja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:54:14 by het-taja          #+#    #+#             */
/*   Updated: 2024/07/15 22:26:01 by het-taja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		line_len;
	int		endian;
	void	*win;
}	t_img;

typedef struct s_assets
{
	t_img		*player;
	t_img		*playerl;
	t_img		*e;
	t_img		*idle;
	t_img		*coin_idle;
	t_img		*coin;
	t_img		wall;
	t_img		wall2;
	t_img		floor;
	t_img		door;
	t_img		enemy;

}				t_assets;

typedef struct s_coin
{
	int	is_collected;
	int	x;
	int	y;
}	t_coin;

typedef struct s_game
{
	t_assets	*asset;
	t_coin		coin;
	char		**map;
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			playerx;
	int			playery;
	int			c;
	int			moves;
	int			win_h;
	int			win_w;
	int			ex;
	int			ey;
	int			en_x;
	int			en_y;
	int			last_x;
	int			last_y;
	int			enemy;
	float		gravity;
	int			player_stat;
	t_img		back_img;
	t_img		base;
	int			is_jump;
	char		**enemy_map;
}				t_game;

int				ft_strlen(char *str);
char			*ft_strdup(char *s);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			**ft_split(char const *s, char c);
void			player_pos(t_game *game);
int				ft_count_char(char **str, char c);
int				parce_map(char **str);
int				read_map(t_game *game, char *map);
void			player_pos(t_game *game);
int				map_walls(t_game *game);
void			exit_pos(t_game *game);
int				error(t_game *game);
int				parcing(t_game *game, char *map);
int				count_newline(char *str, char **map);
void			render(t_game *game, t_assets *assets);
void			load_it(int x, int y, t_game *game, t_assets *assets);
void			calc_win(t_game *game);
int				game_assets(t_assets *assets, t_game *game);
int				start_game(t_game *game);
int				move(int keycode, t_game *game);
void			right(t_game *game);
void			left(t_game *game);
void			up(t_game *game);
void			down(t_game *game);
void			ft_put(t_game *game, t_img img, int x, int y);
void			print_moves(t_game *game);
int				win(t_game *game);
void			clear_map(char **map);
int				flood_fill(t_game *game);
int				check_fill(char **map, char c);
void			check_path(int x, int y, char **map, char c);
char			**map_dup(char **map);
void			check_path_exit(int x, int y, char **map, char c);
int				map_name(char *map);
void			player_pos_real(t_game *game);
int				collition(t_game *game, int py, int px);
void			jump(t_game *game);
int				check_collision(int y, int x, int py, int px);
int				gravity(t_game *game);
int				check_door_collision(int y, int x, int py, int px);
int				idle(t_game *game);
int				playerstat(int keycode, t_game *game);
int				backimg(t_game *game);
void			player_assets(t_game *game);
void			put_pixel_img(t_img img, int x, int y, int color);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
unsigned int	get_pixel_img(t_img img, int x, int y);
t_img			new_img(int w, int h, t_game *window);
t_img			new_file_img(char *path, t_game *window);
unsigned int	get_pixel_img(t_img img, int x, int y);
void			put_img_to_img(t_img dst, t_img src, int x, int y);
int				wich_edge(t_game *game, int x, int y);
void			put_edge(t_game *game, t_img *e, int x, int y);
void			edge_assets(t_game *game);
void			coin_assets(t_game *game);
void			put_coin(t_game *game);
char			*ft_itoa(int n);
void			patrol(t_game *game);
int				put_enemy(t_game *game);

#endif
