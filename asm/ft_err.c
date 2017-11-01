/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:36:11 by vkim              #+#    #+#             */
/*   Updated: 2017/11/01 14:39:49 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_put_lexerr(t_asm *as, int i, int j)
{
	int			k;

	ft_putstr("Lexical error at [");
	ft_putnbr(i + 1);
	ft_putstr(":");
	if (!(ft_err_str_gnl(as)))
		return (-1);
	k = -1;
	while (as->lines[i][++k] == ' ' || as->lines[i][k] == '\t')
		j++;
	ft_putnbr(j + 1);
	ft_putstr("]\n");
	return (0);
}

int				ft_check_command(char **lines, int i, int j)
{
	int			k;
	int			l;

	k = 0;
	while (lines[i][k + j] == NAME_CMD_STRING[k]
		&& lines[i][k] && NAME_CMD_STRING[k])
			k++;
	l = 0;
	while (lines[i][l + j] == NAME_CMD_STRING[l]
		&& lines[i][l] && NAME_CMD_STRING[l])
			l++;
	if (NAME_CMD_STRING[k] == '\0')
		return (ft_strlen(NAME_CMD_STRING));
	if (COMMENT_CMD_STRING[l] == '\0')
		return (ft_strlen(COMMENT_CMD_STRING));
	return (0);
}

int				ft_lexical_err(t_asm *as, char **lines)
{
	int			i;
	int			j;
	int			k;
	int			cmd;

	cmd = 0;
	i = -1;
	while (lines[++i])
	{
		j = -1;
		cmd = 0;
		while (lines[i][++j])
		{
			if (lines[i][j] == NAME_CMD_STRING[0]
					|| lines[i][j] == COMMENT_CMD_STRING[0])
			{
				if (ft_check_command(as->lines, i, j) > 0)
				{
					j += ft_check_command(as->lines, i, j);
					cmd = 1;
				}
			}
			if (!ft_strchr(LABEL_CHARS, lines[i][j]) && lines[i][j] != ','
				&& lines[i][j] != ' ' && lines[i][j] != '\t'
				&& lines[i][j] != ':'
				&& (lines[i][j] < '0' || lines[i][j] > '9')
				&& lines[i][j] != '%'
				&& lines[i][j] != '"'
				&& lines[i][j] != '\0')
			{
				printf("lex : <%s> <<%c>>\n", lines[i], lines[i][j]);
				return (ft_put_lexerr(as, i, j));
			}
			if (lines[i][j] == ':' || lines[i][j] == '%')
			{
				k = -1;
				if (j > 0 && cmd != 1 && lines[i][j] == ':')
					k = 1;
				printf("K : %d %c\n", k, lines[i][j]);
				if ((!ft_strchr(LABEL_CHARS, lines[i][j - k])
				&& (lines[i][j - k] < '0' || lines[i][j - k] > '9'))
				&& (!ft_strchr(LABEL_CHARS, lines[i][j + 1])
					&& (lines[i][j + 1] < '0' || lines[i][j + 1] > '9')))
				{
					if (!(lines[i][j] == '%' && lines[i][j + 1] == ':'))
					{
						printf("Prev : %c, apres %c\n", lines[i][j - k], lines[i][j + 1]);
						return (ft_put_lexerr(as, i, j));
					}
				}

			}
		}
	}
	return (1);
}
