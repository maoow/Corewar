/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:05 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/30 15:56:50 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_ldi(t_cor *core, t_process *proc)
{
	size_t adress;

	adress = getparam(core, proc, 1, 2);
	adress += getparam(core, proc, 2, 2);
	proc->registres[core->arena[getparamplace(core, proc, 3, 2) % MEM_SIZE]] =
	getram(core, idx(proc, adress));
	if (core->verbose)
		ft_printf("P%5d | ldi %d %d r%d\n",  proc->ID,getparam(core, proc, 1, 2), getparam(core, proc, 2, 2), core->arena[getparamplace(core, proc, 3, 2) % MEM_SIZE]);
	return (proc->registres[core->arena[(getparamplace(core, proc, 3, 2)) % MEM_SIZE]] != 0);
}
