/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_load_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:18:49 by vkim              #+#    #+#             */
/*   Updated: 2017/11/29 16:53:36 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_empty_file(t_asm *as)
{
	int			ln;

	ln = 0;
	if (!as->load[0])
	{
		if (!(ft_new_line(as, &ln, 0, 0)))
			return (0);
		free(as->lines[0]);
		as->lines[0] = NULL;
		return (1);
	}
	return (1);
}

int				ft_close_load_fd(t_asm *as, int fd)
{
	if (fd != -1)
		close(fd);
	if (!(ft_empty_file(as)))
		return (1);
	if (!(ft_str_gnl(as)))
		return (0);
	if (!(ft_del_com(as)))
		return (0);
	if (!(ft_del_space(as)))
		return (0);
	return (1);
}
