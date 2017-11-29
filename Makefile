# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: starrit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/13 12:23:50 by starrit           #+#    #+#              #
#    Updated: 2017/11/29 17:17:10 by starrit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1=asm
NAME2=corewar

all:
	make -C asm
	make -C corewar

.PHONY:asm
asm: 
	make -C $(NAME1)

.PHONY:corewar
corewar: 
	make -C $(NAME2)

.PHONY:clean
clean:
	@make clean -C asm
	@make clean -C corewar
	@rm -rf $(OBJ_PATH)
	@echo "\033[31mObjects files removed.\033[0m"

fclean: clean
	@make fclean -C asm
	@make fclean -C corewar
	@rm -rf $(NAME)
	@echo "\033[31mBinary names removed.\033[0m"

re: fclean
	make
