/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:08 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/18 15:25:25 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
** LLD
**
** load the second param (ind or dir) in the first param reg
*/

bool	cw_lld(t_cor *core, t_process *proc)
{
	size_t		value;
	size_t		pc;
	size_t		reg;

	if (proc->next_jump < 3)
		return (proc->carry);
	pc = proc->PC;
	if ((core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE] / 64) % 4 == 2)
	{
		value = getram(core, pc + 2 + proc->startpos);
		pc += 6;
	}
	else
	{
		value = getram(core, ind(core, proc, proc->startpos + pc + 2));
		pc += 4;
	}
	reg = core->arena[(pc + proc->startpos) % MEM_SIZE];
	if (reg > REG_NUMBER || reg < 1)
		return (proc->carry);
	proc->registres[reg - 1] = value;
	if (core->options->v4)
		ft_printf("P%5d | lld %d r%d\n", proc->ID, value,reg);
	return (value == 0);
}
