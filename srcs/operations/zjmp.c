/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:14 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/14 14:02:51 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_zjmp(t_cor *core, t_process *proc)
{
	long int jump;

	jump = ind(core, proc, proc->PC + 1) % MEM_SIZE;
	if (jump > MEM_SIZE / 2)
		jump -= MEM_SIZE;
	if (core->options->v4)
		ft_printf("P%5d | zjmp %d ", proc->ID, jump);
	if (proc->carry)
	{
		if (core->options->v4)
			ft_printf("OK\n");
		if (jump != 0)
		{
			if (jump > IDX_MOD)
				jump -= IDX_MOD;
			proc->PC += jump;
			proc->PC += proc->startpos;
			proc->PC %= MEM_SIZE;
			proc->PC -= proc->startpos;
		}
	}
	else
	{
		if (core->options->v16)
		{
		proc->next_jump = 3;
			dispjump(core, proc);
		proc->next_jump = 0;
		}
		proc->PC += 3;
		ft_getop(core, proc);
		if (core->options->v4)
			ft_printf("FAILED\n");
	}
	return (true);
}
