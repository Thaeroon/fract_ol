# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:48:28 by nmuller           #+#    #+#              #
#    Updated: 2017/10/09 17:02:23 by nmuller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##############
# PARAMETERS #
##############

# directories
LIB_PATH = .
SRC_PATH = src
OBJ_PATH = obj


# compiler flags
CC = clang
CFLAGS = -Werror -Wall -Wextra -Iinc
LFLAGS = -I $(LIB_PATH)/libft/inc -I $(LIB_PATH)/minilibx_macos

# linker flags
LKFLAGS =  -L$(LIB_PATH)/minilibx_macos -lmlx -framework OpenGL -framework AppKit \
			-L$(LIB_PATH)/libft -lft -lm

# libs
LIB = $(LIB_PATH)/libft/libft.a $(LIB_PATH)/minilibx_macos/libmlx.a

# files
SRC_FILES =	main.c input.c display.c mandelbrot.c julia.c ship.c tree.c

# executable name
NAME = fractol

##############
# PROCESSING #
##############

# variables
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_FILES))

# rules
.PHONY: clean fclean re norme lib fcleanall
all: lib $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) -o $(NAME) $(LKFLAGS)

lib:
	@make -C $(LIB_PATH)/libft
	@make -C $(LIB_PATH)/minilibx_macos

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	@rmdir -v $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(NAME)

fcleanall: fclean
	@make fclean -C $(LIB_PATH)/libft
	@make clean -C $(LIB_PATH)/minilibx_macos

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
