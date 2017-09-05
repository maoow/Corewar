/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_name_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 10:10:17 by vkim              #+#    #+#             */
/*   Updated: 2017/09/05 16:57:22 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_name_check(t_asm *as, char **name, char *s_check)
{
	int			i;
	int			j;
	int			comment;

	comment = 1;
	if (s_check == NAME_CMD_STRING)
		comment = 0;
	i = -1;
	while (as->lines[comment][++i] && as->lines[comment][i] != '\"')
	{
		if ((i < ft_strlen(s_check) && as->lines[comment][i] != s_check[i])
			|| (i >= ft_strlen(s_check) && as->lines[comment][i] != ' ')
			|| as->lines[comment][i] == '\0')
			return (0);
	}
	j = i + 1;
	while (as->lines[comment][++i] != '\"')
	{
		if (as->lines[comment][i] == '\0')
			return (0);
	}
	if (!(*name = ft_strsub(as->lines[comment], j, i - j)))
		return (0);
	return (1);
}
