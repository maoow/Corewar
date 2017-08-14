/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsmanage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:23:04 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/10 14:29:14 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

size_t	ind(t_cor *core, t_process *proc, size_t PC)
{
	size_t value;

	value = core->arena[proc->startpos + PC];
	value *= 256;
	value += core->arena[proc->startpos + PC + 1];
	return (value);
}

size_t	getparam(t_cor *core, t_process *proc, size_t param, size_t label)
{
	unsigned char	op;
	size_t			i;
	size_t			place;
	size_t			value;

	i = 0;
	place = 2;
	op = core->arena[proc->PC + proc->startpos + 1];
	while (i < param)
	{
		if (op % 4 == 1)
		{
			value = proc->registres[core->arena[proc->PC + proc->startpos + place]];
				place++;
		}
		else if (op % 4 == 2)
		{
			if (label == 2)
				value = getram(core, ind(core, proc, proc->PC + proc->startpos + place));
			place += label;
		}
		else
		{
			value = getram(core, ind(core, proc, proc->PC + proc->startpos + place));
			place += 2;
		}
		i++;
		op /= 4;
	}
	return (value);
}

size_t	getparamplace(t_cor *core, t_process *proc, size_t param, size_t label)
{
	unsigned char	op;
	size_t			i;
	size_t			place;

	i = 1;
	place = 2;
	op = core->arena[proc->PC + proc->startpos + 1];
	while (i < param)
	{
		if (op % 4 == 1)
				place++;
		else if (op % 4 == 2)
			place += label;
		else
			place += 2;
		i++;
		op /= 4;
	}
	return (place + proc->PC + proc->startpos);
}
