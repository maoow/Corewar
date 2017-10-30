/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:10:19 by vkim              #+#    #+#             */
/*   Updated: 2017/10/30 12:38:55 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_whatzis(char *txt, int i)
{
	int			j;

	j = -1;
	while (ft_strchr(LABEL_CHARS, txt[i + j]) && txt[i + j])
		;
	if (txt[i + j] != ':' && txt[i + j] != ',' && txt[i + j] != ' '
		&& txt[i + j] != '\t' && txt[i + j] != '\n' && txt[i + j] != '\0')
		
}

int				ft_err_load(int ac, int fd, char *str)
{
	if (ac < 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(str);
		ft_putstr(" <sourcefile.s>\n");
	}
	else if (fd == -1)
		ft_putstr("Syntax error at token [TOKEN][001:001] END \"(null)\"\n");
	return (0);
}

int				ft_err_name_comm(char *s_check, int num, char *txt, int i)
{
	if (s_check == NAME_CMD_STRING && num == 1)
		ft_putstr("Lexical error at [1:1]\n");
	else if (num == 1)
		ft_putstr("Lexical error at [2:1]\n");
	if (num == 2)
		//analyse erreur entre NAME_CMD et suite
	if (num == 3)
		ft_putstr("ERR A CHECK\n");
	return(0);
}
