/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syn_A.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:16:03 by vkim              #+#    #+#             */
/*   Updated: 2017/11/15 16:18:28 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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
		while (ft_is_lblchr(txt[*j]))
			(*j)++;
	else
		while (ft_isdigit(txt[*j]))
			(*j)++;
}

int					ft_syn_A(t_asm *as, int i)
{
	int				j;
	int				var;

	if (ft_watzis(as->lines[i], 0) != 12)
		return (ft_put_syntax(as, i, 0));
	var = 1;
	j = 0;
	while (as->lines[i][j])
	{
		ft_run_types(as->lines[i], &j);
		ft_while_space(as->lines[i], &j);
		if ((as->lines[i][j] == ',' || ft_watzis(as->lines[i], j) == 1)
			&& var == 1)
			return (ft_put_syntax(as, i, j));
		if (ft_watzis(as->lines[i], j) == 2 || ft_watzis(as->lines[i], j) >= 11
		|| ft_watzis(as->lines[i], j) == 7 || ft_watzis(as->lines[i], j) == 8)
			return (ft_put_syntax(as, i, j));
		var = (var == 0) ? 1 : 0;
	}
	return (1);
}

int					ft_op_comma(t_asm *as)
{
	(void)as;
	return (1);
}
