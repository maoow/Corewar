/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:12 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/30 11:48:07 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
static bool		regcheck(t_cor *core, t_process *proc)
{
	size_t op;
	size_t reg;

	op = core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE];
	if ((op / 4) % 4 == 1) // oui
	{
		if ((op / 16) % 4 == 1) // non
			reg = core->arena[(proc->PC + proc->startpos + 4) % MEM_SIZE] - 1;
		else
			reg = core->arena[(proc->PC + proc->startpos + 5) % MEM_SIZE] - 1;
		if (reg >= REG_NUMBER)
			return (false);
	}
	return (true);
}

bool	cw_sti(t_cor *core, t_process *proc)
{
	size_t		adress;
	size_t		adress2;
	long int	total;
	size_t		reg;

	reg = core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE] - 1;
	if (reg >= REG_NUMBER || !regcheck(core, proc))
		return (proc->carry);
	adress = getparam(core, proc, 2, 2);
	if (adress > 34952)
		adress -= 65536;
	adress2 = getparam(core, proc, 3, 2);
	total = adress2 + adress;
	total %= IDX_MOD;
	setram(core, proc->PC + proc->startpos + total, proc->registres[reg],
			proc->color);
	if (core->options->v4)
	{
		ft_printf("P%5d | sti r%d %d %d\n       | -> store to %d + %d = %d \
(with pc and mod %d)\n",
				proc->ID, reg + 1, adress, adress2, adress, adress2, adress + adress2,
				((proc->PC + proc->startpos) % MEM_SIZE) + total);
	}
	return (true);
}
