/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 15:10:19 by vkim              #+#    #+#             */
/*   Updated: 2017/10/23 17:27:51 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

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
