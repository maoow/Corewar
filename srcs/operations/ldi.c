/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:05 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/18 17:49:10 by starrit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_ldi(t_cor *core, t_process *proc)
{
	int adress;
	int adress2;

	adress = getparam(core, proc, 1, 2);
	if (adress > 65536 / 2)
		adress -= 65536;
	adress2 = getparam(core, proc, 2, 2);
	if (adress2 > 65536 / 2)
		adress2 -= 65536;
	proc->registres[mod(core->arena[(getparamplace(core, proc, 3, 2) - 1)
			% MEM_SIZE] - 1, 16)] =
		getram(core, (adress + adress2 + proc->startpos + proc->PC) % MEM_SIZE);
	if (core->options->v4)
	{
		ft_printf("P%5d | ldi %d %d r%d\n", proc->ID, adress, adress2,
				core->arena[(getparamplace(core, proc, 3, 2) - 1) % MEM_SIZE]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
				adress, adress2, (adress + adress2),
				(adress + adress2 + proc->PC + proc->startpos) % MEM_SIZE);
	}
	return (proc->registres[mod(core->arena[(getparamplace(core, proc, 3, 2))
				% MEM_SIZE] - 1, 16)] != 0);
}
