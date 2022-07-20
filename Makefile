# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jabae <jabae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 16:07:07 by jabae             #+#    #+#              #
#    Updated: 2022/07/20 13:56:57 by jabae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 

MLXFLAG = -L./mlx -lmlx -framework OpenGL -framework AppKit


SRCS = so_long.c \
		parsing.c \
		check_valid.c \
		draw_and_set_image.c \
		move.c 


OBJS = $(SRCS:.c=.o)

LIBFT = ./Libft

LIBFT_A = ./Libft/libft.a

MLX = ./mlx

MLX_LIB = ./mlx/libmlx.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_A) $(MLX_LIB)
			cp $(MLX_LIB) ./
			$(CC) $(CFLAGS) $(MLXFLAG) -L$(LIBFT) -lft $(OBJS) -o $@

$(LIBFT_A) : 
			make -C $(LIBFT)

$(MLX_LIB) : 
			make -C $(MLX)

clean : 
		rm -f $(OBJS)
		make clean -C $(MLX)
		make clean -C $(LIBFT)

fclean : clean
		rm -f $(NAME)
		rm -f ./libmlx.a
		make fclean -C $(LIBFT)

re : fclean all

.PHONY :
		all clean fclean re bonus
