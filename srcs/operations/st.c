/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:11 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/14 15:39:46 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_st(t_cor *core, t_process *proc)
{
	size_t		reg;
	size_t		reg2;
	size_t		adress;

reg = core->arena[(proc->startpos + proc->PC + 2) % MEM_SIZE];
reg2 = core->arena[(proc->startpos + proc->PC + 3) % MEM_SIZE];
	if ((core->arena[(proc->startpos + proc->PC + 1) % MEM_SIZE] / 16) % 4 == 3)
	{
		adress = ind(core, proc, proc->PC + 3);
		adress %= MEM_SIZE;
	if (adress > MEM_SIZE / 2)
		adress -= MEM_SIZE;
		setram(core, adress,
		proc->registres[reg - 1], proc->color);
		if (core->options->v4)
			ft_printf("P%5d | st r%d %d\n", proc->ID, reg, adress);
	}
	else
	{
		proc->registres[reg - 1] = proc->registres[reg2 - 1];
		if (core->options->v4)
			ft_printf("P%5d | st r%d r%d\n", proc->ID, reg, reg2);
	}
	return (proc->registres[reg - 1] != 0);
}
