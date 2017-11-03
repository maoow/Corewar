/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:10:19 by vkim              #+#    #+#             */
/*   Updated: 2017/11/03 14:35:33 by vkim             ###   ########.fr       */
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
		(void)j;
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

int				ft_err_str_gnl(t_asm *as)
{
	int			i;

	i = -1;
	if (as->lines)
	{
		while (as->lines[++i])
			free(as->lines[i]);
		as->lines[0] = NULL;
	}
	if (!(ft_str_gnl(as)))
		return (0);
	return (1);
}
