NAME : fractol
INCLUDE = fractol.h
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_D = ./minilibx-linux/	
RM = rm -rf


SCRCS =  main.c \
		 init.c \
		 render.c \
		 complex.c \
		 events.c \
		 color.c \

OBJS = $(SCRCS:.c=.o)

all: $(NAME)

run:
	@$(CC) $(FLAGS) -g $(SCRCS) $(FRACTOL_H) $(MLX) -Iinclude -lglfw -lm -o $(NAME)

%.o: %.c $(INCLUDE)
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re 

