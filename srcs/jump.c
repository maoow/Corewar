/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:06:40 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/22 13:46:09 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

size_t					g_oplabel[OPC_NBR] = {
	4,
	4,
	0,
	0,
	0,
	4,
	4,
	4,
	2,
	2,
	2,
	2,
	4,
	2,
	2,
	0
};

size_t	idx(t_process *proc, size_t jump)
{
	int	tmp;

	if (jump > MEM_SIZE / 2 && jump % IDX_MOD != 0)
		tmp = (jump % IDX_MOD) + proc->PC - IDX_MOD;
	else
		tmp = (jump % IDX_MOD) + proc->PC;
	return ((size_t)((tmp + proc->startpos) % MEM_SIZE));
}

void	dispjump(t_cor *core, t_process *proc)
{
	size_t		i;
	size_t		start;

	if (proc->next_jump > 0)
	{
	start = mod(proc->startpos + proc->PC, MEM_SIZE);
	i = 0;
	if (start > 0)
		ft_printf("ADV %d (%06#x -> %#06x)", proc->next_jump, start, start + proc->next_jump);
	else
		ft_printf("ADV %d (0x0000 -> %#06x)", proc->next_jump, proc->startpos + proc->PC + proc->next_jump);
	if (proc->next_jump < 1000)
		while (i < proc->next_jump)
		{
			ft_printf(" %02x", core->arena[mod(proc->startpos + proc->PC + i, MEM_SIZE)]);
			i++;
		}
	ft_printf(" \n");
	}
}

void	ft_determinejmpdist(t_cor *core, t_process *proc)
{
	unsigned char	tmp;

	tmp = core->arena[(proc->startpos + proc->PC + 1) % MEM_SIZE];
	if (core->arena[(proc->startpos + proc->PC) % MEM_SIZE] != 9 && core->arena[(proc->startpos + proc->PC) % MEM_SIZE] < 17 && core->arena[(proc->startpos + proc->PC) % MEM_SIZE] > 0)
	{
		if (hasopcode(core->arena[(proc->startpos + proc->PC) % MEM_SIZE]))
		{
			proc->next_jump = 2;
			while (tmp)
			{
				tmp /= 4;
				if (tmp % 4 == 1)
					proc->next_jump += 1;
				else if (tmp % 4 == 3)
					proc->next_jump += 2;
				else if (tmp % 4 == 2)
					proc->next_jump += g_oplabel[core->arena[(proc->startpos + proc->PC) % MEM_SIZE] - 1];
			}
		}
		else
			proc->next_jump = 1 + g_oplabel[core->arena[(proc->startpos + proc->PC) % MEM_SIZE] - 1];
		if (core->arena[(proc->startpos + proc->PC) % MEM_SIZE] == 2 && proc->next_jump >= 8)
			proc->next_jump = 6;
	}
	else
		proc->next_jump = 0;
}
