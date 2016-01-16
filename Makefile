# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 17:12:41 by fhenri            #+#    #+#              #
#    Updated: 2016/01/16 11:06:56 by fhenri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

SRC_PATH = ./

OBJ_PATH =

INC_PATH = -I.

LIB_PATH = -L.

LIB_NAME =

//CFLAGS = -Wall -Wextra -Werror

CC = gcc 

SRC_NAME = fdf.c transmo.c

OBJ_NAME = $(SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LDFLAGS = $(LIB_PATH) $(LIB_NAME)


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		    $(CC) $(LD_FLAGS) $^ -o $@ -lmlx -framework OpenGL -framework AppKit libft/libft.a

$(OBJ_PATH)%.o: $(SRC_PATH)%.c 
		    $(CC) $(CFLAGS) $(INC_PATH)  -c $<

clean:
		    rm -f $(OBJ)

fclean: clean
		    rm -f $(NAME)

re: fclean all
