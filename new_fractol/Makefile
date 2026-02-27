# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleineck <lleineck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/27 17:24:05 by lleineck          #+#    #+#              #
#    Updated: 2026/02/27 19:17:29 by lleineck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fractol
NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iinclude -Ilibft -I"v2.4.2 source code/codam-coding-college-MLX42-2e33759/include"
LDFLAGS = -Llibft -lft -L"v2.4.2 source code/codam-coding-college-MLX42-2e33759/build" -lmlx42 -ldl -lglfw -pthread -lm
SRC = main.c
OBJ = $(SRC:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR) all

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all


.PHONY: all clean fclean re


