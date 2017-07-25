/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processmanage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 13:30:25 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/25 14:00:00 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
static void		ft_executeprocess(t_cor *core, t_process *proc)
{
	// TO DO
}

static void		ft_getop(t_cor *core, t_process *proc)
{
	// compare core->arena[proc->PC] with opc_table

}

void			ft_browseprocess(t_cor *core)
{
	t_process	*proc;

	proc = core->process;
	while (proc)
	{
		if (proc->cycles_before_execute == 0 && next_op)
			ft_executeprocess(core, proc);
		if (!next_op)
			ft_getop(core, proc);
		proc->cycles_before_execute--;
		proc = proc->next;
	}
}
