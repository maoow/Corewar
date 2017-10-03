/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkim <vkim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:38:40 by vkim              #+#    #+#             */
/*   Updated: 2017/10/03 14:54:48 by vkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void			ft_while_space(char *txt, int *i)
{
	while (txt[*i] && (txt[*i] == ' ' || txt[*i] == '\t'))
		(*i)++;
}

int				ft_if_op_ok(t_asm *as, char *op)
{
	int			i;
	int			res;

	res = -1;
	i = -1;
	while (++i < 16)
	{
		if (!ft_strcmp(as->ref[i].name, op))
			res = i;
	}
	return (res);
}
