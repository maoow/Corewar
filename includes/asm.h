/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:26:08 by vkim              #+#    #+#             */
/*   Updated: 2017/09/05 13:14:35 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#include <op.h>
#include <libft.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#include <stdio.h>
typedef struct s_instr
{
	int			num;
	int			arg1;
	int			arg2;
	int			arg3;
}				t_instr;

typedef struct s_label
{
	char		*lab;
	int			place_str;
	int			place_oct;
}				t_label;

typedef struct s_op
{
	char		*name;
	int			nb_args;
	int			enc_args;
	int			opc;
	int			modif_carry;
	int			label_size;
}				t_op;

typedef struct	s_asm
{
	t_op		t_op_list[16];
	char		*load;
	char		**lines;
	char		*name;
	char		*comment;
	int			len_mem;
	char		*enc;
	t_label		*t_lab_list;
	t_instr		*t_instr_list;
}				t_asm;

int				ft_loading(int ac, char **av, int index, t_asm *as);
int				ft_name_check(t_asm *as, char **name, char *s_check);

#endif
