/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processmanage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:30:25 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/27 11:32:07 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
static void		ft_executeprocess(t_cor *core, t_process *proc)
{
	bool	(*op);
	bool	carry;
	carry = proc->next_op(core, proc);
	if (g_opcarry[core->arena[proc->PC] - 1])
		proc->carry = carry;
	ft_determinejmpdist(core, proc);
	proc->PC += proc->next_jump % MEM_SIZE;
	free_op(proc);
}

// compare core->arena[proc->PC] with opc_table
static void		ft_getop(t_cor *core, t_process *proc)
{

	if (core->arena[proc->PC] - 1 < OPC_NBR)
	{
		proc->next_op = g_opctable[core->arena[proc->PC] - 1];
		proc->cycle_before_execute = g_optime[core->arena[proc->PC] - 1];
	}
	else
		proc->PC++;
}

void			ft_browseprocess(t_cor *core)
{
	t_process	*proc;

	proc = core->process;
	while (proc)
	{
		if (proc->cycles_before_execute == 0 && proc->next_op)
			ft_executeprocess(core, proc);
		if (!proc->next_op)
			ft_getop(core, proc);
		proc->cycles_before_execute--;
		proc = proc->next;
	}
}
