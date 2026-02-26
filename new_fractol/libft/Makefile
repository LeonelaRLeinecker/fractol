# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleineck <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:08:13 by lleineck          #+#    #+#              #
#    Updated: 2025/05/07 20:18:52 by lleineck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#defino 
#variables 
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

#recursos/funciones: 
SRC = ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strchr.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_tolower.c \
ft_toupper.c \
ft_memchr.c \
ft_memcmp.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c

#recursos/funciones del bounus:
BONUS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c

#transformo mis TODOS (%)recursos a ejecutable de tipo .o
OBJ = $(SRC:%.c=%.o)

#transformo mis TODOS BONUS (%)recursos a ejecutable de tipo .o 
OBJ_BONUS = $(BONUS:%.c=%.o)
#defino libreria a incluir

INCLUDE = libft.h

# hago mi librerias
AR = ar rcs

# variable de limpieza
RM = rm -f

#declaro la estructura 

all : $(NAME)

$(NAME) : $(OBJ) 
	$(AR) $(NAME) $(OBJ)

#estructura para bonus
bonus : $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS)

# #hacer files de tipo .o
#  $(OBJ) : $(BONUS)
#   	$(CC) $(CFLAGS) -c $^ -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#limpiar objetos 
clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

#limpiar libreria 
fclean: clean
	$(RM) $(NAME)

#comando de reinicio
re: fclean all

#defino llamadas del make
.PHONY: all bonus clean fclean re


