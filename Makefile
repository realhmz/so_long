NAME = so_long
MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
CFLAGS = -Wall -Wextra -Werror
SRC =	check_file_name_bonus.c\
		flood_fill_bonus.c\
		ft_split_bonus.c\
		game_bonus.c\
		libft_utils_bonus.c\
		move_bonus.c\
		parce_utils_bonus.c\
		parce_bonus.c\
		so_long_bonus.c\
		utils_bonus.c\
		animation_bonus.c\
		background_bonus.c\
		tiles_bonus.c\
		assets_bonus.c\
		move_utils_bonus.c\
		game_utils_bonus.c\
		ft_itoa_bonus.c\
		enemy_bonus.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(MLX)

re : fclean all
fclean : clean
	rm -rf $(NAME)
clean :
	rm -rf $(OBJ)
debug :
	cc *.c -fsanitize=address -g3 -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o so_long