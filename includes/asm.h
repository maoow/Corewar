/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:26:08 by vkim              #+#    #+#             */
/*   Updated: 2017/08/04 16:01:59 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
#include <op.h>
#include <libft.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_loading(int ac, char **av, int index, char **load);

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

typedef struct	s_asm
{
	t_op		t_op_list;
	char		*load;
	char		*name;
	char		*comment;
	int			len_mem;
	char		*enc;
	t_label		*t_lab_list;
	t_instr		*t_instr_list;
}				t_asm;
#endif
