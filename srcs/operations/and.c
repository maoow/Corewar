/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:01 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/16 14:34:25 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static size_t	and(size_t a, size_t b)
{
	size_t	out;
	size_t	place;

	place = 1;
	out = 0;
	while (place <= 4294967295)
	{
		if ((a / place) % 2 && (b / place) % 2)
			out += place;
		place *= 2;
	}
	return (out);
}
bool	cw_and(t_cor *core, t_process *proc)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = getparam(core, proc, 1, 2);
	b = getparam(core, proc, 2, 2);
	c = core->arena[getparamplace(core, proc, 3, 4) % MEM_SIZE];
	proc->registres[c] = and(a, b);
	if (core->options->v4)
		ft_printf("P%5d | and %d %d r%d\n", proc->ID, a, b, c);
	return (proc->registres[c] == 0);
}
