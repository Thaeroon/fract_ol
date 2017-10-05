# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmuller <nmuller@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:48:28 by nmuller           #+#    #+#              #
#    Updated: 2017/10/05 16:33:38 by nmuller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


##############
# PARAMETERS #
##############

# directories
LIB_PATH = lib
SRC_PATH = src
OBJ_PATH = obj


# compiler flags
CC = clang
CFLAGS = -Werror -Wall -Wextra -Iinc
LFLAGS = -I $(LIB_PATH)/libft/inc -I $(LIB_PATH)/miniLibX11/includes

# linker flags
LKFLAGS =  -Llib/miniLibX11 -lmlx -lXext -lX11 \
			-Llib/libft -lft -lm

# libs
LIB = $(LIB_PATH)/libft/libft.a $(LIB_PATH)/miniLibX11/libmlx.a

# files
SRC_FILES =	main.c display.c input.c mandelbrot.c julia.c ship.c tree.c

# executable name
NAME = fract_ol

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
	@make -C $(LIB_PATH)/miniLibX11

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
	@make clean -C $(LIB_PATH)/miniLibX11

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
