/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_in_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:49:28 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 16:53:39 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			ft_until2(t_asm *as, int *i, int mod, int n_chr)
{
	int			j;

	j = 4;
	while (--j >= 0)
		as->mem[(*i)++] = ((char *)(&n_chr))[j];
	while (*i - mod - 4 < ft_strlen(as->comment))
	{
		as->mem[*i] = as->comment[*i - mod - 4];
		(*i)++;
	}
	while (*i < as->strt_mem)
		as->mem[(*i)++] = 0;
}

int				ft_until_comm(t_asm *as)
{
	int			i;
	int			mod;
	int			n_chr;

	if (!(as->mem = (char *)malloc(as->len_mem * sizeof(char))))
		return (0);
	((int *)as->mem)[0] = -209458688;
	i = 3;
	while (++i - 4 < ft_strlen(as->name))
		as->mem[i] = as->name[i - 4];
	while (i < PROG_NAME_LENGTH + 4)
		as->mem[i++] = 0;
	mod = (((PROG_NAME_LENGTH + 4) % 8) == 0) ? 8 : (PROG_NAME_LENGTH + 4) % 8;
	mod = 4 + PROG_NAME_LENGTH + 8 - mod;
	while (i < mod)
		as->mem[i++] = 0;
	n_chr = as->len_mem - as->strt_mem;
	ft_until2(as, &i, mod, n_chr);
	return (1);
}

void			ft_write_op(t_asm *as, int i, int *k)
{
	int			j;
	int			len;

	j = -1;
	while (++j < 3)
	{
		len = 0;
		if (as->op[i].reg[j] > -1)
			len = 1;
		if (as->op[i].i_lbl_sz[0][j])
			len = as->op[i].i_lbl_sz[0][j];
		if (as->op[i].i_lbl_sz[1][j])
			len = as->op[i].i_lbl_sz[1][j];
		while (--len >= 0)
		{
			if (as->op[i].reg[j] > -1)
				as->mem[(*k)++] = as->op[i].reg[j];
			if (as->op[i].i_lbl_sz[0][j] == 2
				|| as->op[i].i_lbl_sz[1][j] == 2)
				as->mem[(*k)++] = ((char *)&as->op[i].ag_i2[j])[len];
			if (as->op[i].i_lbl_sz[0][j] == 4
				|| as->op[i].i_lbl_sz[1][j] == 4)
				as->mem[(*k)++] = ((char *)&as->op[i].ag_i4[j])[len];
		}
	}
}

int				ft_write_in_str(t_asm *as)
{
	int			i;
	int			k;

	if (!(ft_until_comm(as)))
		return (0);
	k = as->strt_mem;
	i = -1;
	while (as->lines[++i])
	{
		if (as->op[i].num > 0)
		{
			as->mem[k++] = as->op[i].num;
			if (as->op[i].opc > 0)
				as->mem[k++] = as->op[i].opc;
			ft_write_op(as, i, &k);
		}
	}
	return (1);
}
