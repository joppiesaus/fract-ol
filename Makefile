# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jobvan-d <jobvan-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/31 13:54:12 by jobvan-d      #+#    #+#                  #
#    Updated: 2022/02/12 13:36:52 by jobvan-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
# SUPER TIP: Add -mtune=native -march=native -Ofast to make it much faster!
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj
DEPS = drawing.c fract_funcs.c ft_atod.c hooks.c libft_funcs.c main.c \
	translation.c util.c vec2.c
HEADERS = fract.h keys.h
OBJ = $(DEPS:%.c=$(OBJ_DIR)/%.o)

MLX_DIR = ./minilibx_opengl_20191021
MLX_A = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJ) $(MLX_A)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(MLX_DIR) -lmlx \
		-framework OpenGL -framework AppKit

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(MLX_DIR)

$(OBJ_DIR):
	mkdir $@

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) $^

bonus: $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean bonus re
