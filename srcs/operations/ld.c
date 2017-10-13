/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:40:44 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/13 13:16:57 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_ld(t_cor *core, t_process *proc)
{
	size_t value;
	size_t pc;

	if (proc->next_jump < 3)
		return (true);
	pc = proc->PC;
	if ((core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE] / 16) % 4 != 2)
	{
		value = getram(core, pc + 2 + proc->startpos);
		pc += 6;
	}
	else
	{
		value = getram(core, idx(proc, ind(core, proc, pc + 2)));
		pc += 4;
	}
	if (core->arena[(pc + proc->startpos) % MEM_SIZE] <= REG_NUMBER)
	{
		proc->registres[core->arena[(pc + proc->startpos) % MEM_SIZE] - 1] =
			value;
	}
	if (core->options->v4)
		ft_printf("P%5d | ld %d r%d\n", proc->ID, value,
				core->arena[(pc + proc->startpos) % MEM_SIZE]);
	return (value == 0);
}
