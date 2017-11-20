/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:26:08 by vkim              #+#    #+#             */
/*   Updated: 2017/11/20 16:51:32 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <libft.h>
# include <op.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h> //DEL END
typedef struct		s_instr
{
	int				mem_num;
	int				num;
	int				opc;
	char			reg[3];
	int				i_lbl_sz[2][3];
	unsigned int	ag_i4[3];
	unsigned short	ag_i2[3];
	char			*(ag_lbl[3]);
	char			*label;
}					t_instr;

typedef struct		s_ref
{
	char			*name;
	int				ac;
	unsigned int	tvar[3];
	int				mdf_c;
	int				lbl_sz;
}					t_ref;

typedef struct		s_asm
{
	int				n_ln;
	int				n_chr;
	int				strt_mem;
	int				ac;
	t_ref			ref[17];
	char			*syn[14];
	int				num_syn;
	char			*load;
	char			**lines;
	char			*name;
	char			*comment;
	int				len_mem;
	t_instr			*op;
	char			*mem;
}					t_asm;

/*
** 3 fonctions - ft_loading.c
*/
int					ft_loading(int ac, char **av, int index, t_asm *as);
int					ft_str_gnl(t_asm *as);

/*
** 2 fonction - ft_name_comment.c
*/
int					ft_name_comment_check(t_asm *as);

/*
** 4 fonctions - ft_clean_load.c
*/
int					ft_del_com(t_asm *as);
int					ft_del_space(t_asm *as);
void				ft_del_empty_lines(t_asm *as);

/*
** 5 fonctions - ft_init_ref.c
*/
void				ft_init_struct_ref_1(t_ref *ref);

/*
** 3 fonctions - ft_save_op.c
*/
int					ft_instr_check(t_asm *as);
int					ft_if_label(t_asm *as, int *i);
int					ft_del_labels(t_asm *as);

/*
** 4 fonctions - ft_aux.c
*/
void				ft_while_space(char *txt, int *i);
int					ft_if_op_ok(t_asm *as, char *op);
int					ft_check_lbl(t_asm *as);

/*
** x fonctions - ft_err_aux.c
*/
int					ft_max_len(t_asm *as);
int					ft_real_ln_chr(t_asm *as, int *i, int *j);
void				ft_putstr_token_num(int i, int j);

/*
**4 fonctions - ft_check_args.c
*/
int					ft_check_var(t_asm *as);

/*
** 3 fonctions - ft_dir_ind.c
*/
int					ft_dir_ind(t_asm *as, char *txt, int *i, t_instr *sv);

/*
** 3 fonctions ft_len_mem.c
*/
void				ft_mem_len(t_asm *as);

/*
** 4 fonction - ft_err_load.c
*/
int					ft_err_load(int ac, int fd, char *str);
int					ft_err_str_gnl(t_asm *as);

/*
** x fonction - ft_lex_err.c
*/
int					ft_put_lexerr(t_asm *as, int i, int j);
int					ft_lexical_err(t_asm *as, char **lines);
int					ft_check_command(char **lines, int i, int j, int nb);

/*
** 4 fonction - ft_is_char.c
*/
int					ft_is_lblchr(char c);
int					ft_is_lbl_o_dgt(char c);
int					ft_is_lex(char c);
int					ft_is_sep(char c);

/*
** x fonction - ft_name_comm_err.c
*/
int				ft_add_bkn(t_asm *as, int ln, int chr);
int				ft_put_syntax(t_asm *as, int i, int j);
int				ft_substract_char(t_asm *as, int ln, int chr);

/*
** 5 fonctions - ft_watzis.c
*/
int				ft_watzis(char *txt, int i);

/*
** x fonctions - ft_search_syntax.c
*/
void			ft_search_syntax(t_asm *as, int i, int j);

/*
** x fonctions - ft_syn_A.c
*/
void			ft_run_types(char *txt, int *j);
int				ft_jmp_lbl(t_asm *as, int i, int *j, int *lbl);
int				ft_syn_A(t_asm *as, int i);

/*
** x fonctions - ft_syn_name_comm.c
*/
int					ft_syn_name_comm(t_asm *as);

/*
** x fonctions - ft_syn_op.c
*/
int					ft_syn_op(t_asm *as, int i);
int					ft_syn_args(t_asm *as, int i);

/*
** x fonctions - ft_syn_low_ac.c
*/
int					ft_syn_low_ac(t_asm *as, int count_args, char *tmp);
void				ft_check_kills(t_asm *as, int i);

/*
** x fonctions - ft_put_syn_lbl.c
*/
int					ft_put_syn_lbl(t_asm *as, int i, int j);
#endif
