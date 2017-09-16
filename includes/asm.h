/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:26:08 by vkim              #+#    #+#             */
/*   Updated: 2017/09/16 16:05:49 by vkim             ###   ########.fr       */
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
	int			arg1;
	int			arg2;
	int			arg3;
	char		*label;
}				t_instr;

typedef struct	s_descr_op
{
	char		*name;
	int			nb_args;
	int			enc_args;
	int			opc;
	int			modif_carry;
	int			label_size;
}				t_descr_op;

typedef struct	s_asm
{
	t_descr_op	t_op_list[16];
	char		*load;
	char		**lines;
	char		*name;
	char		*comment;
	int			len_mem;
	char		*enc;
	t_instr		*op_lst;
}				t_asm;

typedef struct		s_header
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					t_header;

typedef struct		s_op
{
	char	*ref_name;
	int		nb_args;
	int		ref_enc[3];
	int		ref_mdf_c;
	int		ref_lbl_sz;
}					t_op;

int				ft_loading(int ac, char **av, int index, t_asm *as);
int				ft_name_check(t_asm *as, char **name, char *s_check);
int				ft_del_com(t_asm *as);
int				ft_del_space(t_asm *as);
void			ft_del_empty_lines(t_asm *as);
void			ft_init_struct_ref_1(t_op *op_tab);

int				ft_if_label(t_asm *as, int *i);
int				ft_del_labels(t_asm *as);
#endif
