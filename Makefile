NAME = so_long

SRCS = main.c \

OPENGL = -framework OpenGL -framework AppKit
MLX_LIB = ./mlx/libmlx.a
HDRS = headers

OBJS = $(SRCS:.c=.o)
# CFLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) :$(OBJS)
	make -C mlx
	gcc -L./mlx/ -lmlx $(OPENGL) -o $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)
	make -C mlx clean

fclean :
	make clean
	rm -f $(NAME)
	make -C mlx fclean

re :
	make fclean
	make all

.PHONY : clean fclean re all