# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhaenys <rrhaenys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/30 19:01:08 by rrhaenys          #+#    #+#              #
#    Updated: 2019/02/05 06:43:44 by rrhaenys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARG=
V=
NAME1 = checker
NAME2 = push_swap
COMMAND = gcc
FLAGS = -Wall -Wextra #-Werror
SRC_DIR = src/
SRC_FIL = $(shell ls src | grep -E "ft_.+\.c")
SRCS = $(addprefix  $(SRC_DIR), $(SRC_FIL))
OBJ	= $(SRCS:.c=.o)
INCLUDE = -I libft/src -I includes -Iminilibx_macos
MLX = -framework OpenCL -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit
LIB = ./libft/libft.a
SRC_CHECKER = src/main_checker.c
OBJ_CHECKER	= $(SRC_CHECKER:.c=.o)
SRC_PUSH_SWAP = src/main_push_swap.c
OBJ_PUSH_SWAP	= $(SRC_PUSH_SWAP:.c=.o)

all: $(LIB) $(NAME1) $(NAME2)

$(LIB):
	make -C libft

$(NAME1): $(OBJ_CHECKER) $(OBJ)
	$(COMMAND) -g -o $(NAME1) $(INCLUDE) $(OBJ) $(OBJ_CHECKER) $(LIB) $(MLX)

$(NAME2): $(OBJ_PUSH_SWAP) $(OBJ)
	$(COMMAND) -g -o $(NAME2) $(INCLUDE) $(OBJ) $(OBJ_PUSH_SWAP) $(LIB) $(MLX)

.c.o:
	$(COMMAND) $(FLAGS) $(INCLUDE) -g -c -o $@ $<

clean:
	make -C libft clean
	/bin/rm -f $(OBJ)
	/bin/rm -f $(OBJ_CHECKER)
	/bin/rm -f $(OBJ_PUSH_SWAP)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)

re: fclean all

t_c:
	./$(NAME1) $(V) $(ARG)

t_p:
	./$(NAME2) $(ARG)

t_pc:
	@./$(NAME2) $(ARG) | ./$(NAME1) $(V) $(ARG)
	@./$(NAME2) $(ARG) | wc -l

.PHONY: clean fclean all re
