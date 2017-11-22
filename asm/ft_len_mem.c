/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:31:22 by vkim              #+#    #+#             */
/*   Updated: 2017/11/22 15:27:51 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_clc_lbl(t_asm *as, t_instr *instr, int j)
{
	int			k;
	int			stop;

	k = -1;
	stop = 0;
	while (as->lines[++k])
	{
		if (as->op[k].label && !ft_strcmp(as->op[k].label, instr->ag_lbl[j])
		&& stop == 0)
		{
			if (instr->i_lbl_sz[1][j] == 2
					&& instr->mem_num > as->op[k].mem_num)
				instr->ag_i2[j] = 0xFFFF - instr->mem_num
					+ as->op[k].mem_num + 1;
			else if (instr->i_lbl_sz[1][j] == 2)
				instr->ag_i2[j] = as->op[k].mem_num - instr->mem_num;
			else if (instr->i_lbl_sz[1][j] == 4
				&& instr->mem_num > as->op[k].mem_num)
				instr->ag_i4[j] = 0xFFFFFFFF - instr->mem_num
				+ as->op[k].mem_num + 1;
			else
				instr->ag_i4[j] = as->op[k].mem_num - instr->mem_num;
			stop = 1;
		}
	}
}

void			ft_run_lbl(t_asm *as)
{
	int			i;
	int			j;

	i = -1;
	while (as->lines[++i])
	{
		if (as->op[i].num > 0)
		{
			j = -1;
			while (++j < 3)
				if (as->op[i].i_lbl_sz[1][j] > 0)
					ft_clc_lbl(as, &as->op[i], j);
		}
	}
}

void			ft_len_args(t_asm *as, t_instr *instr)
{
	int			l;
	int			j;

	l = -1;
	while (++l < 2)
	{
		j = -1;
		while (++j < 3)
			if (instr->i_lbl_sz[l][j] > 0)
				as->len_mem += instr->i_lbl_sz[l][j];
	}
	j = -1;
	while (++j < 3)
		if (instr->reg[j] > -1)
			as->len_mem++;
}

void			ft_mem_op(t_asm *as)
{
	int			i;

	i = -1;
	while (as->lines[++i])
	{
		if (as->op[i].num > 0)
		{
			as->len_mem++;
			as->op[i].mem_num = as->len_mem - as->strt_mem - 1;
			if (as->op[i].opc > 0)
				as->len_mem++;
			ft_len_args(as, &as->op[i]);
		}
		else
			as->op[i].mem_num = as->len_mem - as->strt_mem;
	}
}

void			ft_mem_len(t_asm *as)
{
	int			mod1;
	int			mod2;

	as->len_mem = 0;
	mod1 = (PROG_NAME_LENGTH + 4) % 8;
	if (mod1 == 0)
		mod1 = 8;
	mod2 = (COMMENT_LENGTH + 3) % 8;
	if (mod2 == 0)
		mod2 = 8;
	as->len_mem = 4 + PROG_NAME_LENGTH + 8 - mod1 + 4 + COMMENT_LENGTH
		+ 8 - mod2 - 1;
	as->strt_mem = as->len_mem;
	ft_mem_op(as);
	ft_run_lbl(as);
}
