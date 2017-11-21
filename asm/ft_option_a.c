/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:35:30 by vkim              #+#    #+#             */
/*   Updated: 2017/11/21 18:25:22 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_put_thirdline(t_asm *as, int i, int *count)
{
	int			k;

	ft_put_num_opc(as, i, count);
	k = -1;
	while (++k < 3)
	{
		if (as->op[i].i_lbl_sz[0][k] == 2
			|| as->op[i].i_lbl_sz[1][k] == 2)
			ft_complete_int_space((short int)as->op[i].ag_i2[k], 18);
		else if (as->op[i].i_lbl_sz[0][k] == 4
			|| as->op[i].i_lbl_sz[1][k] == 4)
			ft_complete_int_space(as->op[i].ag_i4[k], 18);
		else if (as->op[i].reg[k] > -1)
			ft_complete_int_space((char)as->op[i].reg[k], 18);
	}
	ft_putstr("\n\n");
}

void			ft_put_secondline(t_asm *as, int i, int *count)
{
	int			k;
	int			len;

	ft_put_num_opc(as, i, count);
	k = -1;
	while (++k < 3)
	{
		as->n_chr = 0;
		if (as->op[i].i_lbl_sz[0][k] == 2 || as->op[i].i_lbl_sz[1][k] == 2)
			as->n_chr = 2;
		else if (as->op[i].i_lbl_sz[0][k] == 4 || as->op[i].i_lbl_sz[1][k] == 4)
			as->n_chr = 4;
		else if (as->op[i].reg[k] > -1)
			as->n_chr = 1;
		len = -1;
		while (++len < as->n_chr)
		{
			if (len < as->n_chr - 1)
				ft_complete_int_space((unsigned char)as->mem[(*count)++], 4);
			else
				ft_complete_int_space((unsigned char)as->mem[(*count)++],
					22 - as->n_chr * 4);
		}
	}
	ft_putstr("\n");
}

void			ft_put_firstline(t_asm *as, int i)
{
	ft_complete_int_space(as->op[i].mem_num, 5);
	ft_putstr("(");
	if (as->lines[i + 1])
	{
		ft_complete_int_space(as->op[i + 1].mem_num
			- as->op[i].mem_num, 3);
	}
	else
	{
		ft_complete_int_space(as->len_mem - as->strt_mem
			- as->op[i].mem_num, 3);
	}
	ft_putstr(") :        ");
	ft_complete_str_space(as->ref[as->op[i].num - 1].name, 10);
	ft_put_args(as, i);
	ft_putstr("\n");
}

void			ft_put_intro(t_asm *as)
{
	ft_putstr("Dumping annotated program on standard output\nProgram size : ");
	ft_putnbr(as->len_mem - as->strt_mem);
	ft_putstr(" bytes\nName : \"");
	ft_putstr(as->name);
	ft_putstr("\"\nComment : \"");
	ft_putstr(as->comment);
	ft_putstr("\"\n\n");
}

void			ft_option_a(t_asm *as)
{
	int			i;
	int			count;

	ft_put_intro(as);
	i = -1;
	while (as->lines[++i])
	{
		if (as->op[i].label)
		{
			ft_complete_int_space(as->op[i].mem_num, 11);
			ft_putstr(":    ");
			ft_putstr(as->op[i].label);
			ft_putstr(":\n");
		}
		if (as->op[i].num > 0)
		{
			ft_put_firstline(as, i);
			ft_put_secondline(as, i, &count);
			ft_put_thirdline(as, i, &count);
		}
	}
}
