/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 10:10:17 by vkim              #+#    #+#             */
/*   Updated: 2017/10/31 15:33:52 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_name_check(t_asm *as, char *line, char *s_check, int check)
{
	int			i;
	int			j;

	i = -1;
	while (line[++i] && line[i] != '\"')
		if ((i < ft_strlen(s_check) && line[i] != s_check[i])
			|| (i >= ft_strlen(s_check) && line[i] != ' ' && line[i] != '\t')
			|| line[i] == '\0')
			return (0);
	j = i + 1;
	while (line[++i] != '\"')
		if (line[i] == '\0')
			return (0);
	if (check == 0)
	{
		if (s_check == NAME_CMD_STRING
			&& !(as->name = ft_strsub(line, j, i - j)))
				return (0);
		else if (!(as->comment = ft_strsub(line, j, i - j)))
				return (0);
	}
	line[0] = '\0';
	return (1);
}

void			ft_check_command_kill(t_asm *as, int *i)
{
	int			j;
	int			k;

	j = 0;
	while (as->lines[*i][j] == COMMENT_CMD_STRING[j]
		&& as->lines[*i][j] && COMMENT_CMD_STRING[j])
		j++;
	k = 0;
	while (as->lines[*i][k] == NAME_CMD_STRING[k] && as->lines[*i][k]
		&& as->lines[*i][k] && NAME_CMD_STRING[k])
		k++;
	if (NAME_CMD_STRING[k] == '\0' || COMMENT_CMD_STRING[j] == '\0')
	{
			as->lines[*i][0] = '\0';
		while (as->lines[++*i])
			as->lines[*i][0] = '\0';
	}
	else
		++*i;
}

int				ft_name_comment_check(t_asm *as)
{
	int			i;

	i = 0;
	while (as->lines[i][0] == '\0')
		i++;
	if (!(ft_name_check(as, as->lines[i], NAME_CMD_STRING, 0)))
		return (0);
	while (as->lines[i][0] == '\0')
		i++;
	if (!(ft_name_check(as, as->lines[i], COMMENT_CMD_STRING, 0)))
		return (0);
	i++;
	while (as->lines[i])
		ft_check_command_kill(as, &i);
	return (1);
}
