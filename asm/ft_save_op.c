/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 09:44:06 by vkim              #+#    #+#             */
/*   Updated: 2017/11/20 09:32:01 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_instr_check(t_asm *as)
{
	int			i;
	int			j;
	char		*tmp;

	tmp = NULL;
	i = -1;
	while (as->lines[++i])
	{
		j = -1;
		while (as->lines[i][++j] != '%' && !ft_is_sep(as->lines[i][j])
			&& as->lines[i][j] != '\0')
			;
		if (j != 0)
		{
			if (!(tmp = ft_strsub(as->lines[i], 0, j))
				|| (as->op[i].num = ft_if_op_ok(as, tmp)) == -1)
			{
				ft_strdel(&tmp);
				return (0);
			}
			as->op[i].num += 1;
			ft_strdel(&tmp);
		}
	}
	return (1);
}

int				ft_del_labels(t_asm *as)
{
	int			i;
	int			k;
	char		*save;

	i = -1;
	while (as->lines[++i])
	{
		if (ft_strchr(as->lines[i], ':'))
		{
			k = -1;
			while (ft_strchr(LABEL_CHARS, as->lines[i][++k]))
				;
			if (as->lines[i][k] == ':')
			{
				k++;
				save = as->lines[i];
				if (!(as->lines[i] = ft_strsub(as->lines[i], k,
					ft_strlen(as->lines[i]) - k)))
					return (0);
				free(save);
			}
		}
	}
	return (1);
}

int				ft_if_label(t_asm *as, int *i)
{
	int			k;

	if (ft_strchr(as->lines[*i], ':'))
	{
		k = -1;
		while (as->lines[*i][++k] && ft_strchr(LABEL_CHARS, as->lines[*i][k]))
			;
		if (as->lines[*i][k] != ':')
			return (1);
		if (!(as->op[*i].label = ft_strsub(as->lines[*i], 0, k)))
			return (0);
	}
	return (1);
}
