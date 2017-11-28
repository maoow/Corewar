/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:10 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/28 10:53:49 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
** OR
**
** store in the third reg the result of a logical or of the other two,
** carry go true if the result is equal to zero
*/

static size_t	or(size_t a, size_t b)
{
	size_t	out;
	size_t	place;

	place = 1;
	out = 0;
	while (place <= 4294967295)
	{
		if ((a / place) % 2 || (b / place) % 2)
			out += place;
		place *= 2;
	}
	return (out);
}

bool			cw_or(t_cor *core, t_process *proc)
{
	size_t	a;
	size_t	b;
	size_t	c;
	int		pos;

	a = getparam(core, proc, 1, 4);
	b = getparam(core, proc, 2, 4);
	pos = proc->PC + proc->startpos;
	c = core->arena[(pos + proc->next_jump - 1) % MEM_SIZE] - 1;
	if (c >= REG_NUMBER)
		return (proc->carry);
	proc->registres[c] = or(a, b);
	if (core->options->v4)
		ft_printf("P %4d | or %d %d r%d\n", proc->ID, a, b, c + 1);
	return (proc->registres[c] == 0);
}
