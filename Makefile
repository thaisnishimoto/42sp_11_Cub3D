# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 17:44:33 by tmina-ni          #+#    #+#              #
#    Updated: 2024/07/25 12:18:25 by tmina-ni         ###   ########.fr        #
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
SRC_BONUS_PATH = ./src_bonus
HEADERS	:= -I ./include -I $(LIBFT_PATH)/inc -I ./MLX42/include/MLX42

#================================FILES=========================================#

NAME = cub3D
BONUS_NAME = cub3D_bonus
LIBFT = $(LIBFT_PATH)/libft.a
LIBMLX = $(MLX_PATH)/libmlx42.a

SRC = src/main.c \
	$(addprefix src/validate_file/, validate_file_1.c validate_file_2.c validate_file_3.c validate_file_4.c validate_file_utils1.c validate_file_utils2.c load_file.c load_player.c) \
	$(addprefix src/parser/, parser.c get_textures.c get_colors.c get_map_layout.c get_player_pos.c) \
	$(addprefix src/run_game/, run_game.c create_images.c) \
	$(addprefix src/actions/, hook_functions.c move.c) \
	$(addprefix src/draw/, playerview.c raycast_walls.c texture_walls.c) \
	$(addprefix src/end_game/, end_game.c)
OBJ = $(SRC:.c=.o)

BONUS_FILES = main.c \
	$(addprefix validate_file/, validate_file_1.c validate_file_2.c validate_file_3.c validate_file_4.c validate_file_utils1.c validate_file_utils2.c load_file.c load_player.c) \
	$(addprefix parser/, parser.c get_textures.c get_colors.c get_map_layout.c get_player_pos.c) \
	$(addprefix run_game/, run_game.c create_images.c) \
	$(addprefix actions/, hook_functions.c move.c shoot.c) \
	$(addprefix draw/, playerview.c raycast_walls.c texture_walls.c minimap.c) \
	$(addprefix end_game/, end_game.c)
SRC_BONUS = $(addprefix src_bonus/, $(addsuffix _bonus.c, $(basename $(BONUS_FILES))))
OBJ_BONUS = $(SRC_BONUS:.c=.o)

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

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(LIBMLX) $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ_BONUS) $(LIBFT_FLAG) $(MLX_FLAG)

$(SRC_BONUS_PATH)/%.o: $(SRC_BONUS_PATH)/%.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

leak: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=mlx42.supp ./$(NAME) $(MAP)

#================================CLEAN=========================================#

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE_NO_PRINT) clean -C $(LIBFT_PATH)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE_NO_PRINT) fclean -C $(LIBFT_PATH)

re: fclean all

rebonus: fclean bonus

mlxfclean:
	rm -rf $(MLX_PATH)

.PHONY: all clean fclean re libft libmlx
