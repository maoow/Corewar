/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:13 by cbinet            #+#    #+#             */
/*   Updated: 2017/09/28 14:59:34 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_xor(t_cor *core, t_process *proc)
{
	size_t	a;
	size_t	b;

	if (core->options->v4)
		ft_printf("P%5d | xor %d %d r%d\n",
getparam(core, proc, 1, 4),
getparam(core, proc, 2, 4),
getparamplace(core, proc, 3, 4)
		);
	a = getparam(core, proc, 1, 4);
	b = getparam(core, proc, 2, 4);
	proc->registres[core->arena[(getparamplace(core, proc, 3, 4)) % MEM_SIZE]] = (a || b) && ((a && !b) || (!a && b));
	return (proc->registres[core->arena[(getparamplace(core, proc, 3, 4)) % MEM_SIZE]] != 0);
}
