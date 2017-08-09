/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:27:38 by starrit           #+#    #+#             */
/*   Updated: 2017/08/09 19:37:54 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <string.h>
# include <stdbool.h>

# define MEM_SIZE (4*1024)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

# define REG_NUMBER 16
# define OPC_NUMBER 16
# define REG_SIZE 4

# define CYCLE_TO_DIE 1500
# define NBR_LIVE 21
# define CYCLE_DELTA 50
# define MAX_CHECKS 10

# define CHAMP_NAME 128
# define COMMENT_NAME 2048
# define EXEC_MAGIC_LENGHT 3

typedef struct			s_champ
{
	char				*name;
	char				*comment;
	size_t				ID;
	struct s_champ		*next;
	bool				alive;
}						t_champ;

/*
** int live : nombre d'instruction live pour calculer la decrementation
*/

typedef struct			s_process
{
	size_t				ID;
	unsigned char		registres[REG_NUMBER];
	size_t				PC;
	size_t				startpos;
	size_t				next_jump;
	size_t				cycles_before_execute;
	bool				*next_op;
	bool				carry;
	size_t				live;
	struct s_process	*next;
}						t_process;

/*
** char *last_champ_alive : dernier champion rapporte en vie
** t_process **process: liste chainee des processus
** t_champ **champs : tableau des champions
** int checks : compteur de verifications de cycle_to_die
** int total_cycle : nombre de cycle total pour les option d'affichage tous les
** N cycles (modulo)
**
**	arena_color :	1 : no color
**					4 a 9 : color correspondant a COLOR_PAIR du champ
**					14 a 19 : color correspondant a COLOR_PAIR du champ + fond (new written process)
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
	unsigned char		arena[MEM_SIZE];
	int					arena_color[MEM_SIZE];
}						t_cor;

void		ft_browseprocess(t_cor *core);
void		usage(void);
void		write_error(int nb);
int			**parse(t_cor *cor, char *av);
void		init_struct(t_cor *cor);
void		visu(t_cor *env);
void		ft_warcycle(t_cor *core);

#endif
