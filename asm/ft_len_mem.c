/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_mem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 13:31:22 by vkim              #+#    #+#             */
/*   Updated: 2017/10/09 21:42:33 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_len_args(t_asm *as, t_instr *instr)
{
	int			j;

	j = -1;
	while (++j < 3)
	{
		if (instr->i2_on[j] == 1)
			as->len_mem += 2;
		if (instr->i4_on[j] == 1)
		{
			as->len_mem++;
			if (!instr->reg_on[j])
				as->len_mem += 3;
		}
		if (instr->ag_lbl2[j] != NULL)
			as->len_mem += 2;
		if (instr->ag_lbl4[j] != NULL)
			as->len_mem += 4;
	}
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
			if (as->ref[as->op[i].num - 1].mdf_c == 1)
				as->len_mem++;
			ft_len_args(as, &as->op[i]);
		}
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
	as->len_mem = 4 + PROG_NAME_LENGTH + 8 - mod1 + 3 + COMMENT_LENGTH
		+ 8 - mod2;
	ft_mem_op(as);
}
