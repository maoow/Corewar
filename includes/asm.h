/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:26:08 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 14:26:30 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <libft.h>
# include <op.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** ft_watzis :
** 01 ENDLINE
** 02 STRING
** 03 DIRECT_LABEL
** 04 DIRECT
** 05 INDIRECT_LABEL
** 06 SEPARATOR
** 07 CMD_COMMENT
** 08 CMD_NAME
** 09 INDIRECT
** 10 REGISTER
** 11 LABEL
** 12 INSTR
** 13 NULL
*/

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
	int				opt_a;
	char			*output;
}					t_asm;

/*
** 4 fonctions - ft_loading.c
*/
int					ft_loading(int ac, char **av, int *index, t_asm *as);
int					ft_str_gnl(t_asm *as);
int					ft_new_line(t_asm *as, int *nb_l, int i, int j);

/*
** 2 fonctions - ft_clean_load.c
*/
int					ft_del_com(t_asm *as);
int					ft_del_space(t_asm *as);

/*
** 5 fonctions - ft_init_ref.c
*/
void				ft_init_struct_ref_1(t_ref *ref);

/*
** 3 fonctions - ft_save_op.c
*/
int					ft_instr_check(t_asm *as);
int					ft_if_label(t_asm *as, int i);
int					ft_del_labels(t_asm *as);

/*
** 4 fonctions - ft_aux.c
*/
void				ft_while_space(char *txt, int *i);
int					ft_if_op_ok(t_asm *as, char *op);
int					ft_check_lbl(t_asm *as);

/*
** 3 fonctions - ft_err_aux.c
*/
int					ft_max_len(t_asm *as);
int					ft_real_ln_chr(t_asm *as, int *i, int *j);
void				ft_putstr_token_num(int i, int j);

/*
** 4 fonctions - ft_check_args.c
*/
int					ft_check_var(t_asm *as);

/*
** 3 fonctions - ft_dir_ind.c
*/
int					ft_dir_ind(t_asm *as, char *txt, int *i, t_instr *sv);

/*
** 5 fonctions ft_len_mem.c
*/
void				ft_mem_len(t_asm *as);

/*
** 2 fonction - ft_err_load.c
*/
int					ft_err_load(int ac, int fd, char *src_file, char *path);
int					ft_err_str_gnl(t_asm *as);

/*
** 5 fonction - ft_lex_err.c
*/
int					ft_put_lexerr(t_asm *as, int i, int j);
int					ft_lexical_err(t_asm *as, char **lines);

/*
** 4 fonction - ft_is_char.c
*/
int					ft_is_lblchr(char c);
int					ft_is_lbl_o_dgt(char c);
int					ft_is_lex(char c);
int					ft_is_sep(char c);

/*
** 5 fonction - ft_err_aux2.c
*/
int					ft_add_bkn(t_asm *as, int ln, int chr);
int					ft_put_syntax(t_asm *as, int i, int j);
int					ft_substract_char(t_asm *as, int ln, int chr);

/*
** 5 fonctions - ft_watzis.c
*/
int					ft_watzis(char *txt, int i);

/*
** 5 fonctions - ft_search_syntax.c
*/
void				ft_search_syntax(t_asm *as, int i, int j);

/*
** 5 fonctions - ft_syn_a.c
*/
void				ft_run_types(char *txt, int *j);
int					ft_jmp_lbl(t_asm *as, int i, int *j, int *lbl);
int					ft_syn_a(t_asm *as, int i);

/*
** 2 fonctions - ft_syn_name_comm.c
*/
int					ft_syn_name_comm(t_asm *as);

/*
** 2 fonctions - ft_syn_op.c
*/
int					ft_syn_op(t_asm *as, int i);

/*
** 3 fonctions - ft_syn_args.c
*/
int					ft_syn_args(t_asm *as, int i);

/*
** 2 fonctions - ft_syn_low_ac.c
*/
int					ft_syn_low_ac(t_asm *as, int count_args, char *tmp);
void				ft_check_kills(t_asm *as, int i);

/*
** 2 fonctions - ft_put_syn_lbl.c
*/
int					ft_put_syn_lbl(t_asm *as, int i, int j);

/*
** 4 fonctions - ft_write_in_str.c
*/
int					ft_write_in_str(t_asm *as);

/*
** 5 fonctions - ft_complete_space_n_opt2.c
*/
void				ft_complete_int_space(int nbr, int nb_esp);
void				ft_complete_str_space(char *str, int nb_esp);
void				ft_complete_len_space(int len, int nb_esp);
void				ft_put_args(t_asm *as, int i);
void				ft_put_num_opc(t_asm *as, int i, int *count);

/*
** 5 fonctions - ft_option_a.c
*/
void				ft_option_a(t_asm *as);

/*
** 3 fonctions - ft_output.c
*/
int					ft_write_output(t_asm *as);
int					ft_output(t_asm *as, char **av, int index);
void				ft_print_output(t_asm *as);

/*
** 2 fonctions - ft_free_end.c
*/
void				ft_free_end(t_asm **as);

/*
** 4 fonctions - ft_init_main.c
*/
int					ft_malloc_instr(t_asm *as);
void				ft_init_syn(t_asm *as);
int					ft_init_struct_asm(t_asm **as);

/*
** 2 fonctions - ft_close_load_fd.c
*/
int					ft_close_load_fd(t_asm *as, int fd);
#endif
