/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:13 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/13 12:09:33 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static size_t	xor(size_t a, size_t b)
{
	size_t	out;
	size_t	place;

	place = 1;
	out = 0;
	while (a / place || b / place)
	{
		if (((a / place) % 2 || (b / place) % 2) && !((a / place) % 2 && (b / place) % 2))
			out += place;
		place *= 2;
	}
	return (out);
}

bool	cw_xor(t_cor *core, t_process *proc)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = getparam(core, proc, 1, 4);
	b = getparam(core, proc, 2, 4);
	c = core->arena[(getparamplace(core, proc, 3, 4) - 1) % MEM_SIZE] - 1;
	proc->registres[c] = xor(a, b);
	if (core->options->v4)
		ft_printf("P%5d | xor %d %d r%d\n", proc->ID, a, b, c + 1);
	return (proc->registres[c] == 0);
}
