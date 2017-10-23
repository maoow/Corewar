/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:11 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/18 15:46:00 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_st(t_cor *core, t_process *proc)
{
	size_t		reg;
	size_t		reg2;
	size_t		adress;

	reg = mod(core->arena[(proc->startpos + proc->PC + 2) % MEM_SIZE] - 1, 16);
	reg2 = mod(core->arena[(proc->startpos + proc->PC + 3) % MEM_SIZE] - 1, 16);
	if ((core->arena[(proc->startpos + proc->PC + 1) % MEM_SIZE] / 16) % 4 == 3)
	{
		adress = ind(core, proc, proc->PC + 3);
		adress %= MEM_SIZE;
		if (adress > MEM_SIZE / 2)
			adress -= MEM_SIZE;
		setram(core, adress + proc->startpos + proc->PC,
				proc->registres[reg], proc->color);
		if (core->options->v4)
			ft_printf("P%5d | st r%d %d\n", proc->ID, reg + 1, adress);
	}
	else
	{
		proc->registres[reg] = proc->registres[reg2];
		if (core->options->v4)
			ft_printf("P%5d | st r%d r%d\n", proc->ID, reg + 1, reg2 + 1);
	}
	return (proc->registres[reg] != 0);
}
