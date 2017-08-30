/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:02 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/30 15:56:50 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_fork(t_cor *core, t_process *proc)
{
	t_process 	*tmp;
	size_t		i;
	int			indt;

	i = 0;
	tmp = (t_process *)malloc(sizeof(t_process)); //
	while (i < REG_NUMBER)
	{
		tmp->registres[i] = proc->registres[i];
		i++;
	}
	tmp->PC = 0;
	tmp->startpos = (proc->PC - proc->startpos + idx(proc, ind(core, proc, proc->PC + 1)) + proc->startpos) % MEM_SIZE;
	tmp->next_jump = 0;
	tmp->cycles_before_execute = 0;
	tmp->next_op = false;
	tmp->carry = proc->carry;
	tmp->live = proc->live;
	tmp->color = proc->color;
	tmp->ID = core->process->ID + 1;
	tmp->next = core->process;
	core->arena_color[(tmp->PC + tmp->startpos) % MEM_SIZE] = 16;
	core->process = tmp;
	if (core->verbose)
	{
		indt = ind(core, proc, proc->PC + 1) % MEM_SIZE;
		if (indt > MEM_SIZE / 2)
			indt -= MEM_SIZE;
		ft_printf("P%5d | fork %d (%d)\n", proc->ID, indt, idx(proc,ind(core, proc, proc->PC + 1)));
	}
	return (true);
}
