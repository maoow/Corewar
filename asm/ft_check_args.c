/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:03:10 by vkim              #+#    #+#             */
/*   Updated: 2017/10/11 11:04:20 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_check_reg(t_asm *as, char *txt, int *i, char *save)
{
	int		tmp;
	int		nb_dgts;

	if ((as->ref[as->op[as->n_ln].num - 1].tvar[as->ac - 1] & T_REG) != T_REG)
		return (0);
	if (as->ref[as->op[as->n_ln].num - 1].mdf_c)
		as->op[as->n_ln].opc |= (REG_CODE << (6 - (as->ac - 1) * 2));
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
		(*i) += nb_dgts;
	}
	else
		return (0);
	return (1);
}

int			ft_type_var(t_asm *as)
{
	if (as->lines[as->n_ln][as->n_chr] == '%'
		|| ((as->lines[as->n_ln][as->n_chr] >= '0'
			&& as->lines[as->n_ln][as->n_chr] <= '9')
			|| as->lines[as->n_ln][as->n_chr] == '-'
			|| ft_strchr(LABEL_CHARS, as->lines[as->n_ln][as->n_chr]))
		|| as->lines[as->n_ln][as->n_chr] == ':')
	{
		(as->ac)++;
		if (as->lines[as->n_ln][as->n_chr] == '%')
		{
			if ((as->ref[as->op[as->n_ln].num - 1].tvar[as->ac - 1]
				& T_DIR) != T_DIR
				&& (as->ref[as->op[as->n_ln].num - 1].tvar[as->ac - 1] & T_IND)
				!= T_IND)
				return (0);
		}
		if (!(ft_dir_ind(as, as->lines[as->n_ln], &as->n_chr,
			&as->op[as->n_ln])))
			return (0);
	}
	else
		return (0);
	ft_while_space(as->lines[as->n_ln], &as->n_chr);
	return (1);
}

int			ft_wich_var(t_asm *as, t_instr *sv)
{
	ft_while_space(as->lines[as->n_ln], &as->n_chr);
	if (as->lines[as->n_ln][as->n_chr] == ',')
	{
		(as->n_chr)++;
		if (as->ac == 0 || as->ac > as->ref[as->op[as->n_ln].num - 1].ac)
			return (0);
	}
	ft_while_space(as->lines[as->n_ln], &as->n_chr);
	if (as->lines[as->n_ln][as->n_chr] == 'r')
	{
		(as->ac)++;
		if (!(ft_check_reg(as, as->lines[as->n_ln], &as->n_chr,
			&sv->reg[as->ac - 1])))
			return (0);
	}
	else if (!(ft_type_var(as)))
		return (0);
	return (1);
}

int			ft_check_var(t_asm *as)
{
	as->n_ln = -1;
	while (as->lines[++(as->n_ln)])
	{
		as->ac = 0;
		as->n_chr = -1;
		while (as->lines[as->n_ln][++(as->n_chr)] != '%'
			&& as->lines[as->n_ln][as->n_chr] != ' '
			&& as->lines[as->n_ln][as->n_chr] != '\0')
			;
		if (as->n_chr != 0)
		{
			while (as->ac < as->ref[as->op[as->n_ln].num - 1].ac)
			{
				if (!(ft_wich_var(as, &as->op[as->n_ln])))
					return (0);
			}
			if (as->lines[as->n_ln][as->n_chr] != '\0')
				return (0);
		}
	}
	return (1);
}
