/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:11 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/20 13:02:08 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_st(t_cor *core, t_process *proc)
{
	size_t		op;

	op = core->arena[proc->PC + proc->startpos + 1] / 4;
	if (op % 4 == 3)
	{
		setram(core, idx(proc, ind(core, proc, proc->PC + 2)),
				getparam(core, proc, 1, 2), proc->color);
	}
	else
	{
		proc->registres[core->arena[proc->PC + proc->startpos + 3]] =
		proc->registres[core->arena[proc->PC + proc->startpos + 2]];
	}
	return (proc->registres[core->arena[proc->PC + proc->startpos + 2]] != 0);
}
