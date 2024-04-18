NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE :=	./source/check_map.c \
			./source/ft_split.c \
			./source/ft_strchr.c \
			./source/ft_strlcpy.c \
			./source/get_next_line.c \
			./source/get_next_line_utils.c \
			./source/so_long.c \
			./source/render.c \
			./source/player.c \
			./source/fill.c \
			./source/map_edges.c\
			./source/algo.c\
			./source/animat.c\
			./source/free.c\
			./source/sky.c\
			./source/audio.c\
			./source/ft_itoa.c\
			./source/enemy.c\
			


./a.outexport DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:/minilibx/
./a.out= get_next_line/*c
LIBRARY :=  -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/
SANITIZE := -fsanitize=address -g
all:
	$(CC) -Wall -Wextra  $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

dlinux:
		$(CC) $(SOURCE) -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz $(SANITIZE) -o $(NAME)
linux:
		$(CC) $(SOURCE) -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
debug:
		$(CC)  -Wall -Wextra $(SOURCE) $(LIBRARY) $(SANITIZE) -o $(NAME)
clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all
