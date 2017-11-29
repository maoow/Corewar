/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: starrit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:27:38 by starrit           #+#    #+#             */
/*   Updated: 2017/11/29 19:08:29 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "ft_printf.h"
# include <math.h>
# include <fcntl.h>
# include <ncurses.h>

# define MAX_PLAYERS 4
# define MEM_SIZE (4*1024)
# define IDX_MOD (MEM_SIZE / 8)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)

# define T_REG					1
# define T_DIR					2
# define T_IND					4

# define REG_NUMBER 16
# define OPC_NUMBER 16
# define REG_SIZE 4

# define CYCLE_TO_DIE 1536
# define NBR_LIVE 21
# define CYCLE_DELTA 50
# define MAX_CHECKS 10

# define CHAMP_NAME 128 + 8
# define COMMENT_NAME 2048 + CHAMP_NAME + 8
# define EXEC_MAGIC_LENGHT 3
# define MAGIC_PACKET 0xea83f3

/*
**	structure allouee et remplie si un ou plusieurs champions a un numero
**	assigne au lancement de l'executable
*/

typedef struct			s_opt_number
{
	int					num;
	size_t				champ;
	struct s_opt_number	*next;
}						t_opt_number;

/*
**	structure remplie en fonction des options passees a l'executable
**	dump et son size_t pour afficher l'etat de la vm a un cycle donne
**	n et num_champ pour assigner un numero precis a un champion
**	v4 pour le verbose details des operations
**	visu pour le visualisateur ncurses
**	follow pour follow un processus precis sur le visu
**	aff_visu pour n'afficher le visu qu'a partir d'un certain moment
*/

typedef struct			s_options
{
	bool				dump;
	size_t				nb_dump;
	t_opt_number		*num_champ;
	bool				s;
	bool				v16;
	bool				v4;
	bool				v2;
	bool				reg;
	bool				visu;
	bool				fast;
	bool				follow;
	int					nb_follow;
	int					aff_visu;
}						t_options;

typedef struct			s_champ
{
	char				*name;
	char				*comment;
	long int			id;
	struct s_champ		*next;
	bool				alive;
	size_t				last_live;
	size_t				lives_in_period;
	size_t				weight;
	int					color;
}						t_champ;

/*
** int live : nombre d'instruction live pour calculer la decrementation
*/

typedef struct			s_process
{
	int					id;
	int					registres[REG_NUMBER];
	size_t				pc;
	size_t				startpos;
	size_t				next_jump;
	size_t				cycles_before_execute;
	bool				(*next_op)();
	bool				carry;
	bool				just_played;
	size_t				live;
	struct s_process	*next;
	int					color;
	size_t				buffc;
	char				buff[128];
}						t_process;

/*
** char *last_champ_alive : dernier champion rapporte en vie
** t_process **process: liste chainee des processus
** t_champ **champs : tableau des champions
** t_opt_number *id_list : list des numero optionnels de champions
** int checks : compteur de verifications de cycle_to_die
** int total_cycle : nombre de cycle total pour les option d'affichage tous les
** N cycles (modulo)
**
**	arena_color :	1 : no color
**					4 a 9 : color correspondant a COLOR_PAIR du champ
**					14 a 19 : color correspondant a COLOR_PAIR du champ +
**								fond (new written process)
**					24 a 29 : color d'ecriture des processus. temporaire
*/

typedef struct			s_cor
{
	t_champ				*champs;
	t_process			*process;
	t_options			*options;
	t_opt_number		*id_list;
	long int			last_champ_alive;
	int					cycle_to_die;
	int					tmp_cycle_to_die;
	size_t				checks;
	int					total_cycle;
	unsigned char		arena[MEM_SIZE];
	int					arena_color[MEM_SIZE];
	bool				verbose;
	size_t				nb_champs;
	size_t				procnb;
	bool				error;
}						t_cor;

/*
**						START FUNCTIONS
*/
void					usage(int ac, char **av);
void					intro(t_cor *cor, t_champ *champs);
void					write_error(int nb);
void					ft_init(t_cor *core);
size_t					get_options(t_cor *cor, int ac, char **av, size_t i);
int						**parse(t_cor *cor, char *av, int optionnal_id);
void					get_magic_packet(size_t s, unsigned char *buf,
		bool *end);
bool					is_champ(char *av, size_t *nb_champ, bool test, int j);
void					add_champ(t_cor *cor, char *name, char *comment,
		int id);
void					add_process(t_cor *cor, size_t startpos);
void					visu(t_cor *cor);
void					print_right(WINDOW *right, t_cor *cor, int i,
		t_champ *tmp);
void					print_left(WINDOW *left, t_cor *cor, size_t col,
		size_t lign);
void					ft_dump(t_cor *cor);
void					ft_clean(t_cor *cor);
/*
**						GAME FUNCTIONS
*/

size_t					revgetop(bool (*op)());
void					ft_warcycle(t_cor *core, bool b_alive);
void					ft_increase_cycle(t_cor *core);
void					ft_browseprocess(t_cor *core);
long int				idx(t_process *proc, long int jump);
void					ft_determinejmpdist(t_cor *core, t_process *proc);
size_t					ind(t_cor *core, t_process *proc, size_t pc);
size_t					indx(t_cor *core, t_process *proc, size_t pc);
int						getparam(t_cor *core, t_process *proc, size_t param,
		size_t label);
size_t					getparamplace(t_cor *core, t_process *proc,
		size_t param, size_t label);
size_t					*ft_getparamstype(t_cor *core, t_process *proc);
long int				getram(t_cor *core, size_t address);
void					setram(t_cor *core, size_t address, int value,
		int color);
void					free_process(t_process *tmp);
void					ft_delprocess(t_cor *core, t_process **del);
void					ft_addprocess(t_cor *core, t_process *new);
void					ft_getop(t_cor *core, t_process *proc, int first);
void					dispreg(t_process *proc);
void					dispjump(t_cor *core, t_process *proc);
bool					ft_checkexecutable(t_cor *core, t_process *proc);
bool					ft_checkloadable(t_cor *core, t_process *proc);
size_t					get_paramnb(size_t opc);
bool					hasopcode(size_t op);
size_t					getlabel(size_t op);
bool					checkopn(t_cor *core, t_process *proc);

#endif
