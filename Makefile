NAME = fractol
INCLUDE = fractol.h
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_D = ./minilibx-linux
MLX = $(MLX_D)/libmlx.a
RM = rm -rf

SRCS = main.c \
       init.c \
       render.c \
       complex.c \
       events.c \
       color.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I$(MLX_D) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -lm -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

