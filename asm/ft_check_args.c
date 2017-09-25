/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:03:10 by vkim              #+#    #+#             */
/*   Updated: 2017/09/25 16:42:02 by vkim             ###   ########.fr       */
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

	if (as->t_op_list[as->op_lst[as->n_ln].num - 1].ref_enc[as->count_args]
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

int			ft_check_dir(char *txt, int *i, t_instr *sv, int *nb_var)
{
	int		nb_chrs;

	if (as->t_op_list[as->op_lst[as->n_ln].num - 1].ref_enc[as->count_args]
		& T_DIR != T_DIR)
		return (0);
	(void)txt;
	(void)i;
	(void)sv;
	(void)nb_var;
	nb_chrs = 1;
	
	return (1);
}

int			ft_wich_var(char *txt, int *i, int *nb_var, t_instr *sv)
{
	//Check if var is possible for op
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
		ft_check_dir(as->lines[as->n_ln], as->n_chr, as->op_lst[as->n_ln], as->count_args);
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
	int		count_args;

	as->count_args = 0;
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
			if (as->lines[as->n_ln][as->n_chr] == '\0')
				return (0);
			ft_wich_var(as->lines[as->n_ln], as->n_chr, as->count_args, &as->op_lst[as->n_ln]);
			if (as->count_args < as->t_op_list[as->op_lst[as->n_ln].num - 1].nb_args)
				return (0);
		}
	}
	return (1);
}
