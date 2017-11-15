/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:54:13 by vkim              #+#    #+#             */
/*   Updated: 2017/11/15 16:30:55 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		ft_putstr_at_token_num(int i, int j)
{
	ft_putstr(" at token [TOKEN][");
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
	int		chr;
	int		origine;

	origine = *j;
	if (!(ft_err_str_gnl(as)))
		return (-1);
	if (ft_watzis(as->lines[*i], 0) == 11)
	{
		while (as->lines[*i][++(*j)] && as->lines[*i][*j] != ':')
			;
		(*j)++;
		ft_while_space(as->lines[*i], j);
		origine = *j;
	}
	chr = *j;
	chr = ft_substract_char(as, *i, *j);
	if (chr < *j)
		*j = chr;
	k = -1;
	while (as->lines[*i][++k] == ' ' || as->lines[*i][k] == '\t')
		(*j)++;
	*i += ft_add_bkn(as, *i, origine);
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