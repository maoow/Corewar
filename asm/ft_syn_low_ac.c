/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syn_low_ac.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:51:27 by vkim              #+#    #+#             */
/*   Updated: 2017/11/22 16:46:29 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void				ft_check_kills(t_asm *as, int i)
{
	int				wtz;

	wtz = ft_watzis(as->lines[i], 0);
	if (wtz != 1 && wtz < 11)
	{
		as->lines[i][0] = '\0';
		while (as->lines[++i])
			as->lines[i][0] = '\0';
	}
}

int					ft_syn_low_ac(t_asm *as, int count_args, char *tmp)
{
	if (count_args < as->ref[ft_if_op_ok(as, tmp)].ac)
	{
		ft_putstr("Invalid parameter count for instruction ");
		ft_putstr(tmp);
		ft_putstr("\n");
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}
