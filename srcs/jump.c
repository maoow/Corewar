/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:06:40 by cbinet            #+#    #+#             */
/*   Updated: 2017/07/27 12:23:56 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_determinejmpdist(t_cor *core, t_process *proc)
{
	unsigned char	tmp;

	tmp = core->arena[proc->PC + 1];
	if (g_opc[core->arena[proc->PC]])
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
				proc->next_jump += g_oplabel[core->arena[proc->PC]];
		}
	}
	else
		proc->next_jump = 1 + g_oplabel[core->arena[proc->PC]];
}
