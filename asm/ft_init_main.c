/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:20:14 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 16:53:36 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_malloc_vars(t_asm *as, int j)
{
	int			k;

	k = -1;
	while (++k < 3)
	{
		as->op[j].reg[k] = -1;
		as->op[j].i_lbl_sz[0][k] = 0;
		as->op[j].i_lbl_sz[1][k] = 0;
		as->op[j].ag_i2[k] = 0;
		as->op[j].ag_i4[k] = 0;
		as->op[j].ag_lbl[k] = NULL;
	}
}

int				ft_malloc_instr(t_asm *as)
{
	int			i;
	int			j;

	i = -1;
	while (as->lines[++i])
		;
	if (!(as->op = (t_instr *)malloc(i * sizeof(t_instr))))
		return (0);
	j = -1;
	while (++j < i)
	{
		as->op[j].mem_num = -1;
		as->op[j].num = 0;
		as->op[j].opc = 0;
		ft_malloc_vars(as, j);
		as->op[j].label = NULL;
	}
	return (1);
}

void			ft_init_syn(t_asm *as)
{
	as->syn[1] = "ENDLINE\n";
	as->syn[2] = "STRING";
	as->syn[3] = "DIRECT_LABEL";
	as->syn[4] = "DIRECT";
	as->syn[5] = "INDIRECT_LABEL";
	as->syn[6] = "SEPARATOR";
	as->syn[7] = "COMMAND_COMMENT";
	as->syn[8] = "COMMAND_NAME";
	as->syn[9] = "INDIRECT";
	as->syn[10] = "REGISTER";
	as->syn[11] = "LABEL";
	as->syn[12] = "INSTRUCTION";
	as->syn[13] = "END \"(null)\"\n";
}

int				ft_init_struct_asm(t_asm **as)
{
	if (!(*as = (t_asm *)malloc(sizeof(t_asm))))
		return (0);
	if (!((*as)->load = malloc(sizeof(char))))
		return (0);
	(*as)->lines = NULL;
	(*as)->load[0] = '\0';
	(*as)->name = NULL;
	(*as)->comment = NULL;
	(*as)->len_mem = 0;
	(*as)->ac = 0;
	(*as)->n_ln = 0;
	(*as)->n_chr = 0;
	(*as)->strt_mem = 0;
	(*as)->op = NULL;
	(*as)->mem = NULL;
	(*as)->opt_a = 0;
	(*as)->output = NULL;
	return (1);
}
