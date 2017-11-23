/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syn_A.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:16:03 by vkim              #+#    #+#             */
/*   Updated: 2017/11/23 16:21:05 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void				ft_run2(char *txt, int *j)
{
	if (txt[*j] == '-')
		(*j)++;
	while (ft_isdigit(txt[*j]))
		(*j)++;
}

void				ft_run_types(char *txt, int *j)
{
	if (ft_watzis(txt, *j) == 12)
	{
		while (ft_is_lblchr(txt[*j]))
			(*j)++;
		return ;
	}
	if (txt[*j] == ',')
	{
		(*j)++;
		return ;
	}
	if (txt[*j] == '%')
		(*j)++;
	if (txt[*j] == ':')
		while (ft_is_lblchr(txt[++(*j)]))
			;
	if (txt[*j] == 'r')
	{
		(*j) += 2;
		if (ft_isdigit(txt[*j]))
			(*j)++;
	}
	else
		ft_run2(txt, j);
}

int					ft_jmp_lbl(t_asm *as, int i, int *j, int *lbl)
{
	if (!as->lines[i])
		return (0);
	if (!as->lines[i][*j])
		return (0);
	*lbl = 0;
	*j = 0;
	if (ft_watzis(as->lines[i], 0) == 11)
	{
		*lbl = 1;
		while (as->lines[i][*j] != ':' && as->lines[i][*j])
			(*j)++;
		(*j)++;
	}
	ft_while_space(as->lines[i], j);
	return (1);
}

int					ft_syn_a(t_asm *as, int i)
{
	int				j;
	int				var;

	j = 0;
	if (!ft_jmp_lbl(as, i, &j, &var))
		return (1);
	if (ft_watzis(as->lines[i], j) != 12 && as->lines[i][j])
		return (ft_put_syntax(as, i, j));
	var = 1;
	while (as->lines[i][j])
	{
		ft_run_types(as->lines[i], &j);
		ft_while_space(as->lines[i], &j);
		if ((as->lines[i][j] == ',' || as->lines[i][j] == '\0') && var == 1)
			return (ft_put_syntax(as, i, j));
		if (ft_watzis(as->lines[i], j) == 2 || ft_watzis(as->lines[i], j) >= 11
		|| ft_watzis(as->lines[i], j) == 7 || ft_watzis(as->lines[i], j) == 8)
			return (ft_put_syntax(as, i, j));
		if (((ft_watzis(as->lines[i], j) >= 3 && ft_watzis(as->lines[i], j) < 6)
			|| ft_watzis(as->lines[i], j) == 9
			|| ft_watzis(as->lines[i], j) == 10) && var == 0)
			return (ft_put_syntax(as, i, j));
		var = (var == 0) ? 1 : 0;
	}
	return (1);
}
