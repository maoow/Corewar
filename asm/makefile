# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/27 12:28:21 by vkim              #+#    #+#              #
#    Updated: 2017/09/04 15:39:52 by vkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=asm
COMPIL=gcc -g -Wall -Wextra -Werror
INC= -I ../includes/ -I ../libft/includes

N_SRC=ft_loading.c \
	  main.c \

P_SRC = .

SRC=$(addprefix $(P_SRC)/,$(N_SRC))

OBJ = $(N_SRC:.c=.o)

all: $(NAME)
$(NAME): $(SRC)
	@cd ../libft && $(MAKE)
	@echo "OK LIB"
	@$(COMPIL) $(INC) -c $(SRC)
	@echo "OK OBJ"
	@$(COMPIL) $(INC) $(OBJ) -L../libft -lftprintf -o $(NAME)
	@echo "OK ASM"

clean:
	@cd ../libft/ && make clean
	@echo "OK FCLEAN LIBFT"
	@rm -rf $(OBJ)
	@echo "OK CLEAN OBJ"

fclean: clean
	@cd ../libft/ && make fclean
	@echo "OK FCLEAN LIBFT"
	@rm -rf $(NAME)
	@echo "OK DEL $(NAME)"

re: fclean all
.PHONY: all, clean, fclean, re
