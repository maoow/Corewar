# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: starrit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/13 12:23:50 by starrit           #+#    #+#              #
#    Updated: 2017/10/09 10:21:29 by cbinet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -iquote includes -iquote $(LIB_PATH)$(INC)
OPTIONS = -lncurses

SRC_PATH = srcs/
SRC_NAME = add_champ_process.c						\
		   init.c									\
		   cyclemanage.c									\
		   main.c									\
		   paramsmanage.c							\
		   parse.c									\
		   processmanage.c							\
		   jump.c									\
		   ramfunctions.c							\
		   usage.c									\
		   visu.c									\
		   visu_2.c									\
		   warcycle.c								\
		   operations/add.c							\
		   operations/aff.c							\
		   operations/and.c							\
		   operations/fork.c						\
		   operations/ld.c							\
		   operations/ldi.c							\
		   operations/lfork.c						\
		   operations/live.c						\
		   operations/lld.c							\
		   operations/lldi.c						\
		   operations/or.c							\
		   operations/st.c							\
		   operations/sti.c							\
		   operations/sub.c							\
		   operations/xor.c							\
		   operations/zjmp.c						\
		   options.c 

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
SRCS = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = includes/
LIB_PATH := libft/
LIB := $(LIB_PATH)libftprintf.a
LIB_INCLUDE := $(LIB_PATH)$(INC)libft.h			\
				$(LIB_PATH)$(INC)get_next_line.h\
				$(LIB_PATH)$(INC)ft_printf.h
HEADER := $(LIB_INCLUDE)						\
		 includes/corewar.h

all: lib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OPTIONS) $(OBJS) $(LIB) -o $(NAME)
	@echo "\033[32m$(NAME) udpated\033[0m"

.PHONY:lib
lib:
	@make -C libft
	
$(OBJS): | $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir -p $@
	@mkdir -p $@/operations

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) $(LIB)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY:clean
clean:
	@make clean -C libft
	@rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files removed.\033[0m"

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@echo "\033[31mBinary names removed.\033[0m"

re: fclean
	make
