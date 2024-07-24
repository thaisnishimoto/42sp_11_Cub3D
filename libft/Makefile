# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 17:25:13 by mchamma           #+#    #+#              #
#    Updated: 2024/07/16 16:57:25 by mchamma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a
FLAGS = -Werror -Wextra -Wall -g3

SRC_DIR = src/
OBJ_DIR = obj/

SRC = $(wildcard $(SRC_DIR)*.c)
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

INC = -I inc/
LIB = $(NAME)

#--------------------//-------------------#

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(LIB) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(dir $@)
	cc $(FLAGS) $(INC) -c $< -o $@

#--------------------//-------------------#

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
	make clean

#--------------------//-------------------#

.PHONY: all bonus clean fclean re run

#--------------------//-------------------#

# Compile individual file
# In root: cc -Werror -Wextra -Wall -g -I ./inc ./src/file.c -L. -lft &&  ./a.out
# In ./src: cc -Werror -Wextra -Wall -g -I ../inc file.c -L.. -lft && ./a.out