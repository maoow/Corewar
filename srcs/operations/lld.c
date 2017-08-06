/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:08 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/26 14:32:45 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	lld(t_cor *core, t_process *proc)
{
	size_t value;
	size_t PC;

	PC = proc->PC;
	if (core->arena[proc->PC + proc->startpos + 1] / 16 ) % 4 == 2)
	{
		value = getram(core, PC + 2 + proc->startpos);
		PC += 6;
	}
	else
	{
		value = getram(core, proc->pc + proc->startpos + ind(core, proc, PC + 2)));
		PC += 4;
	}
	proc->registres[core->arena[PC]] = value;
	return (value != 0);
}
