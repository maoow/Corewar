/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:10:19 by vkim              #+#    #+#             */
/*   Updated: 2017/11/23 17:36:41 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				ft_err_load(int ac, int fd, char *src_file, char *path)
{
	if (ac < 2)
	{
		ft_putstr("Usage: ");
		ft_putstr(path);
		ft_putstr(" [-a] <sourcefile.s>\n    -a : Instead of creating a ");
		ft_putstr(".cor file, outputs a stripped and annotated version of the");
		ft_putstr(" code to the standard output\n");
	}
	else if (fd == -1)
	{
		ft_putstr("Can't read source file ");
		ft_putstr(src_file);
		ft_putstr("\n");
	}
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
