/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:36:11 by vkim              #+#    #+#             */
/*   Updated: 2017/11/17 17:34:43 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_put_lexerr(t_asm *as, int i, int j)
{
	if (j > 0 && as->lines[i][j] == ':' && as->lines[i][j - 1] == '%')
		j--;
	if (ft_real_ln_chr(as, &i, &j) == -1)
		return (-1);
	ft_putstr("Lexical error at [");
	ft_putnbr(i + 1);
	ft_putstr(":");
	ft_putnbr(j + 1);
	ft_putstr("]\n");
	return (0);
}

int				ft_check_command(char **lines, int i, int j, int nb)
{
	int			k;
	int			l;

	if (nb == 1 || nb == 3)
	{
		k = 0;
		while (lines[i][k + j] == NAME_CMD_STRING[k]
			&& lines[i][k] && NAME_CMD_STRING[k])
				k++;
		if (NAME_CMD_STRING[k] == '\0')
			return (ft_strlen(NAME_CMD_STRING));
	}
	if (nb == 2 || nb == 3)
	{
		l = 0;
		while (lines[i][l + j] == COMMENT_CMD_STRING[l]
			&& lines[i][l] && COMMENT_CMD_STRING[l])
				l++;
		if (COMMENT_CMD_STRING[l] == '\0')
			return (ft_strlen(COMMENT_CMD_STRING));
	}
	return (0);
}

int				ft_lexical_err(t_asm *as, char **lines)
{
	int			i;
	int			j;
	int			k;
	int			cmd;
	int			lbl;
	int			str;

	cmd = 0;
	i = -1;
	str = 0;
	while (lines[++i])
	{
		j = -1;
		cmd = 0;
		lbl = 0;
		while (lines[i][++j])
		{
			if (lines[i][j] == '-')
			{
				lbl = 0;
				if (!ft_isdigit(lines[i][j + 1]))
					return (ft_put_lexerr(as, i, j));
			}
			if (str == 0 && lines[i][j] == '\"')
				str = 1;
			else if (str == 1 && lines[i][j] == '\"')
				str = 0;
			if (str == 0)
			{
				if (lines[i][j] == NAME_CMD_STRING[0]
						|| lines[i][j] == COMMENT_CMD_STRING[0])
				{
					if (ft_check_command(as->lines, i, j, 3) > 0)
					{
						j += ft_check_command(as->lines, i, j, 3);
						if (!as->lines[i][j])
							j--;
						cmd = 1;
					}
				}
				if (!ft_is_lex(lines[i][j]))
				{
					return (ft_put_lexerr(as, i, j));
				}
				if (lines[i][j] == ':' || lines[i][j] == '%')
				{
					k = -1;
					if (j > 0 && cmd != 1 && (lines[i][j] == ':' && lbl == 0))
						k = 1;
					if ((lines[i][j] == ':' && (!ft_is_lblchr(lines[i][j - k])
						&& !ft_is_lblchr(lines[i][j + 1])))
					|| (lines[i][j] == '%' && !ft_is_lbl_o_dgt(lines[i][j + 1])
						&& lines[i][j + 1] != '-'))
							return (ft_put_lexerr(as, i, j));
					if (lines[i][j] == ':')
						lbl = 1;
				}
				if (ft_is_sep(lines[i][j]))
				{
					cmd = 0;
					lbl = 0;
				}
			}
		}
	}
	return (1);
}
