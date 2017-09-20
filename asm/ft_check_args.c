/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:03:10 by vkim              #+#    #+#             */
/*   Updated: 2017/09/20 18:54:32 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_check_reg(char *txt, int *i, int *save)
{
	int		tmp;
	int		nb_dgts;

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

	(void)txt;
	(void)i;
	(void)sv;
	(void)nb_var;
	nb_chrs = 1;
	if (1)
		;
	return (1);
}

int			ft_wich_var(char *txt, int *i, int *nb_var, t_instr *sv)
{
	//For each var encounter(sep by , (optional spaces))
	//Check if var is possible for op
	ft_while_space(txt, i);
	if (txt[*i] == ',')
	{
		(*i)++;
		if (*nb_var == 0)
			return (0);
	}
	ft_while_space(txt, i);
	if (txt[*i] == 'r')
	{
		(*nb_var)++;
		ft_check_reg(txt, i, &sv->ag_i[*nb_var - 1]);
	}
	else if (txt[*i] == '%')
	{
		(*nb_var)++;
		ft_check_dir(txt, i, sv, nb_var);
	}
	else if (txt[*i] >= '0' && txt[*i] <= '9')
	{
		(*nb_var)++;
	}
	else
		return (0);
	//if (*nb_var > sv->) Check too much nb_var
	ft_while_space(txt, i);
	//After while check if nb_var < nb_var_op
	return (1);
}

int			ft_check_var(t_asm *as)
{
	int		i;
	int		j;
	int		count_args;

	count_args = 0;
	i = -1;
	while (as->lines[++i])
	{
		count_args = 0;
		j = -1;
		while (as->lines[i][++j] != '%' && as->lines[i][j] != ' '
			&& as->lines[i][j] != '\0')
			;
		if (j != 0)
		{
			if (as->lines[i][j] == '\0')
				return (0);
			ft_wich_var(as->lines[i], &j, &count_args, &as->op_lst[i]);
		}
	}
	return (1);
}
