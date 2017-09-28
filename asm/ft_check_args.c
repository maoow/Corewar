/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:03:10 by vkim              #+#    #+#             */
/*   Updated: 2017/09/28 18:04:35 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_arg_ok(t_asm *as)
{
	(void)as;
	return (0);
}

int			ft_check_reg(t_asm *as, char *txt, int *i, int *save)
{
	int		tmp;
	int		nb_dgts;

	if ((as->t_op_list[as->op_lst[as->n_ln].num - 1].ref_enc[as->count_args - 1]
		& T_REG) != T_REG)
		return (0);
	nb_dgts = 1;
	(*i)++;
	if (txt[*i] < '0' || txt[*i] > '9')
		return (0);
	if (txt[*i + 1] >= '0' && txt[*i + 1] <= '9')
	{
		nb_dgts++;
		if (txt[*i + 2] >= '0' && txt[*i + 2] <= '9')
			return (0);
	}
	if ((tmp = ft_atoi(txt + *i)) >= 0 && tmp <= 99)
	{
		*save = tmp;
		(*i)+= nb_dgts;
	}
	else
		return (0);
	return (1);
}

int			ft_check_dir(t_asm *as, char *txt, int *i, t_instr *sv)
{
	int		nb_chrs;

	if (txt[*i] == '%')
	{
		if (!txt[*i + 1])
			return (0);
		(*i)++;
	}
	if (txt[*i] == ':')
	{
		(*i)++;
		nb_chrs = 0;
		while (ft_strchr(LABEL_CHARS, txt[*i]))
		{
			(*i)++;
			nb_chrs++;
		}
		if (!(sv->ag_lbl[as->count_args - 1]
			= ft_strsub(txt, *i - nb_chrs, nb_chrs)))
			return (0);
	}
	else if (txt[*i] == '-' || (txt[*i] >= '0' && txt[*i] <= '9'))
	{
		sv->ag_i[as->count_args - 1] = ft_atoi(txt + *i);
		if (txt[*i] == '-')
			(*i)++;
		while (txt[*i] >= '0' && txt[*i] <= '9')
			(*i)++;
	}
	else
		return (0);
	return (1);
}

int			ft_wich_var(t_asm *as, t_instr *sv)
{
	//gerer nb negatifs qui bouclent sauf Reg
	ft_while_space(as->lines[as->n_ln], &as->n_chr);
	if (as->lines[as->n_ln][as->n_chr] == ',')
	{
		(as->n_chr)++;
		if (as->count_args == 0
			|| as->count_args
				> as->t_op_list[as->op_lst[as->n_ln].num - 1].nb_args)
			return (0);
	}
	ft_while_space(as->lines[as->n_ln], &as->n_chr);
	if (as->lines[as->n_ln][as->n_chr] == 'r')
	{
		(as->count_args)++;
		ft_check_reg(as, as->lines[as->n_ln], &as->n_chr,
			&sv->ag_i[as->count_args - 1]);
	}
	else if (as->lines[as->n_ln][as->n_chr] == '%')
	{
		(as->count_args)++;
		if ((as->t_op_list[as->op_lst[as->n_ln].num - 1].ref_enc[as->count_args - 1]
			& T_DIR) != T_DIR)
			return (0);
		ft_check_dir(as, as->lines[as->n_ln], &as->n_chr, &as->op_lst[as->n_ln]);
	}
	else if ((as->lines[as->n_ln][as->n_chr] >= '0'
				&& as->lines[as->n_ln][as->n_chr] <= '9')
			|| as->lines[as->n_ln][as->n_chr] == '-'
			|| ft_strchr(LABEL_CHARS, as->lines[as->n_ln][as->n_chr]))
	{
		(as->count_args)++;
		if ((as->t_op_list[as->op_lst[as->n_ln].num - 1].ref_enc[as->count_args - 1]
			& T_IND) != T_IND)
			return (0);
		ft_check_dir(as, as->lines[as->n_ln], &as->n_chr, &as->op_lst[as->n_ln]);
	}
	else
		return (0);
	ft_while_space(as->lines[as->n_ln], &as->n_chr);
	return (1);
}

int			ft_check_var(t_asm *as)
{
	as->n_ln = -1;
	while (as->lines[++(as->n_ln)])
	{
		as->count_args = 0;
		as->n_chr = -1;
		while (as->lines[as->n_ln][++(as->n_chr)] != '%'
			&& as->lines[as->n_ln][as->n_chr] != ' '
			&& as->lines[as->n_ln][as->n_chr] != '\0')
			;
		if (as->n_chr != 0)
		{
			while (as->count_args
			< as->t_op_list[as->op_lst[as->n_ln].num - 1].nb_args)
			{
				if (!(ft_wich_var(as, &as->op_lst[as->n_ln])))
					return (0);
			}
			if (as->lines[as->n_ln][as->n_chr] != '\0')
				return (0);
		}
	}
	return (1);
}
