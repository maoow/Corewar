/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syn_B.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 08:58:56 by vkim              #+#    #+#             */
/*   Updated: 2017/11/20 14:40:16 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					ft_put_bad_op(t_asm *as, int i, int j, char *tmp)
{
	int				k;

	if (ft_real_ln_chr(as, &i, &j) == -1)
		return (-1);
	if (as->lines[i] && i > 0)
		ft_while_space(as->lines[i], &j);
	ft_putstr("Invalid instruction at");
	ft_putstr_token_num(i, j);
	k = -1;
	while (as->lines[++k])
		;
	i = (i > k) ? k : i;
	ft_putstr("INSTRUCTION \"");
	ft_putstr(tmp);
	ft_putstr("\"\n");
	return (0);
}

int					ft_syn_op(t_asm *as, int i)
{
	int				j;
	int				k;
	char			*tmp;

	if (!ft_jmp_lbl(as, i, &j, &k))
		return (1);
	if ((as->num_syn = ft_watzis(as->lines[i], j)) != 12
		&& as->num_syn != 1)
		return (0);
	if (as->num_syn == 1)
		return (1);
	k = j;
	while (ft_is_lblchr(as->lines[i][k]))
		k++;
	if (!(tmp = ft_strsub(as->lines[i], j, k - j)))
		return (-1);
	if (ft_if_op_ok(as, tmp) == -1)
	{
		j = ft_put_bad_op(as, i, j, tmp);
		ft_strdel(&tmp);
		return (j);
	}
	return (1);
}

int					ft_put_bad_arg(int count_args, int type_var, char *tmp)
{
	ft_putstr("Invalid parameter ");
	ft_putnbr(count_args);
	ft_putstr(" type ");
	if (type_var == T_DIR)
		ft_putstr("direct");
	else if (type_var == T_IND)
		ft_putstr("indirect");
	if (type_var == T_REG)
		ft_putstr("register");
	ft_putstr(" for instruction ");
	ft_putstr(tmp);
	ft_putstr("\n");
	ft_strdel(&tmp);
	return (0);
}

int					ft_each_args(t_asm *as, int *j, int *count_args, char *tmp)
{
	unsigned int	type_var;
	int				num_op;

	ft_run_types(as->lines[as->n_ln], j);
	if (as->lines[as->n_ln][*j] == ',')
		(*j)++;
	ft_while_space(as->lines[as->n_ln], j);
	if ((num_op = ft_if_op_ok(as, tmp)) == -1)
		return (0);
	if (ft_watzis(as->lines[as->n_ln], *j) == 3
		|| ft_watzis(as->lines[as->n_ln], *j) == 4)
		type_var = T_DIR;
	else if (ft_watzis(as->lines[as->n_ln], *j) == 5
		|| ft_watzis(as->lines[as->n_ln], *j) == 9)
		type_var = T_IND;
	else
		type_var = T_REG;
	if ((as->ref[num_op].tvar[*count_args] & type_var) != type_var)
		return (ft_put_bad_arg(*count_args, type_var, tmp));
	(*count_args)++;
	if (*count_args > as->ref[num_op].ac)
		return (ft_put_bad_arg(*count_args - 1, type_var, tmp));
	ft_run_types(as->lines[as->n_ln], j);
	ft_while_space(as->lines[as->n_ln], j);
	return (1);
}

int					ft_syn_args(t_asm *as, int i)
{
	char			*tmp;
	int				j;
	int				k;
	int				count_args;

	as->n_ln = i;
	if (!ft_jmp_lbl(as, i, &j, &k))
		return (1);
	if (!as->lines[i][j])
		return (1);
	if ((as->num_syn = ft_watzis(as->lines[i], j)) != 12
		|| as->num_syn == 1)
		return (0);
	k = j;
	while (ft_is_lblchr(as->lines[i][k]))
		k++;
	if (!(tmp = ft_strsub(as->lines[i], j, k - j)))
		return (-1);
	count_args = 0;
	while (as->lines[i][j])
	{
		if (!(ft_each_args(as, &j, &count_args, tmp)))
			return (0);
	}
	return (ft_syn_low_ac(as, count_args, tmp));
}
