/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:26:08 by vkim              #+#    #+#             */
/*   Updated: 2017/09/20 15:14:26 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <libft.h>
# include <op.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h>
typedef struct	s_instr
{
	int			num;
	int			opc;
	int			ag_i[3];
	char		*(ag_lbl[3]);
	char		*label;
}				t_instr;

typedef struct		s_op
{
	char	*ref_name;
	int		nb_args;
	int		ref_enc[3];
	int		ref_mdf_c;
	int		ref_lbl_sz;
}					t_op;

typedef struct	s_asm
{
	t_op		t_op_list[17];
	char		*load;
	char		**lines;
	char		*name;
	char		*comment;
	int			len_mem;
	char		*enc;
	t_instr		*op_lst;
}				t_asm;

//3 fonctions - ft_loading.c
int				ft_loading(int ac, char **av, int index, t_asm *as);

//1 fonction - ft_name_comment.c
int				ft_name_check(t_asm *as, char **name, char *s_check);

//3 fonctions - ft_clean_load.c
int				ft_del_com(t_asm *as);
int				ft_del_space(t_asm *as);
void			ft_del_empty_lines(t_asm *as);

//5 fonctions - ft_init_ref.c
void			ft_init_struct_ref_1(t_op *op_tab);

//3 fonctions - ft_save_op.c
int				ft_instr_check(t_asm *as);
int				ft_if_label(t_asm *as, int *i);
int				ft_del_labels(t_asm *as);

//2 fonctions - ft_aux.c
void			ft_while_space(char *txt, int *i);
int				ft_if_op_ok(t_asm *as, char *op);

//x fonctions - ft_check_args.c
int				ft_check_var(t_asm *as);
#endif
