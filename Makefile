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

./a.outexport DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:/minilibx/
./a.out= get_next_line/*c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	$(CC)  $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)

re: fclean all