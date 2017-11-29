/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:54:13 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 16:53:36 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_putstr_token_num(int i, int j)
{
	ft_putstr(" token [TOKEN][");
	if (i + 1 < 100)
		ft_putstr("0");
	if (i + 1 < 10)
		ft_putstr("0");
	ft_putnbr(i + 1);
	ft_putstr(":");
	if (j + 1 < 100)
		ft_putstr("0");
	if (j + 1 < 10)
		ft_putstr("0");
	ft_putnbr(j + 1);
	ft_putstr("] ");
}

int			ft_real_ln_chr(t_asm *as, int *i, int *j)
{
	int		k;
	int		origine;

	origine = *j;
	if (!(ft_err_str_gnl(as)))
		return (-1);
	if (as->lines[*i])
	{
		k = -1;
		while (as->lines[*i][++k] == ' ' || as->lines[*i][k] == '\t')
			(*j)++;
	}
	origine = *j;
	if (!as->lines[*i])
		return (1);
	*i += ft_add_bkn(as, *i, origine);
	k = -1;
	while (as->lines[++k])
		;
	if (*i >= k)
		*j = 0;
	return (1);
}

int			ft_max_len(t_asm *as)
{
	if (ft_strlen(as->name) > PROG_NAME_LENGTH)
	{
		ft_putstr("Champion name too long (Max length ");
		ft_putnbr(PROG_NAME_LENGTH);
		ft_putstr(")\n");
		return (0);
	}
	else if (ft_strlen(as->comment) > COMMENT_LENGTH)
	{
		ft_putstr("Champion comment too long (Max length ");
		ft_putnbr(COMMENT_LENGTH);
		ft_putstr(")\n");
		return (0);
	}
	return (1);
}
