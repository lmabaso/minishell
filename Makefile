# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmabaso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/16 17:05:36 by lmabaso           #+#    #+#              #
#    Updated: 2017/09/16 22:25:00 by lmabaso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        =   minishell

SRC         =   main.c \
				ft_read_line.c \
				ft_cmd.c \
				cmd_loop.c  \
				ft_launch.c \
				gnl/get_next_line.c \
				ft_split_line.c \

OBJ         =   $(SRC:.c=.o)

INC         =   -I includes -I libft
LINK        =   -L gnl/libft -lft

FLAGS       =   $(CFLAGS)
CFLAGS      =   -Wall -Wextra -Werror -g3
P           =   -pedantic
EXTRAFLAGS  =   --analyze -Weverything -Wno-missing-prototypes  \
				-Qunused-arguments

CC          =   $(CLANG)
GCC         =   /usr/local/bin/gcc
CLANG       =   /usr/bin/clang
RM          =   /bin/rm -fv

all         :   $(NAME)

$(NAME)     :   $(OBJ)
	make -C gnl/libft
	$(CC) $(FLAGS) $(INC) $(LINK) $(OBJ) -o $(NAME)
clean       :
	make -C gnl/libft clean
	$(RM) $(OBJ)

fclean      :   clean
	make -C gnl/libft fclean
	$(RM) $(NAME)

re          :   fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

%.o         :   %.c
				$(CC) $(FLAGS) $(INC) -c $< -o $@
