/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:13 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/12 11:10:43 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_xor(t_cor *core, t_process *proc)
{
	size_t	a;
	size_t	b;
	size_t	c;

	a = getparam(core, proc, 1, 4);
	b = getparam(core, proc, 2, 4);
	c = core->arena[(getparamplace(core, proc, 3, 4) - 1) % MEM_SIZE] - 1;
	proc->registres[c] = ((a | b) && !(a & b));
	if (core->options->v4)
		ft_printf("P%5d | xor %d %d r%d\n", proc->ID, a, b, c + 1);
	return (proc->registres[c] == 0);
}
