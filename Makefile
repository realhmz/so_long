NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE :=	first.c \
			check_map.c \
			ft_split.c \
			ft_strchr.c \
			ft_strlcpy.c \
			get_next_line.c \
			get_next_line_utils.c \
			so_long.c \
			render.c \
			player.c \
			fill.c \
			map_edges.c\
			algo.c\
			animat.c\
			free.c\
			


./a.outexport DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:/minilibx/
./a.out= get_next_line/*c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/
SANITIZE := -fsanitize=address -g
all:
	make -C $(MINILIBX)
	$(CC) -Wall -Wextra  $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

dlinux:
		$(CC) $(SOURCE) -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz $(SANITIZE) -o $(NAME)
linux:
		$(CC) $(SOURCE) -Lmlx_linux -lmlx_Linux -L./minilibx-linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
debug:
		make -C $(MINILIBX)
		$(CC)  -Wall -Wextra $(SOURCE) $(GETNEXTLINE) $(LIBRARY) $(SANITIZE) -o $(NAME)
clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all
