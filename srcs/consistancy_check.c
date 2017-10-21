/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consistancy_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 11:00:05 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/21 13:16:57 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

size_t					g_opparamnb[OPC_NUMBER] = {
	1,
	2,
	2,
	3,
	3,
	3,
	3,
	3,
	1,
	3,
	3,
	1,
	2,
	3,
	1,
	1
};

bool					g_ocp[OPC_NUMBER] = {
	false,
	true,
	true,
	true,
	true,
	true,
	true,
	true,
	false,
	true,
	true,
	false,
	true,
	true,
	false,
	true
};

bool			hasopcode(size_t op)
{
	return (g_ocp[op - 1]);
}
/*
** check if operation is executable
*/
static bool		checkopn(t_cor *core, t_process *proc)
{
	size_t op;

	op = core->arena[(proc->PC + proc->startpos) % MEM_SIZE];
	if (op == 0 || op > OPC_NUMBER)
		return (false);
	return (true);
}
bool			ft_checkexecutable(t_cor *core, t_process *proc)
{
	size_t op;
	size_t opc;

	op = core->arena[(proc->startpos + proc->PC) % MEM_SIZE];
	if (op > 1 && op < OPC_NUMBER && g_ocp[op - 1])
	{

		opc = core->arena[(proc->startpos + proc->PC + 1) % MEM_SIZE];
		if (get_paramnb(opc) != g_opparamnb[op - 1])
		{
			if (proc->next_op)
			{
				proc->next_op = NULL;
				proc->next_jump = 2;
				if (core->options->v16)
					dispjump(core, proc);
			}
			return (false);
		}
	}
	if (core->options->v16 && proc->next_op)
		dispjump(core, proc);
	return (true);
}

bool			ft_checkloadable(t_cor *core, t_process *proc)
{
	size_t opc;
	size_t op;

	op = core->arena[(proc->PC + proc->startpos) % MEM_SIZE];
	opc = core->arena[(1 + proc->PC + proc->startpos) % MEM_SIZE];
	if (!checkopn(core, proc))
		return (false);
	if (hasopcode(op) && !(op == 2 || op == 4 || op == 5))
	{
		if (get_paramnb(opc) != g_opparamnb[op - 1])
			return (false);
	}
		return (true);
}
