/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:14 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/13 14:20:03 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_zjmp(t_cor *core, t_process *proc)
{
	long int jump;

	jump = ind(core, proc, proc->PC + 1) % MEM_SIZE;
	if (jump > MEM_SIZE / 2)
		jump -= MEM_SIZE;
	//if (jump == 0)
		//jump--;
	if (core->options->v4)
		ft_printf("P%5d | zjmp %d ", proc->ID, jump);
	if (proc->carry)
	{
		if (core->options->v4)
			ft_printf("OK\n");
		//if (proc->ID == 4 && jump == 0)
			//ft_printf("  %d  \n", core->total_cycle);
		jump += proc->startpos;
		jump %= MEM_SIZE;
		jump -= proc->startpos;
		proc->PC += jump;
		proc->PC %= MEM_SIZE;
	}
	else
	{
		proc->PC += 2;
		ft_getop(core, proc);
		//proc->next_jump = 1;
		if (core->options->v4)
			ft_printf("FAILED\n");
	}
	return (true);
}
