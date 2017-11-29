/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:05 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/28 12:53:54 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
** LDI
**
** add first and second param (%IDX) and load it in the first param reg
*/

static bool		regcheck(t_cor *core, t_process *proc)
{
	size_t		op;
	size_t		reg;

	op = core->arena[(proc->pc + proc->startpos + 1) % MEM_SIZE];
	if ((op / 4) % 4 == 1)
	{
		if ((op / 16) % 4 == 1)
			reg = core->arena[(proc->pc + proc->startpos + 4) % MEM_SIZE] - 1;
		else
			reg = core->arena[(proc->pc + proc->startpos + 5) % MEM_SIZE] - 1;
		if (reg >= REG_NUMBER)
			return (false);
	}
	return (true);
}

static void		print_v4(t_process *proc, int adress, int adress2, size_t reg)
{
	ft_printf("P %4d | ldi %d %d r%d\n", proc->id, adress, adress2, reg);
	ft_printf("       | -> load from %d + %d = %d (",
			adress, adress2, adress + adress2);
}

bool			cw_ldi(t_cor *core, t_process *proc)
{
	int			adress;
	int			adress2;
	int			adress3;
	size_t		reg;

	reg = core->arena[(proc->pc + proc->startpos + proc->next_jump - 1)
		% MEM_SIZE];
	if (reg - 1 >= REG_NUMBER || !regcheck(core, proc))
		return (proc->carry);
	adress = getparam(core, proc, 1, 2);
	adress2 = getparam(core, proc, 2, 2);
	adress3 = (adress + adress2) % IDX_MOD;
	proc->registres[reg - 1] =
		getram(core, (adress3 + proc->startpos + proc->pc) % MEM_SIZE);
	if (core->options->v4)
	{
		print_v4(proc, adress, adress2, reg);
		ft_printf("with pc and mod %d)\n", adress3 + proc->pc + proc->startpos);
	}
	return (proc->registres[reg - 1] != 0);
}
