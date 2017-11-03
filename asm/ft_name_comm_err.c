/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name_comm_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 12:46:42 by vkim              #+#    #+#             */
/*   Updated: 2017/11/03 14:34:22 by vkim             ###   ########.fr       */
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

int					ft_btw_cmd_qut(t_asm *as, int ln, int chr, char *s_check)
{
	int			j;
	int			add;

	add = ft_add_bkn(as, ln, chr);
	if (!(ft_err_str_gnl(as)))
		return (-1);
	j = 0;
	ft_while_space(as->lines[ln], &j);
	if (!ft_strcmp(s_check, NAME_CMD_STRING) && ft_check_command(as->lines, ln, j, 1) > 0)
		j += ft_check_command(as->lines, ln, j, 1);
	if (!ft_strcmp(s_check, COMMENT_CMD_STRING) && ft_check_command(as->lines, ln, j, 2) > 0)
		j += ft_check_command(as->lines, ln, j, 2);
	ft_while_space(as->lines[ln], &j);
	//lex / watzis
	ft_put_lexerr(as, ln, j);
	return (0);
}
