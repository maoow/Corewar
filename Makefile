# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: starrit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/13 12:23:50 by starrit           #+#    #+#              #
#    Updated: 2017/09/02 14:13:38 by cbinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS = srcs/init.c  srcs/main.c srcs/paramsmanage.c srcs/parse.c srcs/processmanage.c srcs/jump.c srcs/ramfunctions.c srcs/usage.c srcs/visu.c srcs/visu_2.c srcs/warcycle.c srcs/operations/add.c srcs/operations/aff.c srcs/operations/and.c srcs/operations/fork.c srcs/operations/ld.c srcs/operations/ldi.c srcs/operations/lfork.c srcs/operations/live.c srcs/operations/lld.c srcs/operations/lldi.c srcs/operations/or.c srcs/operations/st.c srcs/operations/sti.c srcs/operations/sub.c srcs/operations/xor.c srcs/operations/zjmp.c srcs/options.c srcs/get_functions.c

OBJS = *.o

all: lib $(NAME)

$(NAME):  
	gcc -lncurses -g -Wall -Wextra -Werror -iquote includes -iquote libft/includes libft/libftprintf.a $(SRCS) -o $(NAME)

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
