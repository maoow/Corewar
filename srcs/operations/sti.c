/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 14:25:12 by cbinet            #+#    #+#             */
/*   Updated: 2017/10/10 15:24:19 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

bool	cw_sti(t_cor *core, t_process *proc)
{
	size_t		adress;
	size_t		adress2;
	size_t		total;
	size_t		decale;

	// + 4 et + 2 dans le cas sans reg
	// a faire : un truc generique
	//ft_printf("%x", proc->PC + proc->startpos);
	//exit(0);
	//adress = core->arena[proc->PC + 4 + proc->startpos];
	//adress2 = core->arena[proc->PC + 2 + proc->startpos];
	decale = 3;
	if ((core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE] / 16) % 4 > 1)
	{
		adress = ind(core, proc, proc->PC + 3);
		decale += 2;
	}
	else
	{
		adress = proc->registres[core->arena[proc->PC + 3 + proc->startpos] - 1];
	}
	if ((core->arena[(proc->PC + proc->startpos + 1) % MEM_SIZE] / 4) % 4 > 1)
		adress2 = ind(core, proc, proc->PC + decale);
	else
		adress2 = proc->registres[core->arena[(proc->PC + decale + proc->startpos) % MEM_SIZE ] - 1];
	total = adress + adress2;
	//a finir + 2 - 2 en verifiant sur d'autres sti
	setram(core, proc->PC + proc->startpos + total, proc->registres[core->arena[proc->PC + 2 + proc->startpos] - 1], proc->color);
	if (core->options->v4)
		ft_printf("P%5d | sti r%d %d %d\n       | -> store to %d + %d = %d (with pc and mod %d)\n",
				proc->ID,core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE],
				adress, adress2, adress, adress2, total, proc->PC + total + proc->startpos);
	return (true);
}

/*

TON STI ICI

bool	cw_sti(t_cor *core, t_process *proc)
{
	size_t		adress;
	size_t		adress2;

	adress = getparam(core, proc, 2, 2);
	adress2 = getparam(core, proc, 3, 2);
	adress += adress2;
	setram(core, adress, proc->registres[core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE] - 1], proc->color);
	if (core->options->v4)
		ft_printf("P%5d | sti r%d %d %d\n", proc->ID,core->arena[(proc->PC + proc->startpos + 2) % MEM_SIZE] - 1, adress - adress2, adress2);
	return (true);
}*/
