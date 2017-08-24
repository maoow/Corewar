/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:11 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/24 16:45:53 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_st(t_cor *core, t_process *proc)
{
	size_t		op;

	op = core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE] / 16;
	if (op % 4 == 3)
	{
		setram(core, idx(proc, ind(core, proc, proc->PC + 3)),
				getparam(core, proc, 1, 2), proc->color);
		ft_printf("st | r%d %d\n", core->arena[(proc->PC + proc->startpos + 3) % MEM_SIZE] + 1, ind(core, proc, proc->PC + 3));
	}
	else
	{
		proc->registres[core->arena[(proc->PC + proc->startpos + 3) % MEM_SIZE]] =
		proc->registres[core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE]];
	if (core->verbose)
		ft_printf("st | r%d r%d\n", core->arena[(proc->PC + proc->startpos + 3) % MEM_SIZE],core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE] + 1);
	}
	if (core->verbose)
		ft_printf("st | %d %d\n", proc->PC, proc->startpos);
	return (proc->registres[core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE]] != 0);
}
