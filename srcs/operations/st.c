/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:11 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/10 14:11:46 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	st(t_cor *core, t_process *proc)
{
	size_t		op;

	op = core->arena[proc->pc + proc->startpos + 1] / 4;
	if (op % 4 == 3)
	{
		setram(core, ind(core, proc, proc->pc + 2) + proc->startpos,
				getparam(core, proc, 1, 2));
	}
	else
	{
		proc->reg[core->arena[proc->PC + proc->startpos + 3]] =
		proc->reg[core->arena[proc->PC + proc->startpos + 2]];
	}
	return (proc->reg[core->arena[proc->PC + proc->startpos + 2]] != 0);
}
