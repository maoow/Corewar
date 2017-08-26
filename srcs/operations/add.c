/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:24:58 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/26 14:30:00 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool		cw_add(t_cor *core, t_process *proc)
{
	proc->registres[core->arena[(proc->PC + proc->startpos + 4) % MEM_SIZE]] =
		proc->registres[core->arena[(proc->PC + proc->startpos + 3) % MEM_SIZE]] +
		proc->registres[core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE]];
	if (core->verbose)
		ft_printf("P%4d | add r%d r%d r%d\n", proc->ID,core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE], core->arena[(proc->PC + proc->startpos + 3) % MEM_SIZE],core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE]);
	return (proc->registres[proc->PC + proc->startpos + 4] != 0);
}
