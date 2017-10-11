/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:06 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/11 16:49:12 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_lfork(t_cor *core, t_process *proc)
{
	t_process	*tmp;
	size_t		i;

	i = 0;
	if (!(tmp = (t_process *)malloc(sizeof(t_process))))
		write_error(2);
	while (i < REG_NUMBER)
	{
		tmp->registres[i] = proc->registres[i];
		i++;
	}
	tmp->PC = (proc->PC + ind(core, proc, proc->PC + 1)) % MEM_SIZE;
	tmp->startpos = proc->startpos;
	tmp->next_jump = 0;
	tmp->cycles_before_execute = 0;
	tmp->next_jump = 0;
	tmp->carry = proc->carry;
	tmp->live = proc->live;
	tmp->next = core->process;
	core->process = tmp;
	if (core->options->v4)
		ft_printf("P%5d | lfork %d\n", proc->ID, ind(core, proc, proc->PC + 1));
	return (true);
}
