/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processmanage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:30:25 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/21 14:16:25 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool					(*g_opctable[OPC_NBR])(t_cor *, t_process *) = {
	&cw_live,
	&cw_ld,
	&cw_st,
	&cw_add,
	&cw_sub,
	&cw_and,
	&cw_or,
	&cw_xor,
	&cw_zjmp,
	&cw_ldi,
	&cw_sti,
	&cw_fork,
	&cw_lld,
	&cw_lldi,
	&cw_lfork,
	&cw_aff
};

size_t					revgetop(bool (*op)())
{
	size_t	i;

	i = 0;
	while (op != g_opctable[i] && i < OPC_NUMBER)
	{
		i++;
	}
	if (i >= OPC_NUMBER)
		return (0);
	return (i + 1);
}

bool					g_opcarry[OPC_NBR] = {
	false,
	true,
	false,
	true,
	true,
	true,
	true,
	true,
	false,
	false,
	false,
	false,
	true,
	true,
	false,
	false,
};

size_t					g_optime[OPC_NBR] = {
	10,
	5,
	5,
	10,
	10,
	6,
	6,
	6,
	20,
	25,
	25,
	800,
	10,
	50,
	1000,
	2
};
static void		ft_executeprocess(t_cor *core, t_process *proc)
{
	bool	carry;
	int		op;

	op = core->arena[(proc->startpos + proc->PC) % MEM_SIZE];
	ft_determinejmpdist(core, proc);
	if (ft_checkexecutable(core, proc))
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
	if (ft_checkloadable(core, proc))
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
