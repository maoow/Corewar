# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/27 12:28:21 by vkim              #+#    #+#              #
#    Updated: 2017/11/20 15:23:47 by vkim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=asm
COMPIL=gcc -g -Wall -Wextra -Werror
INC= -I ../includes/ -I ../libft/includes -I ../ressources/

N_SRC=ft_loading.c \
	  ft_name_comment.c \
	  ft_clean_load.c \
	  ft_init_ref.c \
	  ft_save_op.c \
	  ft_aux.c \
	  ft_check_args.c \
	  ft_dir_ind.c \
	  ft_len_mem.c \
	  ft_err_load.c \
	  ft_lex_err.c \
	  ft_is_char.c \
	  ft_name_comm_err.c \
	  ft_watzis.c \
	  ft_err_aux.c \
	  ft_search_syntax.c \
	  ft_syn_A.c \
	  ft_syn_name_comm.c \
	  ft_syn_op.c \
	  ft_syn_low_ac.c \
	  ft_put_syn_lbl.c \
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
