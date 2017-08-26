/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:02 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/26 13:44:09 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_fork(t_cor *core, t_process *proc)
{
	t_process 	*tmp;
	size_t		i;

	i = 0;
	tmp = (t_process *)malloc(sizeof(t_process)); //
	while (i < REG_NUMBER)
	{
		tmp->registres[i] = proc->registres[i];
		i++;
	}
	tmp->PC = (proc->PC - proc->startpos + idx(proc, ind(core, proc, proc->PC + 1))) % MEM_SIZE;
	tmp->startpos = proc->startpos;
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
		ft_printf("p%d fork | %d (%d)\n", proc->ID,ind(core, proc, proc->PC + 1), ind(core, proc, proc->PC + 1) + proc->startpos);
	return (true);
}
