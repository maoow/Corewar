/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processmanage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:30:25 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/20 16:50:16 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "opg.c"

size_t			*ft_getparamstype(t_cor *core, t_process *proc)
{
	size_t		*params;
	size_t		i;
	size_t		tmp;

	if (!(params =
				(size_t *)malloc(g_oplabel[core->arena[(proc->startpos +
						proc->PC) % MEM_SIZE] - 1] * sizeof(size_t))))
		exit(1);
	tmp = core->arena[(proc->startpos + proc->PC + 1) % MEM_SIZE];
	i = 0;
	while (tmp)
	{
		tmp /= 4;
		if (tmp % 4 == 1)
			params[i] = 1;
		else if (tmp % 4 == 3)
			params[i] = 2;
		else if (tmp % 4 == 2)
			params[i] = g_oplabel[core->arena[(proc->startpos + proc->PC) %
				MEM_SIZE] - 1];
		i++;
	}
	return (params);
}
static bool		ft_checkconsistancy(t_cor *core, t_process *proc)
{
	size_t op;
	size_t opc;
	size_t params;

	params = 0;
	op = core->arena[(proc->startpos + proc->PC) % MEM_SIZE];
	if (op > 1 && op < OPC_NUMBER && g_ocp[op - 1])
	{

		opc = core->arena[(proc->startpos + proc->PC + 1) % MEM_SIZE];
		while (opc)
		{
			opc /= 4;
			if (opc % 4 != 0)
				params++;
		}
		if (params != g_opparamnb[op - 1])
		{
			proc->next_op = NULL;
			proc->next_jump = 2;
			if (core->options->v16)
				dispjump(core, proc);
			return (false);
		}
	}
	if (core->options->v16)
		dispjump(core, proc);
	return (true);
}

static void		ft_executeprocess(t_cor *core, t_process *proc)
{
	bool	carry;
	int		op;

	op = core->arena[(proc->startpos + proc->PC) % MEM_SIZE];
	ft_determinejmpdist(core, proc);
	if (ft_checkconsistancy(core, proc))
	{
		carry = proc->next_op(core, proc);
		if (core->options->reg)
			dispreg(proc);
		if (op > 0 && op < 17 && g_opcarry[op - 1])
			proc->carry = carry;
	}
	proc->PC += proc->next_jump;
	proc->next_op = NULL;
}

// compare core->arena[proc->PC] with opc_table
void			ft_getop(t_cor *core, t_process *proc)
{
	if (core->arena[(proc->startpos + proc->PC) % MEM_SIZE] - 1 >= 0 &&
			core->arena[(proc->startpos + proc->PC) % MEM_SIZE] - 1 < OPC_NBR)
	{
		proc->next_op =
			g_opctable[core->arena[(proc->startpos + proc->PC) % MEM_SIZE] - 1];
		proc->cycles_before_execute =
			g_optime[core->arena[(proc->startpos + proc->PC) % MEM_SIZE] - 1];
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
		if (proc->cycles_before_execute > 0)
			proc->cycles_before_execute--;
		proc = proc->next;
	}
}

void			ft_delprocess(t_cor *core, t_process **del)
{
	t_process *tmp;

	if (core->process == (*del))
	{
		core->process = (*del)->next;
	}
	else
	{
		tmp = core->process;
		while (tmp->next != (*del))
			tmp = tmp->next;
		tmp->next = (*del)->next;
	}
	free((*del));
	*del = NULL;
}
