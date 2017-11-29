# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/27 12:28:21 by vkim              #+#    #+#              #
#    Updated: 2017/11/29 17:13:56 by starrit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

NAME=asm
COMPIL=gcc -Wall -Wextra -Werror
CC= gcc -Wall -Wextra -Werror
INC= -I ../includes/ -I ../libft/includes 
INC2= ../includes/asm.h  ../libft/includes/libft.h ../includes/op.h

N_SRC=ft_loading.c \
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
	  ft_err_aux2.c \
	  ft_watzis.c \
	  ft_err_aux.c \
	  ft_search_syntax.c \
	  ft_syn_a.c \
	  ft_syn_name_comm.c \
	  ft_syn_op.c \
	  ft_syn_low_ac.c \
	  ft_put_syn_lbl.c \
	  ft_write_in_str.c \
	  ft_complete_space_n_opt2.c \
	  ft_option_a.c \
	  ft_output.c \
	  ft_syn_args.c \
	  ft_init_main.c \
	  ft_free_end.c \
	  ft_close_load_fd.c \
	  main.c \

P_SRC = .

SRC=$(addprefix $(P_SRC)/,$(N_SRC))

OBJ = $(N_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "OK OBJ"
	@make -C ../libft
	@echo "OK LIB"
	$(COMPIL) $(INC) $(OBJ) -L../libft -lftprintf -o $(NAME)
	@echo "OK ASM"

%.o: %.c $(INC2)
	$(CC) $(INC) -c $< -o $@

clean:
	@make clean -C ../libft
	@echo "OK CLEAN LIBFT"
	@rm -rf $(OBJ)
	@echo "OK CLEAN OBJ"

fclean: clean
	@make fclean -C ../libft
	@echo "OK FCLEAN LIBFT"
	@rm -rf $(NAME)
	@echo "OK DEL $(NAME)"

re: fclean
	make

.PHONY: all, clean, fclean, re
