# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkarlon- <lkarlon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/04 18:07:03 by chermist          #+#    #+#              #
#    Updated: 2019/10/30 21:03:59 by lkarlon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc -g

INCDIR = -I libft/includes -I ./inc

LIBDIR = -L ./libft -L minilibx_macos

OBJDIR = ./obj

LIBNAME = libft/libft.a

LIB = -lft -lmlx

CFLAGS = $(INCDIR) -Wall -Werror -Wextra

SRCDIR = ./src

FW = -framework OpenGL -framework AppKit

SRC = 	fractol.c \
		inits.c \
		support.c \
	  	mandelbrot.c \
		keys.c \
		julia.c \
		burning_ship.c


OBJ = $(SRC:.c=.o)

vpath %.c $(SRCDIR)

all: DEPS $(NAME)

#$(OBJ_DIR):
#	@mkdir -p $(OBJ_DIR)

$(NAME):  $(OBJ) $(LIBNAME)
	@echo "\033[35mCompiling ./fractol\033[0m"
	@$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) $(LIB) $(FW) $(OBJ) -o $@
	@echo "\033[1;32m./fractol was built\033[0m"

DEPS:
	@make -C libft/

$(LIBNAME):
	@make -C libft/

%.o: %.c %.h

clean:
	@make -C libft $@
	@rm -f $(OBJ)
	@echo "\033[3;36mProject cleaned\033[0m"

fclean: clean
	@make -C libft $@
	@ rm -f $(NAME)
	@echo "\033[3;36mProject fully cleaned\033[0m"

re: fclean all

norm:
	@norminette src/*

.PHONY: all clean fclean re norm
