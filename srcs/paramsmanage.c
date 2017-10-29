/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsmanage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:23:04 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/21 11:18:08 by cbinet           ###   ########.fr       */
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

size_t	indx(t_cor *core, t_process *proc, size_t PC)
{
	size_t value;
	PC = ((PC - proc->PC) % IDX_MOD) + proc->PC;
	value = core->arena[(proc->startpos + PC) % MEM_SIZE];
	value *= 256;
	value += core->arena[(proc->startpos + PC + 1) % MEM_SIZE];
	return (value);
}
size_t	ind(t_cor *core, t_process *proc, size_t PC)
{
	size_t value;

	value = core->arena[(proc->startpos + PC) % MEM_SIZE];
	value *= 256;
	value += core->arena[(proc->startpos + PC + 1) % MEM_SIZE];
	return (value);
}

size_t	getparam(t_cor *core, t_process *proc, size_t param, size_t label)
{
	size_t			op[3];
	size_t			i;
	size_t			place;
	int				value;

	i = 0;
	place = 2;
	op[0] = core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE];
	op[2] = (op[0] / 4) % 4;
	op[1] = (op[0] / 16) % 4;
	op[0] /= 64;
	//ft_printf("%d %d %d \n", op[0], op[1], op[2]);
	while (i < param)
	{
		if (op[i] == 1)
		{
			value = proc->registres[mod(core->arena[(proc->PC + proc->startpos + place ) % MEM_SIZE] - 1, 16)];
				place++;
		}
		else if (op[i] == 2)
		{
			if (label == 2)
				value = ind(core, proc, proc->PC + place );
			else
				value = getram(core, proc->PC + place + proc->startpos);
			place += label;
		}
		else
		{
			value = getram(core, ind(core, proc, proc->PC + proc->startpos + place));
			place += 2;
		}
		i++;
	}
	return ((size_t)(value % 4294967295));
}

size_t	getparamplace(t_cor *core, t_process *proc, size_t param, size_t label)
{
	size_t		op[3];
	size_t			i;
	size_t			place;

	i = 0;
	place = 2;
	op[0] = core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE];
	op[2] = (op[0] / 4) % 4;
	op[1] = (op[0] / 16) % 4;
	op[0] /= 64;
	while (i < param)
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
