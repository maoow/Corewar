/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:02 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/23 11:03:12 by cbinet           ###   ########.fr       */
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
	tmp->next_jump = 0;
	tmp->carry = proc->carry;
	tmp->live = proc->live;
	tmp->next = core->process;
	core->process = tmp;
	return (true);
}
