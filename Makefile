CC := gcc

CFLAGS := -Wall -Wextra 
NAME = so_long
SOURCE :=	./source/check_map.c \
			./source/ft_split.c \
			./source/ft_strchr.c \
			./source/ft_strlcpy.c \
			./source/get_next_line.c \
			./source/get_next_line_utils.c \
			./source/handel.c \
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
			./source/moves.c\
			./source/so_long.c\
			./source/menu.c\
			./source/idle.c\
			./source/bar.c\
			
OBJ = $(SOURCE:.c=.o)
MLX :=  -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
