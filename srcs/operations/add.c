/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:24:58 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/18 16:48:25 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool		cw_add(t_cor *core, t_process *proc)
{
	long int		res;

	res =
		(long int)proc->registres[mod(core->arena[(proc->PC + proc->startpos + 3) %
		MEM_SIZE] - 1, 16)] +
		proc->registres[mod(core->arena[(proc->PC + proc->startpos + 2) %
		MEM_SIZE] - 1, 16)];
	proc->registres[mod(core->arena[(proc->PC + proc->startpos + 4) %
		MEM_SIZE] - 1, 16)] = res;
	if (core->options->v4)
		ft_printf("P%5d | add r%d r%d r%d\n",
			proc->ID, core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE],
			core->arena[(proc->PC + proc->startpos + 3) % MEM_SIZE],
			core->arena[(proc->PC + proc->startpos + 4) % MEM_SIZE]);
	if (res == 0)
		proc->carry = true;
	else
		proc->carry = false;
	return (proc->carry);
}
