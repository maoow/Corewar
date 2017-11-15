/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name_comm_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:46:42 by vkim              #+#    #+#             */
/*   Updated: 2017/11/15 11:29:45 by vkim             ###   ########.fr       */
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
	while (as->lines[ln][++j] && j <= chr)
	{
		count++;
		if (as->lines[ln][j] == '\n')
			count = 0;
	}
	return (count);
}

int				ft_bkz_syntax(t_asm *as, int i, int j)
{
	if (ft_real_ln_chr(as, &i, &j) == -1)
		return (-1);
	ft_putstr("Syntax error");
	ft_putstr_at_token_num(i, j);
	ft_putstr("END \"(null)\"\n");
	return (0);
}

int				ft_put_syntax(t_asm *as, int i, int j, char *s_check)
{
	if (j < ft_strlen(s_check))
		return (0);
	if (ft_real_ln_chr(as, &i, &j) == -1)
		return (-1);
	as->num_syn = ft_watzis(as->lines[i], j);
	ft_putstr("Syntax error");
	ft_putstr_at_token_num(i, j);
	ft_putstr(as->syn[as->num_syn]);
	ft_search_syntax(as, i, j);
	return (0);
}
