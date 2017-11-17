/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watzis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:36:38 by vkim              #+#    #+#             */
/*   Updated: 2017/11/17 10:19:57 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_is_command(char *txt, int i)
{
	int			j;
	int			k;

	j = 0;
	while (txt[i + j] == COMMENT_CMD_STRING[j]
		&& txt[i + j] && COMMENT_CMD_STRING[j])
		j++;
	k = 0;
	while (txt[i + k] == NAME_CMD_STRING[k] && txt[i + k] && NAME_CMD_STRING[k])
		k++;
	if (COMMENT_CMD_STRING[j] == '\0')
		return (7); //COMMAND_COMMENT
	if (NAME_CMD_STRING[k] == '\0')
		return (8); //COMMAND_NAME
	return (0);
}

int				ft_is_ind(char *txt, int i)
{
	while (ft_isdigit(txt[i]))
		i++;
	if (ft_strchr(LABEL_CHARS, txt[i]) || txt[i] == ':')
		return (0);
	return (1);
}

int				ft_is_reg(char *txt, int i)
{
	if (txt[i] == 'r' && (txt[i + 1] >= '0' && txt[i + 1] <= '9'))
		if (((txt[i + 2] >= '0' && txt[i + 2] <= '9')
			&& !ft_strchr(LABEL_CHARS, txt[i + 3]) && txt[i + 3] != ':')
			|| (!ft_strchr(LABEL_CHARS, txt[i + 2]) && txt[i + 2] != ':'))
				return (1);
	return (0);
}

int				ft_is_label(char *txt, int i)
{
	while (ft_is_lblchr(txt[i]))
		i++;
	if (txt[i] == ':')
		return (1);
	return (0);
}

int				ft_watzis(char *txt, int i)
{
	if (!txt)
		return (13); //NULL
	if (txt[i] == '\n' || txt[i] == '\0')
		return (1); //ENDLINE
	if (txt[i] == '"')
		return (2); //STRING
	if (txt[i] == '%' && txt[i + 1] == ':')
		return (3); //DIRECT_LABEL
	if (txt[i] == '%')
		return (4); //DIRECT
	if (txt[i] == ':')
		return (5); //INDIRECT_LABEL
	if (txt[i] == ',')
		return (6); //SEPARATOR
	if (ft_is_command(txt, i) > 0)
		return (ft_is_command(txt, i));
	if (ft_is_ind(txt, i) == 1)
		return (9); //INDIRECT
	if (ft_is_reg(txt, i) == 1)
		return (10); //REGISTER
	if (ft_is_label(txt, i) == 1)
		return (11); //LABEL
	else
		return (12); //INSTRUCTION
}
