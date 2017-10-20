/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:14 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/20 13:22:20 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void		no_carry(t_cor *core, t_process *proc)
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

bool			cw_zjmp(t_cor *core, t_process *proc)
{
	long int jump;

	jump = ind(core, proc, proc->PC + 1);
	if (jump > 65536 / 2)
		jump -= 65536;
	if (core->options->v4)
		ft_printf("P%5d | zjmp %d ", proc->ID, jump);
	if (proc->carry)
	{
		if (core->options->v4)
			ft_printf("OK\n");
		if (jump != 0)
		{
			jump %= IDX_MOD;
			proc->PC += jump;
			proc->PC += proc->startpos;
			proc->PC %= MEM_SIZE;
			proc->PC -= proc->startpos;
		}
	}
	else
		no_carry(core, proc);
	return (true);
}
