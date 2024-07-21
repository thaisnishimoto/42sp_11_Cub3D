# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 17:44:33 by tmina-ni          #+#    #+#              #
#    Updated: 2024/07/20 21:47:42 by tmina-ni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#================================FLAGS=========================================#

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -Wunreachable-code
LIBFT_FLAG = -L$(LIBFT_PATH) -lft
MLX_FLAG = -L$(MLX_PATH) -lmlx42 -ldl -lglfw -pthread -lm
MAKE_NO_PRINT = $(MAKE) --no-print-directory

#================================PATHS=========================================#

LIBFT_PATH = ./libft
MLX_PATH = ./MLX42/build
SRC_PATH = ./src
HEADERS	:= -I ./include -I $(LIBFT_PATH) -I ./MLX42/include/MLX42

#================================FILES=========================================#

NAME = cub3D
LIBFT = $(LIBFT_PATH)/libft.a
LIBMLX = $(MLX_PATH)/libmlx42.a
SRC = src/main.c \
	$(addprefix src/parser/, parser.c get_textures.c get_colors.c get_map_layout.c get_player_pos.c) \
	$(addprefix src/run_game/, run_game.c create_images.c) \
	$(addprefix src/actions/, hook_functions.c move.c shoot.c) \
	$(addprefix src/draw/, playerview.c raycast_walls.c texture_walls.c minimap.c) \
	$(addprefix src/end_game/, end_game.c)
OBJ = $(SRC:.c=.o)

#================================RULES=========================================#

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_FLAG) $(MLX_FLAG) 

$(LIBFT):
	$(MAKE_NO_PRINT) -C $(LIBFT_PATH)

$(LIBMLX):
	@cmake ./MLX42 -B $(MLX_PATH)
	@make -C $(MLX_PATH) -j4

$(SRC_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

leak: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=mlx42.supp ./$(NAME) $(MAP)

#================================CLEAN=========================================#

clean:
	rm -f $(OBJ)
	$(MAKE_NO_PRINT) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME)
	$(MAKE_NO_PRINT) fclean -C $(LIBFT_PATH)

re: fclean all

mlxfclean:
	rm -rf $(MLX_PATH)

.PHONY: all clean fclean re libft libmlx
