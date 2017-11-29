/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:36:11 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 13:30:23 by vkim             ###   ########.fr       */
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

void		ft_check_command(char **lines, int i, int *j, int *cmd)
{
	int		k;

	k = 0;
	while (lines[i][k + *j] == NAME_CMD_STRING[k]
		&& lines[i][k] && NAME_CMD_STRING[k])
		k++;
	if (NAME_CMD_STRING[k] == '\0')
	{
		*j += k;
		if (!lines[i][*j])
			(*j)--;
		*cmd = 1;
	}
	k = 0;
	while (lines[i][k + *j] == COMMENT_CMD_STRING[k]
		&& lines[i][k] && COMMENT_CMD_STRING[k])
		k++;
	if (COMMENT_CMD_STRING[k] == '\0')
	{
		*j += k;
		if (!lines[i][*j])
			(*j)--;
		*cmd = 1;
	}
}

int			ft_lex_spec(t_asm *as, int *cmd, int *lbl)
{
	int		k;

	if (as->lines[as->n_ln][as->n_chr] == ':'
		|| as->lines[as->n_ln][as->n_chr] == '%')
	{
		k = -1;
		if (as->n_chr > 0 && *cmd != 1
			&& (as->lines[as->n_ln][as->n_chr] == ':' && *lbl == 0))
			k = 1;
		if ((as->lines[as->n_ln][as->n_chr] == ':'
			&& (!ft_is_lblchr(as->lines[as->n_ln][as->n_chr - k])
			&& !ft_is_lblchr(as->lines[as->n_ln][as->n_chr + 1])))
		|| (as->lines[as->n_ln][as->n_chr] == '%'
			&& !ft_is_lbl_o_dgt(as->lines[as->n_ln][as->n_chr + 1])
			&& as->lines[as->n_ln][as->n_chr + 1] != '-'))
			return (ft_put_lexerr(as, as->n_ln, as->n_chr));
		if (as->lines[as->n_ln][as->n_chr] == ':')
			*lbl = 1;
	}
	return (1);
}

int			ft_lex_char(t_asm *as, int *cmd, int *lbl, int *str)
{
	if (as->lines[as->n_ln][as->n_chr] == '\"')
		*str = (*str == 0) ? 1 : 0;
	if (*str == 0)
	{
		ft_check_command(as->lines, as->n_ln, &as->n_chr, cmd);
		if (!ft_is_lex(as->lines[as->n_ln][as->n_chr]))
			return (ft_put_lexerr(as, as->n_ln, as->n_chr));
		if (!(ft_lex_spec(as, cmd, lbl)))
			return (0);
		if (ft_is_sep(as->lines[as->n_ln][as->n_chr]))
		{
			*cmd = 0;
			*lbl = 0;
		}
	}
	return (1);
}

int			ft_lexical_err(t_asm *as, char **lines)
{
	int		cmd;
	int		lbl;
	int		str;

	cmd = 0;
	as->n_ln = -1;
	str = 0;
	while (lines[++as->n_ln])
	{
		as->n_chr = -1;
		cmd = 0;
		lbl = 0;
		while (lines[as->n_ln][++as->n_chr])
		{
			if (lines[as->n_ln][as->n_chr] == '-')
			{
				lbl = 0;
				if (!ft_isdigit(lines[as->n_ln][as->n_chr + 1]) && str == 0)
					return (ft_put_lexerr(as, as->n_ln, as->n_chr));
			}
			if (!(ft_lex_char(as, &cmd, &lbl, &str)))
				return (0);
		}
	}
	return (1);
}
