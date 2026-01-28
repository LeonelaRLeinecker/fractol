NAME : fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
SCRCS =  main.c \
		 init.c \
		 render.c \
		 complex.c \
		 events.c \
		 color.c \

OBJS = $(SCRCS:.c=.o)

all: $(NAME)
