/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:11 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/23 15:57:24 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_st(t_cor *core, t_process *proc)
{
	size_t		reg;
	size_t		reg2;
	long int	adress;

	reg = core->arena[(proc->startpos + proc->PC + 2) % MEM_SIZE] - 1;
	//reg = mod(core->arena[(proc->startpos + proc->PC + 2) % MEM_SIZE] - 1, 16);
	if (reg >= REG_NUMBER)
		return (false);
	reg2 = mod(core->arena[(proc->startpos + proc->PC + 3) % MEM_SIZE] - 1, 16);
	if ((core->arena[(proc->startpos + proc->PC + 1) % MEM_SIZE] / 16) % 4 == 3)
	{
		adress = ind(core, proc, proc->PC + 3);
		if (adress > 65536 / 2)
			adress -= 65536;
		if (core->options->v4)
			ft_printf("P%5d | st r%d %d\n", proc->ID, reg + 1, adress);
		adress %= IDX_MOD;
		setram(core, adress + proc->PC + proc->startpos,
				proc->registres[reg], proc->color);
			//ft_printf("P%5d | st r%d (%x) %d (%d  0x%04x)\n", proc->ID, reg + 1, proc->registres[reg],adress, (adress + proc->startpos + proc->PC) % MEM_SIZE, idx(proc, adress));
	}
	else
	{
		proc->registres[reg] = proc->registres[reg2];
		if (core->options->v4)
			ft_printf("P%5d | st r%d r%d\n", proc->ID, reg + 1, reg2 + 1);
	}
	return (proc->registres[reg] != 0);
}
