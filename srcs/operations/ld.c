/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 13:40:44 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/19 12:25:54 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_ld(t_cor *core, t_process *proc)
{
	size_t		value;
	size_t		pc;
	size_t		reg;

	//if (proc->next_jump > 6 && core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE] % 4 != 0)
	//{
		//proc->next_jump = 6;
		//return (true);
	//}
//		ft_printf("need more info ? \n");
	if (proc->next_jump < 3)
		return (true);
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
		return (false);
	proc->registres[mod(core->arena[(pc + proc->startpos) %
			MEM_SIZE] - 1, 16)] = value;
	if (core->options->v4)
		ft_printf("P%5d | ld %d r%d\n", proc->ID, value,
				core->arena[(pc + proc->startpos) % MEM_SIZE]);
	//if (proc->ID == 12 && value == 64521)
	//dispjump(core, proc);
	return (value == 0);
}
