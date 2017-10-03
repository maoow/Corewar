/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:40:44 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/03 16:57:22 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_ld(t_cor *core, t_process *proc)
{
	size_t value;
	size_t PC;

	PC = proc->PC;
	//if ((core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE] / 16 ) % 4 == 2)
	if ((core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE] / 16 ) % 4 != 2)
	{
//ft_printf("res = %d\n", (core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE] / 16) % 4);	=>	res == 1
		value = getram(core, PC + 2 + proc->startpos);
		PC += 6;
	}
	else
	{
		value = getram(core, idx(proc,ind(core, proc, PC + 2)));
		PC += 4;
	}
	if (core->arena[(PC + proc->startpos) % MEM_SIZE] <= REG_NUMBER)
	{
		proc->registres[core->arena[(PC + proc->startpos) % MEM_SIZE] - 1] = value;
	}
	if (core->options->v4)
		ft_printf("P%5d | ld %d r%d\n", proc->ID, value, core->arena[(PC + proc->startpos) % MEM_SIZE]);
	return (value == 0);
	//return (value != 0);
}
