/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:38:40 by vkim              #+#    #+#             */
/*   Updated: 2017/11/03 10:16:47 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_while_space(char *txt, int *i)
{
	while (txt[*i] && (txt[*i] == ' ' || txt[*i] == '\t'))
		(*i)++;
}

int				ft_if_op_ok(t_asm *as, char *op)
{
	int			i;
	int			res;

	res = -1;
	i = -1;
	while (++i < 16)
	{
		if (!ft_strcmp(as->ref[i].name, op))
			res = i;
	}
	return (res);
}

void			ft_lbl2(t_asm *as, int i, int j, int *find)
{
	int			k;

	k = -1;
	while (as->lines[++k] && !*find)
	{
		if (as->op[k].label && k != i
			&& !ft_strcmp(as->op[k].label, as->op[i].ag_lbl[j]))
			*find = 1;
	}
}

int				ft_check_lbl(t_asm *as)
{
	int			i;
	int			j;
	int			find;

	i = -1;
	while (as->lines[++i])
	{
		j = -1;
		while (++j < 3)
		{
			find = 0;
			if (as->op[i].ag_lbl[j] != NULL)
			{
				ft_lbl2(as, i, j, &find);
				if (!find)
					return (0);
			}
		}
	}
	return (1);
}
