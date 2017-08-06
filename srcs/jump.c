/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:06:40 by cbinet            #+#    #+#             */
/*   Updated: 2017/08/04 14:09:59 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

size_t	idx(t_process *proc, size_t jump)
{
	int	tmp;

	tmp = proc->PC + jump;
	tmp %= MEM_SIZE;
	tmp -= proc->PC;
	if (tmp >= 0)
		tmp %= IDX_MOD;
	else
		tmp = (tmp % IDX_MOD) - IDX_MOD;
	return ((size_t)(tmp + proc->startpos));
}

void	ft_determinejmpdist(t_cor *core, t_process *proc)
{
	unsigned char	tmp;

	tmp = core->arena[proc->startpos + proc->PC + 1];
	if (g_opc[core->arena[proc->startpos + proc->PC]])
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
				proc->next_jump += g_oplabel[core->arena[proc->startpos + proc->PC]];
		}
	}
	else
		proc->next_jump = 1 + g_oplabel[core->arena[proc->startpos + proc->PC]];
}
