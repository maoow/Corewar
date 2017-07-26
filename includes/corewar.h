/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:27:38 by starrit           #+#    #+#             */
/*   Updated: 2017/07/26 14:18:37 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define MEM_SIZE (4*1024)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

# define REG_NUMBER 16
# define OPC_NUMBER 16
# define REG_SIZE 4

# define CYCLE_TO_DIE 1500
# define NBR_LIVE 21
# define CYCLE_DELTA 50
# define MAX_CHECKS 10


typedef struct			s_champ
{
	char				*name;
	char				*comment;
	size_t				ID;
	struct s_champ		*next;
	bool				alive;
}						t_champ;

/*
** int *registres : size de REG_NUMBER
** int live : nombre d'instruction live pour calculer la decrementation
*/

typedef struct			s_process
{
	size_t				ID;

	// int					*registres;
	unsigned char		registres[REG_NUMBER];
	size_t				PC;
	size_t				next_jump;
	size_t				cycles_before_execute;
	bool				*next_op;
	bool				carry;
	size_t				live;
	struct s_process	*next;
}						t_process

/*
** char *last_champ_alive : dernier champion rapporte en vie
** t_process **process: liste chainee des processus
** t_champ **champs : tableau des champions
** int checks : compteur de verifications de cycle_to_die
** int total_cycle : nombre de cycle total pour les option d'affichage tous les
** N cycles (modulo)
*/

typedef struct			s_cor
{
	t_champ				*champs;
	t_process			*process;
	char				*last_champ_alive;
	size_t				cycle_to_die;
	size_t				tmp_cycle_to_die;
	size_t				checks;
	size_t				total_cycle;
	unsigned char		*arena;
}						t_cor;

void		ft_browseprocess(t_cor *core);
void		usage(void);
void		ft_warcycle(t_cor *core);

#endif
