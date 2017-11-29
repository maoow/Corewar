/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:06 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/28 12:53:54 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

/*
** LFORK
**
** make a perfect copy of the proc and place it on the given adress
*/

static void			fulfill_tmp(t_cor *core, t_process *tmp, t_process *proc)
{
	tmp->next_jump = 0;
	tmp->buffc = 0;
	tmp->next_op = NULL;
	tmp->just_played = false;
	tmp->searching = false;
	tmp->carry = proc->carry;
	tmp->live = proc->live;
	tmp->color = proc->color;
	tmp->id = core->procnb + 1;
	core->procnb++;
	tmp->next = core->process;
	core->process = tmp;
}

bool				cw_lfork(t_cor *core, t_process *proc)
{
	t_process	*tmp;
	size_t		i;
	int			indt;

	i = 0;
	if (!(tmp = (t_process *)malloc(sizeof(t_process))))
		write_error(2);
	while (i < REG_NUMBER)
	{
		tmp->registres[i] = proc->registres[i];
		i++;
	}
	indt = ind(core, proc, proc->pc + 1);
	tmp->pc = 0;
	tmp->startpos = ((proc->pc + proc->startpos) % MEM_SIZE + indt);
	fulfill_tmp(core, tmp, proc);
	if (core->options->v4)
		ft_printf("P %4d | lfork %d (%d)\n", proc->id, indt, tmp->startpos);
	tmp->startpos %= MEM_SIZE;
	return (true);
}
