/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:24:58 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/10 14:11:45 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool		cw_add(t_cor *core, t_process *proc)
{
	int		res;

	res = 
		proc->registres[core->arena[(proc->PC + proc->startpos + 3) % MEM_SIZE] - 1] +
		proc->registres[core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE] - 1];
	proc->registres[core->arena[(proc->PC + proc->startpos + 4) % MEM_SIZE] - 1] = res;
	if (core->options->v4)
		ft_printf("P%5d | add r%d r%d r%d\n",
			proc->ID,core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE],
			core->arena[(proc->PC + proc->startpos + 3) % MEM_SIZE],
			core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE]);
	if (res == 0)
		proc->carry = true;
	else
		proc->carry = false;
	return (proc->carry);
}
