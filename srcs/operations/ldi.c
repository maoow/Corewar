/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:05 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/06 13:48:28 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_ldi(t_cor *core, t_process *proc)
{
	int adress;
	int adress2;

	adress = getparam(core, proc, 1, 2);
	if (adress > 201363497 / 2)
	adress -= 201363497;
	adress2 = getparam(core, proc, 2, 2);
	if (adress2 > 201363497 / 2)
	adress2 -= 201363497;
	proc->registres[core->arena[getparamplace(core, proc, 3, 2) % MEM_SIZE]] =
	getram(core, idx(proc, adress + adress2));
	if (core->options->v4)
		ft_printf("P%5d | ldi %d %d r%d\n       | -> load from %d + %d = %d (with pc and mod %d)\n",
			  	proc->ID, adress , adress2, core->arena[getparamplace(core, proc, 3, 2) % MEM_SIZE],
				adress , adress2, (adress + adress2),(adress + adress2 + proc->startpos  ) % MEM_SIZE);
//		exit(0);

	return (proc->registres[core->arena[(getparamplace(core, proc, 3, 2)) % MEM_SIZE]] != 0);
}
