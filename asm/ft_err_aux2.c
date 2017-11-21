/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name_comm_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:46:42 by vkim              #+#    #+#             */
/*   Updated: 2017/11/20 14:39:43 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					ft_add_bkn(t_asm *as, int ln, int chr)
{
	int				i;
	int				j;
	int				count;

	count = 0;
	i = -1;
	while (as->lines[++i] && i <= ln)
	{
		j = -1;
		while (as->lines[i][++j])
			if (i < ln || j < chr)
				if (as->lines[i][j] == '\n')
					count++;
	}
	return (count);
}

int				ft_substract_char(t_asm *as, int ln, int chr)
{
	int			count;
	int			j;

	count = 0;
	j = -1;
	if (!as->lines[ln])
		return (0);
	while (as->lines[ln][++j] == ' ' || as->lines[ln][j] == '\t')
		chr++;
	j = -1;
	while (as->lines[ln][++j] && j <= chr)
	{
		count++;
		if (as->lines[ln][j] == '\n')
			count = 0;
	}
	return (count);
}

int				ft_put_syntax(t_asm *as, int i, int j)
{
	int			k;

	if (ft_real_ln_chr(as, &i, &j) == -1)
		return (-1);
	if (as->lines[i] && i > 0)
		ft_while_space(as->lines[i], &j);
	ft_putstr("Syntax error at");
	ft_putstr_token_num(i, j);
	k = -1;
	while (as->lines[++k])
		;
	i = (i > k) ? k : i;
	as->num_syn = ft_watzis(as->lines[i], j);
	ft_putstr(as->syn[as->num_syn]);
	if (as->num_syn != 13)
		ft_search_syntax(as, i, j);
	return (0);
}
