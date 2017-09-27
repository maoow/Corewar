/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:03:10 by vkim              #+#    #+#             */
/*   Updated: 2017/09/27 13:07:29 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_arg_ok(t_asm *as)
{

}

int			ft_check_reg(t_asm *as, char *txt, int *i, int *save)
{
	int		tmp;
	int		nb_dgts;

	if (as->t_op_list[as->op_lst[as->n_ln].num - 1].ref_enc[as->count_args - 1]
		& T_REG != T_REG)
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
	int		lbl;

	lbl = 0;
	if (as->t_op_list[as->op_lst[as->n_ln].num - 1].ref_enc[as->count_args - 1]
		& T_DIR != T_DIR)
		return (0);
	nb_chrs = 1;
	(*i)++;
	while (ft_strchr(LABEL_CHARS, txt[++(*i)]))
	{
		nb_chrs++;
		if (txt[*i] < '0' || txt[*i] > '9')
			lbl = 1;
	}
	if (lbl == 0)
		sv->ag_i[as->count_args - 1] = ft_atoi(txt + *i - nb_chrs);
	else
		if (!(sv->ag_lbl[as->count_args - 1]
			= ft_strsub(txt, *i - nb_chrs, nb_chrs)))
			return (0);
	return (1);
}

int			ft_wich_var(char *txt, int *i, int *nb_var, t_instr *sv)
{
	//gerer nb negatifs qui bouclent sauf Reg
	ft_while_space(as->lines[as->n_ln], as->n_chr);
	if (as->lines[as->n_ln][as->n_chr] == ',')
	{
		(as->n_chr)++;
		if (as->count_args == 0
			|| as->count_args
				> as->t_op_list[as->op_lst[as->n_ln].num - 1].nb_args)
			return (0);
	}
	ft_while_space(as->lines[as->n_ln], as->n_chr);
	if (as->lines[as->n_chr] == 'r')
	{
		(as->count_args)++;
		ft_check_reg(as, as->lines[as->n_ln], as->n_chr,
			&sv->ag_i[as->count_args - 1]);
	}
	else if (as->lines[as->n_ln][as->n_chr] == '%')
	{
		(as->count_args)++;
		ft_check_dir(ias, as->lines[as->n_ln], as->n_chr, as->op_lst[as->n_ln]);
	}
	else if (as->lines[as->n_ln][as->n_chr] >= '0'
			&& as->lines[as->n_ln][as->n_chr] <= '9')
	{
		(as->count_args)++;
	}
	else
		return (0);
	ft_while_space(as->lines[as->n_ln], as->n_chr);
	return (1);
}

int			ft_check_var(t_asm *as)
{
	int		i;
	int		j;

	i = -1;
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
				ft_wich_var(as->lines[as->n_ln], as->n_chr, as->count_args,
					&as->op_lst[as->n_ln]);
			if (as->lines[as->n_ln][as->n_chr] != '\0')
				return (0);
		}
	}
	return (1);
}
