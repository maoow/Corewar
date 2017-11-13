/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name_comm_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:46:42 by vkim              #+#    #+#             */
/*   Updated: 2017/11/13 16:00:45 by vkim             ###   ########.fr       */
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
	int			k;
	int				chr;

	if (!(ft_err_str_gnl(as)))
		return (-1);
	chr = ft_substract_char(as, i, j);
	k = -1;
	while (as->lines[i][++k] == ' ' || as->lines[i][k] == '\t')
		j++;
	i += ft_add_bkn(as, i, j);
	ft_putstr("Syntax error at token [TOKEN][");
	if (i + 1 < 100)
		ft_putstr("0");
	if (i + 1 < 10)
		ft_putstr("0");
	ft_putnbr(i + 1);
	ft_putstr(":");
	if (chr + 1 < 100)
		ft_putstr("0");
	if (chr + 1 < 10)
		ft_putstr("0");
	ft_putnbr(chr + 1);
	ft_putstr("] END \"(null)\"\n");
	return (0);
}

int				ft_put_syntax(char *txt, int i, char *s_check)
{
	int			num;

	if (i < ft_strlen(s_check))
		return (0);
	num = ft_watzis(txt, i);
	printf("NUM : %d\n", num);
	return (0);
}
