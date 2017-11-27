/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsmanage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:23:04 by cbinet            #+#    #+#             */
/*   Updated: 2017/11/27 12:16:43 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

size_t	get_paramnb(size_t opc)
{
	size_t params;

	params = 0;
	while (opc)
	{
		opc /= 4;
		if (opc % 4 != 0)
			params++;
	}
	return (params);
}

size_t	indx(t_cor *core, t_process *proc, size_t pc)
{
	size_t value;

	pc = ((pc - proc->PC) % IDX_MOD) + proc->PC;
	value = core->arena[(proc->startpos + pc) % MEM_SIZE];
	value *= 256;
	value += core->arena[(proc->startpos + pc + 1) % MEM_SIZE];
	return (value);
}

size_t	ind(t_cor *core, t_process *proc, size_t pc)
{
	size_t value;

	value = core->arena[(proc->startpos + pc) % MEM_SIZE];
	value *= 256;
	value += core->arena[(proc->startpos + pc + 1) % MEM_SIZE];
	if (value > 65536 / 2)
		value -= 65536;
	return (value);
}

int	getparam(t_cor *core, t_process *proc, size_t param, size_t label)
{
	size_t			op[3];
	size_t			place;
	long int		value;

	op[0] = core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE];
	op[2] = (op[0] / 4) % 4;
	op[1] = (op[0] / 16) % 4;
	op[0] /= 64;
	place = getparamplace(core, proc, param, label);
	if (op[param - 1] == 1)
	{
		value = proc->registres[mod(core->arena[place] - 1, 16)];
		if (core->arena[place] <= 0 || core->arena[place] > 16)
		core->error = true;
	}
	else if (op[param - 1] == 2)
	{
		if (label == 2)
		{
			value = ind(core, proc, place - proc->startpos);
		}
		else
			value = getram(core, place);
	}
	else
		value = getram(core, ind(core, proc, place));
	return ((value % 4294967296));
}

size_t	getparamplace(t_cor *core, t_process *proc, size_t param, size_t label)
{
	size_t			op[3];
	size_t			i;
	size_t			place;

	i = 0;
	place = 2;
	op[0] = core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE];
	op[2] = (op[0] / 4) % 4;
	op[1] = (op[0] / 16) % 4;
	op[0] /= 64;
	while (i < param - 1)
	{
		if (op[i] == 1)
			place++;
		else if (op[i] == 2)
			place += label;
		else
			place += 2;
		i++;
	}
	return ((place + proc->PC + proc->startpos) % MEM_SIZE);
}
