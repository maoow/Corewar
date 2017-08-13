# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: starrit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/13 12:23:50 by starrit           #+#    #+#              #
#    Updated: 2017/08/13 16:20:46 by starrit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS = srcs/main.c srcs/parse.c srcs/init.c srcs/visu.c srcs/usage.c srcs/visu_2.c
OBJS = *.o

all: lib $(NAME)

$(NAME):  
	gcc -lncurses -Wall -Wextra -Werror -iquote includes -iquote libft/includes libft/libftprintf.a $(SRCS) -o $(NAME)

.PHONY:lib
lib:
	@make -C libft
	
.PHONY:clean
clean:
#	@make clean -C libft
	@rm -rf *.o

fclean: clean
#	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean
	make
