NAME = fractol
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = man.c
OBJ = $(SRC: .c=.o)
INCLUDE = -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBFT_INC) $(LIBFT) -lmlx -lm -o $(NAME)

clean:
	rm -f $(OBJ)

flcean: clean
	rm -f $(NAME)

re: flcean all

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LIBFT_INC) $(LIBFT) -lmlx -lm -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re