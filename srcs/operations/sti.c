/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:12 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/19 16:12:42 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_sti(t_cor *core, t_process *proc)
{
	size_t		adress;
	size_t		adress2;
	size_t		total;
	size_t		reg;

	reg = mod(core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE] - 1, 16);
	adress = getparam(core, proc, 2, 2);
	if (adress > 34952)
		adress -= 65536;
	adress2 = getparam(core, proc, 3, 2);
	total = adress2 + adress;
	setram(core, proc->PC + proc->startpos + total, proc->registres[reg],
			proc->color);
	if (core->options->v4)
	{
		ft_printf("P%5d | sti r%d %d %d\n       | -> store to %d + %d = %d \
(with pc and mod %d)\n",
				proc->ID, reg + 1, adress, adress2, adress, adress2, total,
				((proc->PC + proc->startpos) % MEM_SIZE) + total);
	}
	return (true);
}
