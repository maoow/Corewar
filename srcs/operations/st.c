/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:11 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/24 16:24:20 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_st(t_cor *core, t_process *proc)
{
	size_t		op;

	op = core->arena[proc->PC + proc->startpos + 1] / 16;
	if (op % 4 == 3)
	{
		setram(core, idx(proc, ind(core, proc, proc->PC + 3)),
				getparam(core, proc, 1, 2), proc->color);
		ft_printf("st | r%d %d\n", core->arena[proc->PC + proc->startpos + 3] + 1, ind(core, proc, proc->PC + 3));
	}
	else
	{
		proc->registres[core->arena[proc->PC + proc->startpos + 3]] =
		proc->registres[core->arena[proc->PC + proc->startpos + 2]];
	if (core->verbose)
		ft_printf("st | r%d r%d\n", core->arena[proc->PC + proc->startpos + 3],core->arena[proc->PC + proc->startpos + 2] + 1);
	}
	return (proc->registres[core->arena[proc->PC + proc->startpos + 2]] != 0);
}
