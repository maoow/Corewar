/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:26:08 by vkim              #+#    #+#             */
/*   Updated: 2017/10/23 15:36:44 by vkim             ###   ########.fr       */
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
	char			*load;
	char			**lines;
	char			*name;
	char			*comment;
	int				len_mem;
	t_instr			*op;
}					t_asm;

/*
** 3 fonctions - ft_loading.c
*/
int					ft_loading(int ac, char **av, int index, t_asm *as);

/*
** 1 fonction - ft_name_comment.c
*/
int					ft_name_check(t_asm *as, char **name, char *s_check);

/*
** 3 fonctions - ft_clean_load.c
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
** 1 fonction - ft_err_load.c
*/
int					ft_err_load(int ac, int fd, char *str);
#endif
