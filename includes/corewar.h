/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:27:38 by starrit           #+#    #+#             */
/*   Updated: 2017/07/20 16:41:08 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define MEM_SIZE (4*1024)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

# define REG_NUMBER 16
# define REG_SIZE 4

# define CYCLE_TO_DIE 1500
# define NBR_LIVE 21
# define CYCLE_DELTA 50
# define MAX_CHECKS 10

typedef struct			s_champ
{
	char				*name;
	char				*comment;
	int					ID;
	struct s_champ		*next;
}						t_champ;

/*
** int *registres : size de REG_NUMBER
** int live : nombre d'instruction live pour calculer la decrementation
*/

typedef struct			s_process
{
	int					ID;
	int					*registres;
	int					PC;
	bool				carry;
	int					live;
	struct s_process	*next;
}						t_process

/*
** char *last_champ_alive : dernier champion rapporte en vie
** t_process **process: liste chainee des processus
** t_champ **champs : liste chainee des champions
** int checks : compteur de verifications de cycle_to_die
*/

typedef struct			s_cor
{
	t_champ				*champs;
	t_process			*process;
	char				*last_champ_alive;
	int					checks;
}						t_cor;

#endif
