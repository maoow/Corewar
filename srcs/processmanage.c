/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processmanage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:30:25 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/27 13:58:06 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

size_t			*ft_getparamstype(t_cor *core, t_process *proc)
{
	size_t		*params;
	size_t		i;
	size_t		tmp;

	if (!(params = (size_t *)malloc(g_oplabel[core->arena[proc->PC]] * sizeof(size_t))))
		exit(1);
	tmp = core->arena[proc->PC + 1];
	i = 0;
	while (tmp)
	{
		tmp /= 4;
		if (tmp % 4 == 1)
			params[i] = 1;
		else if (tmp % 4 == 3)
			params[i] = 2;
		else if (tmp % 4 == 2)
			params[i] = g_oplabel[core->arena[proc->PC]];
		i++;
	}
	return (params);
}

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
