/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:06 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/26 14:32:45 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	lfork(t_cor *core, t_process *proc)
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
	tmp->PC = (proc->PC + ind(proc, proc->PC + 1)) % MEM_SIZE;
	tmp->startpos = core->startpos;
	tmp->next_jump = 0;
	tmp->cycles_before_execute = 0;
	tmp->next_jump = NULL;
	tmp->carry = core->carry;
	tmp->live = core->live;
	tmp->next = NULL; // todo (voir comment on gere la pile)
	return (true);
}
